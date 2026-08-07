import sys
import subprocess
import random

# AHC061 Local Tester
# Simulates the game environment locally.

class InputReader:
    def __init__(self, content):
        self.tokens = content.split()
        self.ptr = 0
    
    def next(self):
        if self.ptr < len(self.tokens):
            token = self.tokens[self.ptr]
            self.ptr += 1
            return token
        return None

    def read_int(self):
        val = self.next()
        if val is None: return None
        return int(val)

    def read_float(self):
        val = self.next()
        if val is None: return None
        return float(val)

def main():
    if len(sys.argv) < 3:
        print("Usage: python3 local_tester.py <in.txt> <command e.g. ./061copy>")
        sys.exit(1)
        
    in_file = sys.argv[1]
    command = sys.argv[2] # Can be "./061copy" or "python3 main.py"
    
    try:
        with open(in_file, 'r') as f:
            content = f.read()
    except FileNotFoundError:
        print(f"Error: Input file '{in_file}' not found.")
        sys.exit(1)
    
    reader = InputReader(content)
    
    # --- 1. Read Input ---
    N = reader.read_int()
    M = reader.read_int()
    T = reader.read_int()
    U = reader.read_int()
    
    if N is None:
        print("Error: Invalid input file format (empty?).")
        sys.exit(1)

    V = [[0]*N for _ in range(N)]
    for r in range(N):
        for c in range(N):
            V[r][c] = reader.read_int()
            
    P = []
    for _ in range(M):
        r = reader.read_int()
        c = reader.read_int()
        P.append((r, c)) # (row, col)

    # Read AI Parameters (M-1 lines expected)
    ai_params = []
    
    # Check if we have enough tokens for AI params
    # M-1 lines * 5 floats = (M-1)*5 tokens
    # If not enough, generate random defaults
    use_random_ai = False
    if reader.ptr + (M - 1) * 5 > len(reader.tokens):
        use_random_ai = True
        # print("Note: Input file exhausted. Generating random AI parameters.")

    for _ in range(M - 1):
        params = []
        if use_random_ai:
            # wa, wb, wc, wd from 0.3 to 1.0
            params.append(random.uniform(0.3, 1.0))
            params.append(random.uniform(0.3, 1.0))
            params.append(random.uniform(0.3, 1.0))
            params.append(random.uniform(0.3, 1.0))
            # epsilon from 0.1 to 0.5
            params.append(random.uniform(0.1, 0.5))
        else:
            for _ in range(5): 
                val = reader.read_float()
                if val is not None:
                    params.append(val)
                else:
                    params.append(0.0)
        ai_params.append(params)

    # Read Random Seeds
    # r[i][2*tt] is r1, r[i][2*tt+1] is r2
    # Input order in lib.rs:
    # for tt in 0..T:
    #   for i in 0..(M-1):
    #     read r1, r2
    
    ai_randoms = [[(0.0, 0.0) for _ in range(T)] for _ in range(M-1)]
    
    # Try to read seeds if available
    if reader.ptr < len(reader.tokens):
        for t in range(T):
            for i in range(M - 1):
                r1 = reader.read_float()
                r2 = reader.read_float()
                if r1 is not None and r2 is not None:
                    ai_randoms[i][t] = (r1, r2) 

    # --- 2. Initialize Game State ---
    owner = [[-1]*N for _ in range(N)]
    level = [[0]*N for _ in range(N)]
    
    for i in range(M):
        pr, pc = P[i]
        owner[pr][pc] = i
        level[pr][pc] = 1

    # --- 3. Launch User Solution ---
    try:
        proc = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True, shell=True)
    except Exception as e:
        print(f"Error starting subprocess: {e}")
        sys.exit(1)

    # Send Initial Input to User
    # Format matches 061copy.cpp reading:
    # N M T U
    # V (NxN)
    # P (M pairs)
    input_str_parts = [f"{N} {M} {T} {U}"]
    for r in range(N):
        input_str_parts.append(" ".join(map(str, V[r])))
    
    points_str = []
    for r, c in P:
        points_str.append(f"{r} {c}")
    input_str_parts.append("\n".join(points_str)) 
    
    input_str = "\n".join(input_str_parts) + "\n"

    try:
        proc.stdin.write(input_str)
        proc.stdin.flush()
    except BrokenPipeError:
        print("Error: User subprocess exited immediately after start.")
        return

    # --- 4. Game Loop ---
    user_move_history = []
    
    # Order matched with lib.rs: Right, Down, Left, Up
    # (0, 1), (1, 0), (0, -1), (-1, 0)
    dr = [0, 1, 0, -1]
    dc = [1, 0, -1, 0]

    for t in range(T):
        # A. Get User Move
        line = proc.stdout.readline()
        if not line:
            # Maybe process finished or crashed
            break
        
        try:
            parts = list(map(int, line.split()))
            if len(parts) < 2:
                # Should handle error gracefully
                user_move = P[0]
            else:
                user_move = (parts[0], parts[1])
        except ValueError:
            user_move = P[0]
            
        user_move_history.append(user_move)
        # Output user move to stdout for tracking
        print(f"Turn {t + 1}: User moved to {user_move}")

        # B. Calculate AI Moves
        current_moves = [user_move]
        
        for i in range(1, M):
            # AI Logic using BFS logic from lib.rs
            # get_candidates implementation
            
            candidates = []
            visited_bfs = [[False]*N for _ in range(N)]
            bfs_q = [P[i]]
            visited_bfs[P[i][0]][P[i][1]] = True
            
            idx = 0
            while idx < len(bfs_q):
                cx, cy = bfs_q[idx]; idx += 1
                
                # Check occupancy (logic from lib.rs: if ok { push })
                # But note: visited check prevents duplicates in candidates?
                # lib.rs logic:
                # 1. Pop (x, y).
                # 2. Check if occupied by OTHER.
                # 3. If NOT occupied, add to reachable (candidates).
                
                is_occupied_by_other = False
                for pid in range(M):
                    if pid != i and P[pid] == (cx, cy):
                        is_occupied_by_other = True
                        break
                
                if not is_occupied_by_other:
                    candidates.append((cx, cy))
                
                # Expand neighbors if OWN territory
                if owner[cx][cy] == i:
                    for d in range(4):
                        nr, nc = cx + dr[d], cy + dc[d]
                        if 0 <= nr < N and 0 <= nc < N:
                            if not visited_bfs[nr][nc]:
                                visited_bfs[nr][nc] = True
                                bfs_q.append((nr, nc))
            
            valid_candidates = candidates
            
            if not valid_candidates:
                current_moves.append(P[i])
                continue
            
            # Select Move based on Params
            p_params = ai_params[i-1] 
            while len(p_params) < 5: p_params.append(0.5)
            wa, wb, wc, wd, epsilon = p_params[0], p_params[1], p_params[2], p_params[3], p_params[4]
            
            # Use Random Seeds
            r1, r2 = ai_randoms[i-1][t]
            
            chosen = P[i] # Default
            
            if r1 < epsilon:
                # floor(r2 * len)
                idx = int(r2 * len(valid_candidates))
                idx = min(idx, len(valid_candidates) - 1)
                chosen = valid_candidates[idx]
            else:
                scores = []
                max_score = -float('inf')
                
                for idx, (cr, cc) in enumerate(valid_candidates):
                    val = 0.0
                    cell_owner = owner[cr][cc]
                    cell_level = level[cr][cc]
                    cell_v = V[cr][cc]
                    
                    if cell_owner == -1: val = cell_v * wa
                    elif cell_owner == i:
                        val = (cell_v * wb) if cell_level < U else 0.0
                    else:
                        val = (cell_v * wc) if cell_level == 1 else (cell_v * wd)
                    
                    scores.append(val)
                    if val > max_score:
                        max_score = val
                
                # Tolerance check
                tolerance = 1e-9 * max(abs(max_score), 1.0)
                best_indices = []
                for idx, sc in enumerate(scores):
                    if sc >= max_score - tolerance:
                        best_indices.append(idx)
                
                if best_indices:
                    idx_in_best = int(r2 * len(best_indices))
                    idx_in_best = min(idx_in_best, len(best_indices) - 1)
                    chosen = valid_candidates[best_indices[idx_in_best]]
                else:
                    chosen = P[i]
            
            current_moves.append(chosen)

        # C. Resolve Moves
        target_map = {}
        for pid, (mr, mc) in enumerate(current_moves):
            if (mr, mc) not in target_map: target_map[(mr, mc)] = []
            target_map[(mr, mc)].append(pid)
        
        next_P = list(P)
        
        for (tr, tc), pids in target_map.items():
            if len(pids) > 1:
                # Collision: All bounce
                for pid in pids:
                    next_P[pid] = P[pid]
            else:
                # Unique target
                next_P[pids[0]] = (tr, tc)
        
        P = next_P
        
        # Update Territory
        for i in range(M):
            pr, pc = P[i]
            if owner[pr][pc] == i:
                if level[pr][pc] < U:
                    level[pr][pc] += 1
            elif owner[pr][pc] == -1:
                owner[pr][pc] = i
                level[pr][pc] = 1
            else: # Enemy
                level[pr][pc] -= 1
                if level[pr][pc] == 0:
                    owner[pr][pc] = i # Capture
                    level[pr][pc] = 1

        # D. Update User
        if t < T - 1:
            # Format:
            # tP (User code expects vector<pair<int,int>>). We send current_moves (intentions).
            # P (User code expects vector<pair<int,int>>). We send P (final positions).
            # owner
            # level
            
            msg_lines = []
            # tP
            for mr, mc in current_moves:
                msg_lines.append(f"{mr} {mc}")
            # P
            for pr, pc in P:
                msg_lines.append(f"{pr} {pc}")
            # Owner
            for r in range(N):
                msg_lines.append(" ".join(map(str, owner[r])))
            # Level
            for r in range(N):
                msg_lines.append(" ".join(map(str, level[r])))
            
            msg = "\n".join(msg_lines) + "\n"
            
            try:
                proc.stdin.write(msg)
                proc.stdin.flush()
            except BrokenPipeError:
                break

    # --- 5. Output Results ---
    scores = [0]*M
    for r in range(N):
        for c in range(N):
            if owner[r][c] != -1:
                # Score = Sum(V * Level)
                scores[owner[r][c]] += V[r][c] * level[r][c]
    
    print("-" * 20)
    print(f"Final Score (User): {scores[0]}")
    for i in range(1, M):
        print(f"Player {i}: {scores[i]}")
    print("-" * 20)
    print("User Moves:")
    for i, m in enumerate(user_move_history):
        print(f"{m[0]} {m[1]}")
    
    try:
        proc.terminate()
    except:
        pass

if __name__ == "__main__":
    main()

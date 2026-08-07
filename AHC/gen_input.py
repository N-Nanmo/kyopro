import random

def main():
    N = 10
    M = 4
    T = 100
    U = 3
    
    print(f"{N} {M} {T} {U}")
    
    # V
    for r in range(N):
        row = [str(random.randint(1, 9)) for _ in range(N)]
        print(" ".join(row))
    
    # P
    positions = set()
    while len(positions) < M:
        r = random.randint(0, N-1)
        c = random.randint(0, N-1)
        positions.add((r, c))
    
    for r, c in positions:
        print(f"{r} {c}")
    
    # AI Params (M-1 lines of 5 floats)
    for _ in range(M - 1):
        params = [f"{random.uniform(0.0, 1.0):.10f}" for _ in range(5)]
        print(" ".join(params))
        
    # Random seeds (T*(M-1) lines of 2 floats)
    for _ in range(T * (M - 1)):
        seeds = [f"{random.uniform(0.0, 1.0):.10f}" for _ in range(2)]
        print(" ".join(seeds))

if __name__ == "__main__":
    main()

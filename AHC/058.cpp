#include <bits/stdc++.h>
#include <atcoder/all>
#pragma GCC optimize("O3")
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
#define cYes cout << "YES\n"
#define cNo cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"

// 時間計測
chrono::high_resolution_clock::time_point startTime;
double getElapsed() {
    return chrono::duration<double>(chrono::high_resolution_clock::now() - startTime).count();
}

// 乱数生成
mt19937_64 rng(42);
double randDouble() {
    return uniform_real_distribution<double>(0.0, 1.0)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    startTime = chrono::high_resolution_clock::now();

    ll N, L, T, K;
    cin >> N >> L >> T >> K;
    vll A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    // C[level][id], B[level][id], P[level][id]
    vvll C(L, vll(N));
    for (ll lv = 0; lv < L; lv++) {
        for (ll id = 0; id < N; id++) {
            cin >> C[lv][id];
        }
    }
    vvll Binit(L, vll(N, 1));
    vvll Pinit(L, vll(N, 0));
    
    // シミュレーション関数: スキップリストとランダム購入リストを受け取り、最終りんご数を返す
    // randomHighLevel[turn] = true なら高レベルからランダム購入
    auto simulate = [&](const vector<bool>& skipList, const vector<bool>& randomHighLevel) -> pair<ull, vector<pair<int, int>>> {
        vvll B(Binit);
        vvll P(Pinit);
        ull apples = K;
        vector<pair<int, int>> purchases(T);
        
        for (int turn = 0; turn < T; turn++) {
            int bestLv = -1, bestId = -1;
            
            // スキップでない場合のみ購入
            if (!skipList[turn]) {
                // ランダム高レベル購入モード
                if (randomHighLevel[turn]) {
                    // 高レベルから順に購入可能なものを探す
                    vector<pair<int, int>> candidates;
                    for (int lv = L - 1; lv >= 0; lv--) {
                        for (int id = 0; id < N; id++) {
                            ull cost = (ull)C[lv][id] * (P[lv][id] + 1);
                            if (apples >= cost) {
                                candidates.push_back({lv, id});
                            }
                        }
                        // このレベルに候補があればそこから選ぶ
                        if (!candidates.empty()) break;
                    }
                    if (!candidates.empty()) {
                        int idx = rng() % candidates.size();
                        bestLv = candidates[idx].first;
                        bestId = candidates[idx].second;
                    }
                } else {
                    // 通常のスコアベース購入
                    double bestScore = -1e18;
                    bool foundP0 = false;
                    const int remainingTurns = T - turn;
                    const double t = remainingTurns;
                    
                    // 時間係数のプリコンピュート (lv=0,1,2,...L-1)
                    double timeFactors[8];  // Lは最大8程度と仮定
                    timeFactors[0] = t;
                    for (int lv = 1; lv < L; lv++) {
                        timeFactors[lv] = timeFactors[lv-1] * t / (lv + 1);
                    }

                    // P=0優先
                    for (int lv = 0; lv < L; lv++) {
                        const double timeFactor = timeFactors[lv];
                        for (int id = 0; id < N; id++) {
                            if (P[lv][id] != 0) continue;
                            const ull cost = C[lv][id];
                            if (apples < cost) continue;
                            
                            double baseProduction = A[id];
                            for (int k = 0; k < lv; k++) {
                                baseProduction *= B[k][id] * max(1LL, P[k][id]);
                            }
                            double score = baseProduction * B[lv][id] * timeFactor / cost;
                            
                            if (score > bestScore) {
                                bestScore = score;
                                bestLv = lv;
                                bestId = id;
                                foundP0 = true;
                            }
                        }
                    }

                    if (!foundP0) {
                        for (int lv = 0; lv < L; lv++) {
                            const double timeFactor = timeFactors[lv];
                            for (int id = 0; id < N; id++) {
                                const ull cost = (ull)C[lv][id] * (P[lv][id] + 1);
                                if (apples < cost) continue;
                                
                                double baseProduction = A[id];
                                for (int k = 0; k < lv; k++) {
                                    baseProduction *= B[k][id] * max(1LL, P[k][id]);
                                }
                                double score = baseProduction * B[lv][id] * timeFactor / cost;
                                
                                if (score > bestScore) {
                                    bestScore = score;
                                    bestLv = lv;
                                    bestId = id;
                                }
                            }
                        }
                    }
                }
            }

            purchases[turn] = {bestLv, bestId};
            
            if (bestLv >= 0) {
                apples -= (ull)C[bestLv][bestId] * (P[bestLv][bestId] + 1);
                P[bestLv][bestId]++;
            }
            
            // 更新処理
            for (int id = 0; id < N; id++) {
                apples += A[id] * B[0][id] * P[0][id];
            }
            for (int lv = 1; lv < L; lv++) {
                for (int id = 0; id < N; id++) {
                    B[lv-1][id] += B[lv][id] * P[lv][id];
                }
            }
        }
        return {apples, purchases};
    };
    
    // 焼きなまし法
    const double TIME_LIMIT = 1.95;  // 2秒上限
    const double RANDOM_HIGH_PROB = 0.1;  // ランダム高レベル購入の確率
    
    // 初期解: スキップなし、ランダム高レベルなし
    vector<bool> bestSkipList(T, false);
    vector<bool> bestRandomHighLevel(T, false);
    auto [bestApples, bestPurchases] = simulate(bestSkipList, bestRandomHighLevel);
    
    vector<bool> currentSkipList = bestSkipList;
    vector<bool> currentRandomHighLevel = bestRandomHighLevel;
    ull currentApples = bestApples;
    auto currentPurchases = bestPurchases;
    
    int iteration = 0;
    int improved = 0;
    
    while (getElapsed() < TIME_LIMIT) {
        double progress = getElapsed() / TIME_LIMIT;
        double temperature = 1.0 - progress;  // 1.0 -> 0.0
        
        // 近傍解を生成
        vector<bool> newSkipList = currentSkipList;
        vector<bool> newRandomHighLevel = currentRandomHighLevel;
        
        // 変更戦略: スキップまたはランダム高レベルを変更
        int changeType = rng() % 3;  // 0: skip, 1: randomHigh, 2: both
        int numChanges = (rng() % 3 == 0) ? 1 : (1 + rng() % (max(1, (int)(5 * temperature))));
        
        for (int i = 0; i < numChanges; i++) {
            int turn = rng() % T;
            if (changeType == 0 || changeType == 2) {
                newSkipList[turn] = !newSkipList[turn];
            }
            if (changeType == 1 || changeType == 2) {
                // ランダム高レベルの確率的設定
                newRandomHighLevel[turn] = (randDouble() < RANDOM_HIGH_PROB * temperature);
            }
        }
        
        auto [newApples, newPurchases] = simulate(newSkipList, newRandomHighLevel);
        
        // 改善なら採用、悪化でも確率で採用
        double delta = (double)newApples - (double)currentApples;
        bool accept = false;
        if (delta > 0) {
            accept = true;
        } else if (temperature > 0.001) {
            // 温度スケールを調整
            double scale = max(1e10, (double)currentApples * 0.01);
            double acceptProb = exp(delta / (scale * temperature));
            accept = (randDouble() < acceptProb);
        }
        
        if (accept) {
            currentSkipList = move(newSkipList);
            currentRandomHighLevel = move(newRandomHighLevel);
            currentApples = newApples;
            currentPurchases = move(newPurchases);
            
            if (currentApples > bestApples) {
                bestApples = currentApples;
                bestSkipList = currentSkipList;
                bestRandomHighLevel = currentRandomHighLevel;
                bestPurchases = currentPurchases;
                improved++;
            }
        }
        
        iteration++;
    }
    
    // 最適解を出力
    for (int turn = 0; turn < T; turn++) {
        if (bestPurchases[turn].first >= 0) {
            cout << bestPurchases[turn].first << " " << bestPurchases[turn].second << "\n";
        } else {
            cout << "-1\n";
        }
    }
    
    cout << "#Final apples: " << bestApples << endl;
}
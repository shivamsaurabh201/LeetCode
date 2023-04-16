class Solution {
public:
     typedef long long ll;
     int numWays(vector<string>& words, string target) {
        int N = words[0].size();
         vector<vector<int>> cnt(26, vector<int>(N));
         for (auto w : words) {
             for (int i=0; i<N; i++) {
                 cnt[w[i]-'a'][i]++;
            }
        }
        int T = target.size();
        int MOD = 1e9 + 7;
        vector<vector<ll>> dp(T+1, vector<ll>(N+1));
        for (int i=0; i<=N; i++) dp[0][i] = 1;
        
        for (int i=1; i<=T; i++) {
            for (int j=1; j<=N; j++) {
                dp[i][j] = dp[i-1][j-1]*cnt[target[i-1]-'a'][j-1] + dp[i][j-1];
                dp[i][j] %= MOD;
                if (dp[i][j] < 0) dp[i][j] += MOD;
            }
        }
        return dp[T][N];
    }
};
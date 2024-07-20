#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<int> values(n);

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(m+1, 0));

    if(values[0] != 0)
        dp[0][values[0]] = 1;
    else
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;


    for (int i = 1; i < n; i++)
    {
        
        if(values[i] == 0) {
            for (int j = 1; j <= m; j++)
            {
                if(j-1 > 0) {
                    dp[i][j] = (dp[i][j]+dp[i-1][j-1]) % MOD;
                }
                dp[i][j] = (dp[i][j]+dp[i-1][j]) % MOD;
                if(j+1 <= m) {
                    dp[i][j] = (dp[i][j]+dp[i-1][j+1]) % MOD;
                }
            }
        }
        else {
            int j = values[i];
            if(j-1 > 0) {
                dp[i][j] = (dp[i][j]+dp[i-1][j-1]) % MOD;
            }
            dp[i][j] = (dp[i][j]+dp[i-1][j]) % MOD;
            if(j+1 <= m) {
                dp[i][j] = (dp[i][j]+dp[i-1][j+1]) % MOD;
            } 
        }
        
    }
    
    int numberOfArrays = 0;

    for (int i = 1; i <= m; i++)
    {
        numberOfArrays = (numberOfArrays+dp[n-1][i]) % MOD;
    }

    cout << numberOfArrays << endl;
    

}
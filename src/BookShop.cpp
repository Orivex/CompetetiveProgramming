#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;

    cin >> n >> x;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    vector<int> price(n+1);
    vector<int> pages(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {

            dp[i][j] = dp[i-1][j];

            if(j >= price[i]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i]] + pages[i]);
            }

        }   
    }

    cout << dp[n][x];
    

}

#include <bits/stdc++.h>

using namespace std;

vector<int> getDigits(int n);

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n+1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        vector<int> digits = getDigits(i);
        for (int j = 0; j < digits.size(); j++)
        {
            if(digits[j] != 0)
                dp[i] = min(dp[i-digits[j]]+1, dp[i]);
        }
    }

    cout << dp[n] << endl;
    

}

vector<int> getDigits(int n) {
    vector<int> digits;
    while(n > 0) {
        digits.push_back(n%10);
        n/=10;
    }

    return digits;
}
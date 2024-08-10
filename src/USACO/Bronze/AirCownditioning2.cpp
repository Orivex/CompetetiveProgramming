#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> cows(100);
vector<vector<int>> comb;
int upperBound = 0;

int solve(vector<int> currCows, int currComb, int moneySpend) {
    
    for (int i = comb[currComb][0]; i <= comb[currComb][1]; i++)
        currCows[i] -= comb[currComb][2];

    moneySpend += comb[currComb][3];

    bool comfortable = true;

    for (int i = 0; i < upperBound; i++)
    {
        if(currCows[i] > 0) {
            comfortable = false;
            break;
        }
    }
    
    if(comfortable == true)
        return moneySpend;


    int minimum = 1e9;
    for (int i = currComb+1; i < m; i++)
        minimum = min(minimum, solve(currCows, i, moneySpend));
    
    return minimum;
    
}

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    comb.resize(m, vector<int>(4));

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = a-1; j <= b-1; j++)
            cows[j] += c;

        upperBound = max(upperBound, b);
        
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        comb[i][0] = a-1;
        comb[i][1] = b-1;
        comb[i][2] = c;
        comb[i][3] = d;
    }

    int ans = 1e9;
    for (int i = 0; i < m; i++)
        ans = min(ans, solve(cows, i, 0));

    cout << ans << endl;

}
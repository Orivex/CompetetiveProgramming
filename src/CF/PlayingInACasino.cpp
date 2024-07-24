#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int t;
    cin >> t; 

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> cards(n, vector<int>(m));

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> cards[j][k];
            }
            
        }

        int totalChips = 0;

        for (int j = 0; j < m; j++)
        {
            vector<int> column(n);

            for (int k = 0; k < n; k++)
            {
                column[k] = cards[k][j];
            }

            sort(column.begin(), column.end());

            int currentSum = column[0];

            for (int k = 1; k < n; k++)
            {
                totalChips += column[k] * k - currentSum;
                currentSum += column[k];
            }
            
            
        }
        

        cout << totalChips << endl;
    }

}
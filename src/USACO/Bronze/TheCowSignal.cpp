#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("cowsignal.in","r",stdin); 
	freopen("cowsignal.out","w",stdout); 

    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<char>> a(m, vector<char>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        string line;
        for (int j = 0; j < n; j++)
        {
            for (int k_i = 0; k_i < k; k_i++)
            {
                line += a[i][j];
            }
        }
        for (int k_i = 0; k_i < k; k_i++)
        {
            cout << line << endl;
        }
    }
    
    return 0;
    
}   
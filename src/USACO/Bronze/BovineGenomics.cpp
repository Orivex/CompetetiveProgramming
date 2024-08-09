#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("cownomics.in","r",stdin); 
	freopen("cownomics.out","w",stdout); 

    int n, m;
    cin >> n >> m;

    char spotty[n][m] = {};
    char plain[n][m] = {};

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            spotty[i][j] = s[j];
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            plain[i][j] = s[j];
    }

    int ans = 0;
    for (int j = 0; j < m; j++)
    {
        set<char> s;
        for (int i = 0; i < n; i++)
            s.insert(spotty[i][j]);

        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if(s.find(plain[i][j]) != s.end() ) {
                possible = false;
                break;
            }
        }

        if(possible == true)
            ans++;
        
    }
    
    cout << ans << endl;
    

}
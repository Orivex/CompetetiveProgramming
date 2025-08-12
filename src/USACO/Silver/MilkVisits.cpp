#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent;
vector<pair<bool, bool>> hasMilk;
vector<char> pref;

int main(){ 

    freopen("milkvisits.in","r",stdin); 
    freopen("milkvisits.out","w",stdout);

    int n, m;
    cin >> n >> m;

    parent.resize(n+1, 0);
    pref.resize(n+1);

    string s;
    cin >> s;

    for (int i = 1; i < n+1; i++)
        pref[i] = s[i-1];
    

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        parent[b] = a;
        
        char c;
        cin >> c;
    }

    string ans = "";

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        char c;
        cin >> c;

        bool found = false;

        int curr = b;
        while(curr != a) {
            
            if(pref[curr] == c) {
                found = true;
                ans += "1";
                break;
            }

            curr = parent[curr];
        }

        if(!found)
            ans += "0";

    }

    cout << ans << endl;
    
    
}
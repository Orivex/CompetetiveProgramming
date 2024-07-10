#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int n, x;

    cin >> n >> x;

    vector<int> a(n);
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        a[i] = val;
        s.insert(val);
    }

    for (int i = 0; i < n; i++)
    {
        if(s.find(x-a[i]) == s.end())
            continue;

        for (int j = 0; j < n; j++)
        {
            if(j == i)
                continue;

            if(a[j] == (x-a[i])){
                cout << (i+1) << " " << (j+1);
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
    
    

}
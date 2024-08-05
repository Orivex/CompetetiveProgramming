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
        cin >> a[i];
        s.insert(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(s.find(x-a[i]-a[j]) == s.end())
                continue;

            for (int k = 0; k < n; k++)
            {
                if(k == j || k == i)
                    continue;

                if(x-a[i]-a[j] == a[k]) {
                    cout << i+1 << " " << j+1 << " " << k+1 << endl;
                    return 0;
                }
            }
            

        }
        
    }

    cout << "IMPOSSIBLE" << endl;
    
}

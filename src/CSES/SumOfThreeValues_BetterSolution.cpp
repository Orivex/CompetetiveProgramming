#include <bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        a[i] = make_pair(val, i);
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        int x2 = x-a[i].first;
        for (int j = i+1, k = n-1; j < k; j++)
        {
            while(a[j].first+a[k].first > x2)
                k--;

            if(a[j].first+a[k].first == x2 && j < k) {
                cout << a[i].second+1 << " " << a[j].second+1 << " " << a[k].second+1 << endl;
                return 0;
            }
        }
        
    }

    cout << "IMPOSSIBLE" << endl;

}

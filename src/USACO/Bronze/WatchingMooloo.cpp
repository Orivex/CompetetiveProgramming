#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> days(n);

    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }

    int moonies = k+1;

    for (int i = 1; i < n; i++)
    {
        moonies += min(k+1, days[i]-days[i-1]);
    }
    
    cout << moonies << endl;

}
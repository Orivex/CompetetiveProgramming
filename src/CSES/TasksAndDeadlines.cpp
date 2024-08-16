#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    ll time = 0;

    for (int i = 0; i < n; i++)
    {
        time += v[i].first;
        ans += (v[i].second-time);
    }

    cout << ans << endl;
    
    

}
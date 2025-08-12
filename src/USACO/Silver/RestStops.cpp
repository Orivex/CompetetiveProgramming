#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){ 

    freopen("reststops.in","r",stdin); 
    freopen("reststops.out","w",stdout);

    ll l, n, rF, rB;
    cin >> l >> n >> rF >> rB;

    vector<ll> x(n);
    vector<ll> c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> c[i];
    }
    
    vector<bool> goodStops(n);

    int maximum = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if(c[i] > maximum) {
            goodStops[i] = true,
            maximum = c[i];
        }
    }

    int prev = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(!goodStops[i])
            continue;

        ll traveledDistance = x[i] - prev;
        prev = x[i];
        ll fTime = traveledDistance * rF;
        ll bTime = traveledDistance * rB;
        ll restTime = fTime - bTime;
        sum += restTime * c[i];
    }

    cout << sum << endl;
    
    

}
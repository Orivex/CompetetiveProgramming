#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll a, ll b) {
    if(a == b)
        return 0;

    if(a > b)
    {
        ll odd = a % 2;
        return 1 + odd + solve((a+odd)/2, b);
    }
    else {
        ll odd = b % 2;
        return min(b-a, 1 + odd + solve(a, b/2));
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    
}
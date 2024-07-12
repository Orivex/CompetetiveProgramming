#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> array(n);

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    
    vector<long long> prefix(n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i-1] + array[i-1];
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << prefix[b] - prefix[a-1] << "\n";
    }
    
    
}
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(2*n);

    for (int i = 0; i < 2*n; i++)
        cin >> v[i];


    sort(v.begin(), v.end());

    int maxDiff = 0;
    int instability = 0;
    for (int i = 0; i < (2*n)-1; i+=2)
    {
        int diff = v[i+1]-v[i];
        instability += diff;

        if( ( v[maxDiff+1]-v[maxDiff] ) < diff)
            maxDiff = i;
    }

    cout << instability-(v[maxDiff+1]-v[maxDiff]) << endl;


}
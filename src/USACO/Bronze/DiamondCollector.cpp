#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("diamond.in","r",stdin); 
	freopen("diamond.out","w",stdout); 

    int n, k;
    cin >> n >> k;
    vector<int> d(n);

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    sort(d.begin(), d.end());

    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        if(n-i < maximum) {
            break;
        }

        int diamonds = 0;
        int j = i;

        while(abs(d[i]-d[j]) <= k && j < n) {
            diamonds++;
            j++;
        }

        maximum = max(maximum, diamonds);

    }

    cout << maximum << endl;
    

}
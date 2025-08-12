#include <bits/stdc++.h>
using namespace std;

int n, m, c;
vector<int> v;

bool check(int interval)  {
    int busses = 0;
    int lcow = 0;
    int cow = 0;

    while(cow < n) {

        if(cow == lcow) {
            busses++;
        }

        if(v[cow]-v[lcow] > interval) {
            lcow = cow;
        }
        else if(cow - lcow + 1 == c) 
            lcow = ++cow;
        else
            cow++;
    }

    if(busses > m)
        return false;

    return true;
    
}


int main() { 

    freopen("convention.in","r",stdin); 
	freopen("convention.out","w",stdout);

    cin >> n >> m >> c;

    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int low = 0;
    int high = v[n-1]-v[0];

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(check(mid))
            high = mid;
        else
            low = mid+1;
    }

    cout << low << endl;
    
    

}
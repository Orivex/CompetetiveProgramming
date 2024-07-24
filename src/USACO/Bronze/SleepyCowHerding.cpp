#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("herding.in","r",stdin); 
	freopen("herding.out","w",stdout); 

    int cows[3];
    cin >> cows[0] >> cows[1] >> cows[2];

    int dist1 = cows[1] - cows[0] - 1;
    int dist2 = cows[2] - cows[1] - 1;

    if(dist1 == 0 && dist2 == 0) {
        cout << 0 << endl << 0 << endl;
        return 0;
    }
    else if(dist1 == 1 || dist2 == 1) {
        cout << 1 << endl;
    }
    else
        cout << 2 << endl;

    cout << max(dist1, dist2) << endl;

}
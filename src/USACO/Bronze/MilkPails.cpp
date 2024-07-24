#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("pails.in","r",stdin); 
	freopen("pails.out","w",stdout); 

    int x, y, m;
    cin >> x >> y >> m;

    int maximum = 0;
    int start = 0;

    while(start <= m && maximum < m) {
        int sum = start;
        while((sum+x) <= m) {
            sum += x;
        }
        maximum = max(maximum, sum);
        start += y;
    }

    cout << maximum << endl;

}
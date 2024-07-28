#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("square.in","r",stdin); 
	freopen("square.out","w",stdout); 

    int ax1, ay1, ax2, ay2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;

    int bx1, by1, bx2, by2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    int length = max(ay2, by2) - min(ay1, by1);
    int width = max(ax2, bx2) - min(ax1, bx1);

    int size = max(length, width);

    cout << size*size << endl;

}

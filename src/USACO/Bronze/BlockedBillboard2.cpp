#include <bits/stdc++.h>

using namespace std;

int getArea(int x1, int y1, int x2, int y2);
int getIntersectionArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("billboard.in","r",stdin); 
	freopen("billboard.out","w",stdout); 

    int ax1, ay1, ax2, ay2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;

    int bx1, by1, bx2, by2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    if( (bx1 > ax1 && bx2 < ax2 ) || (by1 > ay1 && by2 < ay2) )
        cout << getArea(ax1, ay1, ax2, ay2) << endl;
    else if( (bx1 <= ax1 && bx2 >= ax2) || (by1 <= ay1 && by2 >= ay2) )
        cout << getArea(ax1, ay1, ax2, ay2) - getIntersectionArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
    else 
        cout << getArea(ax1, ay1, ax2, ay2) << endl;

    return 0;
}

int getArea(int x1, int y1, int x2, int y2) {
    return (y2 - y1) * (x2 - x1); 
}

int getIntersectionArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    return ( min(ax2, bx2) - max(ax1, bx1) ) * ( min(ay2, by2) - max(ay1, by1) );
}
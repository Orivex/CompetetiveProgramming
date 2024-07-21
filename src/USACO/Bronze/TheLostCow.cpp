#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("lostcow.in","r",stdin); 
	freopen("lostcow.out","w",stdout); 

    int x, y;
    cin >> x >> y;

    int current = x;
    int nextSteps = 1;
    int total = 0;

    while(current != y) {

        int plusOrMinus = nextSteps > 0 ? 1: -1;

        while(current != (x+nextSteps)) {
            if(current == y) {
                cout << total << endl;
                return 0;
            }
            total++;
            current += plusOrMinus;
        }

        nextSteps *= -2;
    }

    cout << total << endl;
    
}
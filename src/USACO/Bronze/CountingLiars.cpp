#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    int low = -1e9;
    int upper = 1e9;
    int liars = 0;
    for (int i = 0; i < n; i++)
    {
        char a;
        int b;
        cin >> a >> b;

        if(a == 'G') {
            if(b > low && b < upper)
                low = b;

            if(b > upper)
                liars++;
        }
        else if(a == 'L') {
            if(b < upper && b > low)
                upper = b;

            if(b < low)
                liars++;
        }

        
    }

    cout << liars << endl;
    

}
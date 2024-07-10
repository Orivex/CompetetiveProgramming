#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    long a, b;

    cin >> a >> b;

    long result = 1;

    while (b > 0)
    {
        
        if(b % 2 == 1) {
            result *= a;
            a = 1;
        }

        a *= a;
        b /= 2;
    }
    
    cout << result;
}
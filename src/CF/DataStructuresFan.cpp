#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    //freopen("dsfan.in","r",stdin); 
	//freopen("dsfan.out","w",stdout); 

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<int> a(n+1);
        vector<int> prefix(n+1);
        prefix[0] = 0;
        int xor0 = 0;
        int xor1 = 0;

        for (int j = 1; j <= n; j++){
            cin >> a[j];
            prefix[j] = prefix[j-1] ^ a[j];
        }
        
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++){
            if(s[j-1] == '1')   
                xor1 ^= a[j];
            else
                xor0 ^= a[j];
        }

        int q;
        cin >> q;

        for (int j = 0; j < q; j++)
        {
            int tp;
            cin >> tp;

            if(tp == 1) {
                int l, r;
                cin >> l >> r;

                int nextXor = prefix[r] ^ prefix[l-1];
                xor0 ^= nextXor;
                xor1 ^= nextXor;
            }
            else {
                int bit;
                cin >> bit;

                if(bit == 0)
                    cout << xor0 << " ";
                else 
                    cout << xor1 << " ";
            }
        }

        cout << endl;   
        
    }

    return 0;

}
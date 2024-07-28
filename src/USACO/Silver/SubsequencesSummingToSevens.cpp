#include <bits/stdc++.h>
using namespace std;
#define int long long int


int32_t main(){ 

    freopen("div7.in","r",stdin); 
	freopen("div7.out","w",stdout);

    int n;
    cin >> n;

    vector<int> ids;
    vector<int> prefix;
    ids.push_back(0);
    prefix.push_back(0);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int id;
        cin >> id;
        ids.push_back(id);
        prefix.push_back(prefix[i-1] + id);
        int value = prefix[i];
        for (int j = 0; j < i; j++)
        {
            value -= ids[j];

            if(value < 7)
                break;

            if(value % 7 == 0) 
                ans = max(ans, i-j);
        }
        
    }

    cout << ans << endl;

}
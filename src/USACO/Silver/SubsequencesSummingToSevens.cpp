#include <bits/stdc++.h>
using namespace std;
#define int long long int


int32_t main(){ 

    freopen("div7.in","r",stdin); 
	freopen("div7.out","w",stdout);

    int n;
    cin >> n;

    vector<int> prefix(n+1, 0);
    for (int i = 1; i < n; i++)
    {
        int id;
        cin >> id;
        prefix[i] = (prefix[i-1] + id) % 7;
    }

    vector<int> firstoccurence(7);
    for (int i = 0; i < 7; i++)
    {
        firstoccurence[i] = -1;
    }
    
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(firstoccurence[prefix[i]] == -1)
            firstoccurence[prefix[i]] = i;
        else 
            ans = max(ans, i - firstoccurence[prefix[i]]);
    }
    

    cout << ans << endl;

}
#include <bits/stdc++.h>
using namespace std;

int main(){ 

    freopen("hps.in","r",stdin); 
	freopen("hps.out","w",stdout);

    int n;
    cin >> n;

    vector<int> h(n+1);
    vector<int> p(n+1);
    vector<int> s(n+1);
    for (int i = 1; i <= n; i++)
    {
        h[i] = h[i-1];
        p[i] = p[i-1];
        s[i] = s[i-1];

        char ch;
        cin >> ch;

        if(ch == 'H')
            p[i]++;
        else if(ch == 'P')
            s[i]++;
        else
            h[i]++; 

    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int current = max(h[i], max(p[i], s[i])); //Maximum der gewonnen Runden bis Runde i
        int afterSwitch = max(h[n]-h[i], max(p[n]-p[i], s[n]-s[i])); //Maximum der gewonnen Runden von i bis n

        ans = max(ans, current+afterSwitch);
    }
    
    cout << ans << endl;

}
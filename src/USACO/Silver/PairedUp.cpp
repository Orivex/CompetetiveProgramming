#include <bits/stdc++.h>
using namespace std;

int main(){ 

    freopen("pairup.in","r",stdin); 
    freopen("pairup.out","w",stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        cows[i] = {a, b}; 
    }

    int currL = 0;
    int countL = 0;
    int currR = n-1;
    int countR = 0;
    int ans = 0;

    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) {return a.second < b.second;});

    while(currL < currR) {
        ans = max(ans, cows[currL].second+cows[currR].second);
        countL++;
        countR++;

        if(countL == cows[currL].first){
            countL = 0;
            currL++;
        }
        if(countR == cows[currR].first){
            countR = 0;
            currR--;
        }
    }

    cout << ans << endl;

}
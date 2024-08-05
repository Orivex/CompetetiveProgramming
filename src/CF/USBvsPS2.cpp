#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int m;
    cin >> m;
    vector<pair<int, int>> priceList(m);
    for (int i = 0; i < m; i++)
    {
        cin >> priceList[i].first;
        string s;
        cin >> s;
        if(s == "USB")
            priceList[i].second = 0;
        else
            priceList[i].second = 1;
    }

    sort(priceList.begin(), priceList.end());

    int equipped = 0;
    int cost = 0;
    for (int i = 0; i < m; i++)
    {
        if(priceList[i].second == 0 && a > 0) {
            equipped++;
            cost += priceList[i].first;
            a--;
        }
        else if(priceList[i].second == 1 && b > 0) {
            equipped++;
            cost += priceList[i].first;
            b--;
        }
        else if(c > 0){
            equipped++;
            cost += priceList[i].first;
            c--;
        }
    }
    
    cout << equipped << " " << cost << endl;
    return 0;

}
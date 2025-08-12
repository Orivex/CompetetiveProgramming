#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> c;
vector<int> t;

int nextTower(int city) {
    int low = 0;
    int high = m;
    while(low < high) {
        int mid = low + (high - low) / 2; 
        if(t[mid] >= city) 
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    //freopen("clnetwork.in","r",stdin); 
    //freopen("clnetwork.out","w",stdout); 
    
    cin >> n >> m;
    c.resize(n);
    t.resize(m);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];
    
    int minR = -INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int minRcurrCity = INT_MAX;
        int currCity = c[i];
        int towerRight = nextTower(currCity);
        int towerLeft = towerRight-1;
        if(towerRight < m) {
            minRcurrCity = min(minRcurrCity, t[towerRight]-currCity);
        }
        
        if(towerLeft >= 0) {
            minRcurrCity = min(minRcurrCity, currCity-t[towerLeft]);              
        }
        minR = max(minR, minRcurrCity);
    }
    cout << minR << endl;
}
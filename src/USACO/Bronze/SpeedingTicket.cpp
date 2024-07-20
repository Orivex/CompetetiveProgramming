#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("speeding.in","r",stdin); 
	freopen("speeding.out","w",stdout); 

    int n, m;
    cin >> n >> m;

    vector<int> limit;
    vector<int> speed;
    int distance1, distance2;
    int i = 0, j = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < a; j++)
        {
            limit.push_back(b);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < a; j++)
        {
            speed.push_back(b);
        }
    }

    int overSpeed = 0;
    for (int i = 0; i < speed.size(); i++)
    {
        overSpeed = max(overSpeed, speed[i]-limit[i]);
    }
    
    cout << overSpeed;

}

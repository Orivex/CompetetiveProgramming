#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, char>> v;
    for (int i = 0; i < n; i++)
    {
        char a;
        int b;
        cin >> a >> b;

        v.push_back({b, a});

    }

    sort(v.begin(), v.end());

    int minLiars = n;

    for (int i = 0; i < n; i++)
    {
        int currLiars = 0;
        for (int j = 0; j < i; j++)
        {
            if(v[j].second == 'L')
                currLiars++;
        }

        for (int j = i+1; j < n; j++)
        {
            if(v[j].second == 'G')
                currLiars++;
        }

        minLiars = min(minLiars, currLiars);
        
    }
    
    cout << minLiars << endl;
    

}
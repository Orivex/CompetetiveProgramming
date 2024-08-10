#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(2*n);

    for (int i = 0; i < 2*n; i++)
        cin >> v[i];
    
    
    sort(v.begin(), v.end());

    int minimum = 1e9;
    for (int i = 0; i < 2*n; i++)
    {
        for (int j = i+1; j < 2*n; j++)
        {
            vector<int> tandem;
            for (int k = 0; k < 2*n; k++)
            {
                if(k != i && k != j)
                    tandem.push_back(v[k]);
            }

            int instability = 0;
            for (int k = 0; k < 2*n-2; k+=2)
            {
                instability += tandem[k+1]-tandem[k];
            }

            minimum = min(minimum, instability);
        }
        
    }

    cout << minimum << endl;
    

}
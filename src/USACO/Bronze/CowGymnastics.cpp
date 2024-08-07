#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("gymnastics.in","r",stdin); 
	freopen("gymnastics.out","w",stdout); 

    int k, n;
    cin >> k >> n;

    vector<vector<int>> v(k, vector<int>(n));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            v[i][val-1] = j;
        }
    }

    int pairs = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            bool hasToBeBigger = v[0][i] > v[0][j];
            bool works = true;
            for (int m = 1; m < k; m++)
            {
                if( (v[m][i] > v[m][j] && hasToBeBigger == false) || (v[m][i] < v[m][j] && hasToBeBigger == true) ) {
                    works = false;
                    break;
                }
            }

            if(works == true)  {
                pairs++;
            }

        }
        
    }

    cout << pairs << endl;
    
    

}
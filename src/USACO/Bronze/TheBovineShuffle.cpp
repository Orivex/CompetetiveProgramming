#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("shuffle.in","r",stdin); 
	freopen("shuffle.out","w",stdout); 

    int n;
    cin >> n;

    vector<int> shuffle(n);

    for (int i = 0; i < n; i++)
    {
        cin >> shuffle[i];
    }

    vector<string> cows(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }

    vector<string> beforeShuffle(n);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            beforeShuffle[j] = cows[shuffle[j]-1]; 
        }

        cows = beforeShuffle;
    }

    for (int i = 0; i < n; i++)
    {
        cout << cows[i] << endl;
    }
    

}
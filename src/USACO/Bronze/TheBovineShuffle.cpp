#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("shuffle.in","r",stdin); 
	freopen("shuffle.out","w",stdout); 

    int n;
    cin >> n;

    vector<int> shuffle(n);

    for (int i = 0; i < n; i++)
    {
        cin >> shuffle[i];
    }

    vector<string> id(n);

    for (int i = 0; i < n; i++)
    {
        cin >> id[i];
    }

    vector<string> beforeShuffle(n);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            beforeShuffle[j] = id[shuffle[j]-1]; //beforeShuffle[2] = id[shuffle[2]-1] -> id[4-1] -> id[3] -> 4;
        }

        id = beforeShuffle;
    }

    for (int i = 0; i < n; i++)
    {
        cout << id[i] << endl;
    }
    

}


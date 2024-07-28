#include <bits/stdc++.h>
using namespace std;


int main(){ 

    freopen("bcount.in","r",stdin); 
	freopen("bcount.out","w",stdout);

    int n, q;
    cin >> n >> q;

    vector<int> breed1(n+1);
    vector<int> breed2(n+1);
    vector<int> breed3(n+1);

    for (int i = 1; i <= n; i++)
    {
        int breedID;
        cin >> breedID;

        breed1[i] = breed1[i-1];
        breed2[i] = breed2[i-1];
        breed3[i] = breed3[i-1];

        switch (breedID)
        {
        case 1:
            breed1[i]++;
            break;
        case 2:
            breed2[i]++;
            break;
        case 3:
            breed3[i]++;
            break;
        }

    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << breed1[b]- breed1[a-1] << " ";
        cout << breed2[b]- breed2[a-1] << " ";
        cout << breed3[b]- breed3[a-1] << endl;
    }
    
    

}
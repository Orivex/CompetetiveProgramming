#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("blocks.in","r",stdin); 
	freopen("blocks.out","w",stdout); 

    int n;
    cin >> n;

    int sol[26] = {};

    for (int i = 0; i < n; i++)
    {
        string w1, w2;
        cin >> w1 >> w2;

        int temp[26][2] = {};

        for(char ch : w1) {
            temp[ch-'a'][0]++;
        }
        for(char ch : w2) {
            temp[ch-'a'][1]++;
        }

        for (int i = 0; i < 26; i++)
            sol[i] += max(temp[i][0], temp[i][1]);
         
    }

    for(int i : sol) 
        cout << i << endl;
    

}


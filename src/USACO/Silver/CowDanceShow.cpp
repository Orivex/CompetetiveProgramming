#include <bits/stdc++.h>
using namespace std;


bool works(int k);
int n, t_max;
vector<int> v;

int main(){ 

    freopen("cowdance.in","r",stdin); 
	freopen("cowdance.out","w",stdout);

    cin >> n >> t_max;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }

    int low = 1, high = n;
    int k = low + (high - low) / 2;
    while (low < high)
    {
        if(!works(k))
            low = k+1;
        else
            high = k;
        
        k = low + (high - low) / 2;

    }
    
    cout << k << endl;

}

bool works(int k) {

    vector<int> dancingCows;

    for (int i = 0; i < k; i++)
    {
        dancingCows.push_back(v[i]);
    }

    int i = k+1;
    int t = 0;
    bool cowsLeft = true;
    while(cowsLeft) {
        int firstToEnd = 100001;
        for (int j = 0; j < k; j++)
        {
            firstToEnd = min(firstToEnd, dancingCows[j]);
        }

        t += firstToEnd;
        
        for (int j = 0; j < k; j++)
        {
            dancingCows[j] -= firstToEnd;
            if(dancingCows[j] == 0) {
                if(i != n) {
                    dancingCows[j] = v[i];
                    i++;
                }
                else 
                    cowsLeft = false;
            }
        }
        
    }

    int remain = 0;
    for (int j = 0; j < k; j++)
    {
        remain = max(remain, dancingCows[j]);
    }

    return (t + remain) <= t_max;
    
}
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    freopen("blist.in","r",stdin); 
	freopen("blist.out","w",stdout); 

    int n;
    cin >> n;

    int length = 0;
    vector<int> list(1000, 0);

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        list[a] = c;
        list[b] = -1*c;

        length = max(length, b); 
    }
    
    int currentBuckets = 0;
    int maxBuckets = 0;
    for (int i = 0; i < length; i++)
    {
        currentBuckets += list[i];
        maxBuckets = max(currentBuckets, maxBuckets);
    }

    cout << maxBuckets << endl;
    


}
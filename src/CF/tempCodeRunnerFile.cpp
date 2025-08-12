    #include <bits/stdc++.h>

    using namespace std;

    int n, m;
    vector<int> c;
    vector<int> t;

    bool check(int r) {

        int i = 0;
        int j = 0;

        while(i < m) {
            while(t[i] > c[j]) {
                if( c[j] < (t[i]-r) ) {
                                    return false;
                }

                j++;
            }

            bool covered = true;
            while(t[i] < c[j] && j < n) {
                if( c[j] > (t[i]+r) ) {
                    covered = false;
                    break;
                }

                j++;
            }

            i++;

            if(i == m && covered == false)
                return false;
        }

        return true;

    }

    int main() {

        ios_base::sync_with_stdio(0); 
        cin.tie(0);

        //freopen("clnetwork.in","r",stdin); 
        //freopen("clnetwork.out","w",stdout); 

        cin >> n >> m;

        c.resize(n);
        t.resize(m);

        int minC = INT_MAX, maxC = -INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            c[i] = val;
            minC = min(minC, val);
            maxC = max(maxC, val);
        }
        

        int minT = INT_MAX, maxT = -INT_MAX;
        for (int i = 0; i < m; i++)
        {
            int val;
            cin >> val;
            t[i] = val;
            minT = min(minT, val);
            maxT = max(maxT, val);
        }

        int maxR = max(maxC-minT, maxT-minC);

        int high = maxR, low = 0;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(check(mid)) {
                high = mid;
            }
            else
                low = mid+1;
        }

        cout << low << endl;


    }
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    long long n, x;

    cin >> n >> x;

    map<long long, int> sumCounts;
    sumCounts[0] = 1;

    long long sum = 0;
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        sum += val;

        long long needToDelete = sum - x;

        if(sumCounts.find(needToDelete) != sumCounts.end()) {
            counter += sumCounts.at(needToDelete);
        }

        sumCounts[sum]++;
    }
    

    cout << counter;

}
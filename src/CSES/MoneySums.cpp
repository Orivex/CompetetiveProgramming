#include <bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n;
    
    cin >> n;

    vector<int> coins(n);
    int maxSum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        maxSum += coins[i];
    }

    vector<bool> sums(maxSum+1, false);
    sums[0] = true;

    for (int i = 0; i < coins.size(); i++)
    {
        int currentSum = maxSum;

        while(currentSum >= coins[i]) {
            int newSum = currentSum - coins[i];

            if(sums[newSum] == true) {
                sums[currentSum] = true;
            }

            currentSum--;
        }
    }

    int count = 0;
    string result;
    for (int i = 1; i < sums.size(); i++)
    {
        if(sums[i] == true){
            count++;
            result = result.append(to_string(i) + " ");
        }
    }

    cout << count << endl << result;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,amount);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;coins[j]<=i && j<coins.size();j++){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return dp[amount];
    }
};
int main(){

    Solution s;
    vector<int> vec{1,2,5};
    int am=20;
    int res=s.coinChange(vec,am);
    cout<<res<<endl;
    return 0;
}
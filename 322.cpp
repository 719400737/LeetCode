#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size() && coins[j]<=i;j++){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        if(dp[amount]>=amount+1)
            return -1;
        return dp[amount];
    }
};
int main(){

    Solution s;
    vector<int> vec{1};
    int am=11;
    int res=s.coinChange(vec,am);
    cout<<res<<endl;
    return 0;
}
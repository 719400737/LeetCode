#include<bits/stdc++.h>
using namespace std;
class Solution {
//vector<vector<vector<int>>> dp;
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(prices.size()==0){
            return 0;
        }
        int K=1;
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        //dp(prices.size,vector<int>(K,vector<int>(2,0)));
        //dp[i][k][0]表示第i天，进行了k次交易，0表示现在未持有股票
        for(int i=0;i<prices.size();i++){
               if(i==0){
                   dp[i][0]=0;
                   dp[i][1]=-prices[0];
               }
               else if(i==1){
                   dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
                   dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
               else{
                    dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
                    dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i]);
               }
           }
        return dp[n-1][0];
    }
};
int main(){



    return 0;
}
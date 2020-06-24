#include<bits/stdc++.h>
using namespace std;
class Solution {
//vector<vector<vector<int>>> dp;
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int K=1;
        //vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        //dp(prices.size,vector<int>(K,vector<int>(2,0)));
        //dp[i][k][0]表示第i天，进行了k次交易，0表示现在未持有股票
        int dp[2];
        for(int i=0;i<prices.size();i++){
               if( i==0){
                   dp[0]=0;
                  dp[1]=-prices[0];
               }
               else{
                    dp[0]=max(dp[0],dp[1]+prices[i]);
                    dp[1]=max(dp[1],-prices[i]);
               }
           }
        return dp[0];
    }
};
int main(){



    return 0;
}
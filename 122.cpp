#include<bits/stdc++.h>
using namespace std;

class Solution {
//vector<vector<vector<int>>> dp;
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        //dp(prices.size,vector<int>(K,vector<int>(2,0)));
        //dp[i][k][0]表示第i天，进行了k次交易，0表示现在未持有股票
        for(int i=0;i<prices.size();i++){
               if( i==0){
                   dp[i][0]=0;
                   dp[i][1]=-prices[0];
               }
               else{
                    dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
                    dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
               }
           }
        return dp[prices.size()-1][0];
    }
};
int main(){
    Solution s;
    vector<int> vec={7,1,5,3,6,4};
    int res=s.maxProfit(vec);
    cout<<res<<endl;
    return 0;
}
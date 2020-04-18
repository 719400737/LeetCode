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
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(K+1,vector<int>(2,0)));
        //dp(prices.size,vector<int>(K,vector<int>(2,0)));
        //dp[i][k][0]表示第i天，进行了k次交易，0表示现在未持有股票
        for(int i=0;i<prices.size();i++){
           for(int k=0;k<=K;k++){
               if(k==0 || i==0){
                   dp[i][k][0]=0;
                   if(i)
                        dp[i][k][1]=INT_MIN;
                    else
                        dp[i][k][1]=-prices[i];
               }
               else{
                    dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                    dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
               }
           }
        }
        return dp[prices.size()-1][K][0];
    }
};

int main(){
    Solution s;
    vector<int> vec={7,1,5,3,6,4};
    int res=s.maxProfit(vec);
    cout<<res<<endl;
    return 0;
}
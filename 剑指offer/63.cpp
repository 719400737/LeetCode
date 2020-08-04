#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*int maxProfit(vector<int>& prices) { //可以进行无限次交易
        int m=prices.size();
        vector<vector<int>> dp(m+1,vector<int>(2,0));
        for(int i=0;i<=m;i++){
            if(i==0)
                dp[i][1]=INT_MIN;
            else{
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
                dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
            }
        }
        return dp[m][0];
    }*/
    int maxProfit(vector<int>& prices) { //只能进行1次交易
        int m=prices.size();
        vector<int> dp(2,0);
        dp[1]=INT_MIN;
        for(int i=0;i<m;i++){
            dp[0]=max(dp[0],dp[1]+prices[i]);
            dp[1]=max(dp[1],0-prices[i]); //因为只允许交易一次，所以这里
                                          //需要每次从0开始减，意味这前面没有操作  
        }
        return dp[0];
    }
};

int main(){



    return 0;
}
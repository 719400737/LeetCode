#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        int dp[3][2];
        for(int i=0;i<n;i++){
            for(int k=0;k<3;k++){
                if(k==0 || i==0){
                    dp[k][0]=0;
                    if(k==0)
                        dp[k][1]=INT_MIN;
                    if(i==0){
                        dp[k][1]=-prices[i];
                    }

                }
                else{
                    dp[k][0]=max(dp[k][0],dp[k][1]+prices[i]);
                    dp[k][1]=max(dp[k][1],dp[k-1][0]-prices[i]);
                }
            }
        }
        return dp[2][0];
    }
};
int main(){



    return 0;
}
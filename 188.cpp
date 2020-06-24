#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int K,vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        int dp[2];
        int k_1;
        for(int i=0;i<n;i++){
            for(int k=0;k<K+1;k++){
                if(k==0 || i==0){
                    dp[0]=0;
                    if(k==0)
                        dp[1]=INT_MIN;
                    if(i==0){
                        dp[1]=-prices[i];
                    }
                    k_1=dp[0];
                }
                else{
                    dp[0]=max(dp[0],dp[1]+prices[i]);
                    dp[1]=max(dp[1],dp[k-1][0]-prices[i]);
                }
            }
        }
        return dp[K][0];
    }
};
int main(){



    return 0;
}
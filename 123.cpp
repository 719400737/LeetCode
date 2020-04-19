#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        int K=2;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(K+1,vector<int>(2,0)));
        for(int i=0;i<n;i++){
            for(int k=0;k<=K;k++){
                if(k==0 || i==0){
                    if(k==0)
                        dp[i][k][1]=INT_MIN;
                    if(i==0){
                        dp[i][k][1]=-prices[i];
                    }

                }
                else{
                    dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                    dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
                }
            }
        }
        return dp[n-1][K][0];
    }
};

int main(){
    Solution s;
    vector<int> vec={3,3,5,0,0,3,1,4};
    int res=s.maxProfit(vec);
    cout<<res<<endl;
    return 0;
}
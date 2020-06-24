#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));//0表示最小值，1表示最大值
        int nmax=nums[0];
        int nmin=nums[0];
        dp[0][0]=nmax;
        dp[0][1]=nmin;
        for(int i=1;i<n;i++){
            
            if(nums[i]>=0){
                dp[i][0]=min(dp[i-1][0]*nums[i],nums[i]);
                dp[i][1]=max(dp[i-1][1]*nums[i],nums[i]);   
            }
            else{
                dp[i][0]=min(dp[i-1][1]*nums[i],nums[i]);
                dp[i][1]=max(dp[i-1][0]*nums[i],nums[i]);
            }
            nmax=max(nmax,dp[i][1]);
            
            //nmax=max(nmax,nums[i-1]*nums[i]);
            //nmin=min(nmin,nums[i-1]*nums[i]);
        }
        return nmax;
    }
};
int main(){



    return 0;
}
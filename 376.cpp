#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int res=1;
        vector<vector<int>> dp(n,vector<int>(2,1));
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                continue;
            }
            for(int j=0;j<i;j++){
                dp[i][0]=nums[i]-nums[j];
                if(dp[i][0]*dp[j][0]<0)
                    dp[i][1]=max(dp[i][1],dp[j][1]+1);
                else
                    dp[i][1]=max(dp[i][1],2);
                }
            res=max(res,dp[i][1]);
        }
        return res;
    }
};
int main(){

    Solution s;
    vector<int> vec{1,1};
    int res=s.wiggleMaxLength(vec);
    cout<<res<<endl;
    return 0;
}
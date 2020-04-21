#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int dp[n][2];
        for(int i=0;i<n;i++){
            if(i==0){
                dp[i][0]=0;
                dp[i][1]=nums[i];
            }
            else if(i==1){
                dp[i][0]=dp[i-1][1];
                dp[i][1]=nums[i];
            }
            else{
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                dp[i][1]=dp[i-1][0]+nums[i];
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
int main(){
    vector<int> vec{1,2,3,1};
    Solution s;
    int res=s.rob(vec);
    cout<<res<<endl;

    return 0;
}
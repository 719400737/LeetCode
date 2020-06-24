#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        int jie=0;    //本次需要更新到的界线
        int yuanjie=0;//定义上一次更新的界线
        for(int i=0;i<n;i++){
            jie=i+nums[i];
            for(int j=yuanjie+1;j<=jie;j++){
                if(j==n)
                    return  dp[j-1];
                dp[j]=dp[i]+1;
                if(dp[n-1]!=INT_MAX)
                    return dp[n-1];
                yuanjie=jie;
            }
        }
        return dp[n-1];       
    }
};

int main(){
    vector<int> vec={2,3,1,1,1};
    Solution s;
    int res=s.jump(vec);
    cout<<res<<endl; 

    return 0;
}
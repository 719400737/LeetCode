#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        int dp1[n][2];
        int dp2[n][2];
        for(int i=0;i<n;i++){
            if(i==0){
                dp1[i][0]=0;
                dp1[i][1]=nums[i];
                dp2[i][0]=0;
                dp2[i][1]=0;
            }
            else if(i==1){
                dp1[i][0]=dp1[i-1][1];
                dp1[i][1]=nums[i];
                dp2[i][0]=dp2[i-1][1];
                dp2[i][1]=nums[i];
            }
            else{
                dp1[i][0]=max(dp1[i-1][0],dp1[i-1][1]);
                dp1[i][1]=dp1[i-1][0]+nums[i];
                dp2[i][0]=max(dp2[i-1][0],dp2[i-1][1]);
                dp2[i][1]=dp2[i-1][0]+nums[i];
            }
        }
        int res1=max(dp1[n-2][0],dp1[n-2][1]);
        int res2=max(dp2[n-1][0],dp2[n-1][1]);
        return max(res1,res2);
    }
};
int main(){
    vector<int> vec{1,2};
    Solution s;
    int res=s.rob(vec);
    cout<<res<<endl;

    return 0;
}
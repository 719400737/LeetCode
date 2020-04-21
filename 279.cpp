#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> vec;
        vector<int> dp(n+1,n);
        dp[0]=0;
        for(int i=1;i<n+1;i++){
            for(int j=sqrt(i);j>0;j--){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
int main(){

    int n=8285;
    Solution s;

    int res=s.numSquares(n);
    cout<<res<<endl;

    return 0;
}
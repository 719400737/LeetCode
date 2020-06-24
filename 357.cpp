#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int n,int num){
        int res=1;
        for(int i=n;i>0;i--){
            res=res*num--;
        }
        return res;
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1,1);
        for(int i=1;i<=n;i++){
            if(i==1)
                dp[i]=10;
            else{
                dp[i]=helper(i,10)-helper(i-1,9)+dp[i-1];
            }
        }
        return dp[n];
    }
};
int main(){

    Solution s;
    int res=s.countNumbersWithUniqueDigits(4);

    return 0;
}
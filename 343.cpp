#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            if(i-3>=4)  
                dp[i]=3*dp[i-3];
            else{
                if(i==6)
                    dp[i]=9;
                else if(i==2)
                    dp[i]=1;
                else{
                    dp[i]=2*(i-2);
                }
            }
        }
        return dp[n];
    }
};
int main(){



    return 0;
}
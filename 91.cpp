#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            int num1=s[i]-'0';
            if(num1>0 && num1<=9)
                dp[i]= (i==0) ? 1:dp[i-1];
            if(i>0){
                int num2=s[i-1]-'0';
                if(num2>0 && (num2*10+num1)>0 && (num2*10+num1)<=26)
                    dp[i]=dp[i]+(i==1 ? 1:dp[i-2]);
            }
            if(dp[i]==0)
                return 0;
        }
        return dp[n-1];
    }
};
int main(){



    return 0;
}
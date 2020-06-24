#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int N=s.size();
        if(N==0)
            return s;
        int ma=0;
        int a=0;int b=0;
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int i=N-1;i>=0;i--){
            for(int j=N-1;j>=i;j--){
                if(i==j)
                    dp[i][j]=1;
                else if((i==j-1) && (s[i]==s[j]))
                    dp[i][j]=1;
                else{
                    if(s[i]==s[j])
                        dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j]==1){
                    if(j-i>ma){
                        ma=j-i;
                        a=i;
                        b=j;
                    }
                }
            }
        }
        string s1=s.substr(a,ma+1);
        return s1;
    }
};
int main(){
    Solution s;
    string s1="cbbd";
    s1=s.longestPalindrome(s1);
    cout<<s1<<endl;

    return 0;
}
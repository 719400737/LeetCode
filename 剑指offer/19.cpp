#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));//dp[i][j]表示s[i-1]与p[j-1]是否匹配
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(j==0)
                    dp[0][0]=1;
                else{
                    if(p[j-1]!='*'){ //非×情况
                        if(i>0 && (s[i-1]==p[j-1] || p[j-1]=='.'))
                            dp[i][j]=dp[i-1][j-1];
                    }
                    else{ //×情况，分两种操作：不用 或 用
                        if(j>=2){ //不用
                            dp[i][j] |=dp[i][j-2];
                        }
                        if(i>0 && j>=2 && (s[i-1]==p[j-2] || p[j-2]=='.')){//用 
                            dp[i][j] |=dp[i-1][j];
                        }
                    }
                }
            }
        }
        return dp[m][n];

    }
};

int main(){
    string s="aa";
    string p="a*";
    Solution res;
    int b=res.isMatch(s,p);
    cout<<b<<endl;

    return 1;
}
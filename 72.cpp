#include<bits/stdc++.h>
using namespace std;

class Solution {
    int min3(int a,int b,int c){
        int res=a>b?b:a;
        return res>c?c:res;
    }
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        if(m==0 || n==0)
            return m==0?n:m;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    if(i==0){
                        if(word1[i]==word2[j])
                            dp[i][j]=j;
                        else{
                            if(j==0)
                                dp[i][j]=1;
                            else
                                dp[i][j]=dp[i][j-1]+1;
                        }
                    }
                    else{
                        if(word1[i]==word2[j])
                            dp[i][j]=i;
                        else
                            dp[i][j]=dp[i-1][j]+1;
                    }
                }
                else{
                    if(word1[i]==word2[j]){
                        dp[i][j]=dp[i-1][j-1];//相当于跳过操作
                    }
                    else
                    {
                        dp[i][j]=min3(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+1);
                        //3个选择分别对应插入，删除和替换
                    }
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    string s1="intention",s2="execution";
    Solution s;
    int res=s.minDistance(s1,s2);
    cout<<res<<endl;
    return 0;
}
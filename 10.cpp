#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Match(char a,char b){
        if(a=='.' || a==b)
            return true;
        return false;
    }
    bool isMatch(string s, string p) {
        if(s=="" && p=="")
            return true;
        int m=p.size(),n=s.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); //m锁定即对应第m个数
        for(int i=1;i<m+1;i++){
            if(p[i-1]=='*'){
                int j=1;
                for(;j<n+1;j++){
                    //找到*前一个字符和谁匹配 下面得到和j匹配,则*必定和j匹配，且和j后面相同的几个匹配
                    if(p[i-2]=='.'){ //前一个是.时
                       for(int t=0;t<n+1;t++){
                            if(dp[i-1][t]==1){
                                for(int z=t;z<n+1;z++)
                                    dp[i][z]=1;
                            }
                        }
                    }
                    if(dp[i-1][j]==1){
                        dp[i][j]=1;
                        for(int t=j+1;t<n+1;t++){
                            if(s[t-1] == s[t-2])
                                dp[i][t]=1;
                            else
                                break;
                        }
                    }
                }
                //if(j==n+1){ //意味着*前面的字符没有任何一个与其匹配 则i应该和*前面第二个相匹配的匹配
                    if(i==2){ //*在第2个位置且第一个位置的元素不能与任何相匹配
                        dp[i][0]=1;
                    }
                    
                    for(int t=0;t<n+1;t++){
                        if(i>1 && dp[i-2][t]==1){
                            dp[i][t]=1;
                        }  
                    }
                    
                //}
            }
            else{
                for(int j=1;j<n+1;j++){
                    if(j==1)
                        dp[1][1]=Match(p[0],s[0]);
                    if(i>1)
                        dp[i][j]=dp[i-1][j-1] & Match(p[i-1],s[j-1]);
                }   
            }
        }
        bool res=dp[m][n];
        
        return res;
  
    }
};

int main(){
    string s1="aabccbcbacabaab";   
    string s2=".*c*a*b.*a*ba*bb*";
    Solution s;
    bool res=s.isMatch(s1,s2);
    cout<<res<<endl;
    return 0;
}
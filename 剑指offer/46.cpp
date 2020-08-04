#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int translateNum(int num) {//使用动态规划的思想来解,每位可以有两种方式生成排列方式
        stringstream ss;
        ss<<num;
        string s;
        ss>>s;  //将整数转化为字符串
        vector<int> dp(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(i==0){
                dp[i]=1;
                continue;
            }
            dp[i]=dp[i-1]; //第一种,第i位与前一位数量相同
            if(i-1>=0){
                int a=s[i-1]-'0',b=s[i]-'0',num=a*10+b;
                if(num>=10 && num<=25){
                    if(i-2==-1)
                        dp[i]++;
                    else    dp[i]+=dp[i-2];//若第i位和第i-1位可以组成一个字母的话,结果在加上dp[i-2]
                }
                    
            }

        }
        return dp[s.size()-1];
    }
};

int main(){

    int a=25;
    Solution s;
    int res=s.translateNum(a);
    cout<<res<<endl;
    return 1;
}
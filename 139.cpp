#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,0);
        set<string> Set;
        for(auto i:wordDict)
            Set.insert(i);
        //i表示0-i的子字符串，j表示从j处断开，分为0-j和j+1-i两个子字符串；
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && Set.count(s.substr(j,i-j))){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
int main(){
    string s1="aaaaaaaaaaaaaaaaaaaaaa";
    vector<string> word={"aa","aaa"};
    Solution s;
    bool b=s.wordBreak(s1,word);
    cout<<b<<endl;

    return 0;
}
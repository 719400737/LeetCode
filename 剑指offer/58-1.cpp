#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string s1,res;
        stack<string> sta;
        while(ss>>s1)
            sta.push(s1);
        if(!sta.empty()){
            res+=sta.top();
            sta.pop();
        }
        while(!sta.empty()){
            string temp=" "+sta.top();
            res+=temp;
            sta.pop();
        }
        return res;
    }
};

int main(){

    string s="han ge ni hao!";
    Solution s2;
    string res=s2.reverseWords(s);
    cout<<res<<endl;
    return 1;
}
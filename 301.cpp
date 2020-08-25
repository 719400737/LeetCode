#include<bits/stdc++.h>
using namespace std;
class Solution {
    set<string> se;
    string res;
    int Len=0;
    void helper(string &s,int start,int countl,int countr,int el,int er){//分别表示左括号数，和右括号数
    //直接这样写过不了，复杂度过高
    //加入el，er表示可删除的左括号数量，和右括号数量
        if(start==s.size()){
            if(countl==countr){
                if(res.size()>Len){
                    Len=res.size();
                    se.clear();
                    se.insert(res);
                }
                else if(res.size()==Len)
                    se.insert(res);
            }
            return;
        }
        if(countr>countl || el<0 || er<0)//剪枝，右括号数量过多，直接跳出
            return;
        int i=start;
        if(s[i]=='(' || s[i]==')'){
            if(s[i]=='(')
                countl++;
            else if(s[i]==')')
                countr++;
            res+=s[i]; //保留s[i];
            helper(s,start+1,countl,countr,el,er);
            res.pop_back(); //删除s[i]
            if(s[i]=='('){
                countl--;
                el--;
            }
            else if(s[i]==')'){
                countr--;
                er--;
            }
            helper(s,start+1,countl,countr,el,er);
        }
        else{
            res+=s[i]; //保留s[i];
            helper(s,start+1,countl,countr,el,er);
            res.pop_back();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {//一个dfs问题
        int el=0,er=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                el++;
            else if(s[i]==')'){
                if(el==0)
                    er++;
                else el--;
            }
        }
        helper(s,0,0,0,el,er);
        for(auto i:se){
            cout<<i<<endl;
        }
        vector<string> r(se.begin(),se.end());
        return r;
    }
};

int main(){
    Solution s;
    string str="()a())";
    vector<string> r=s.removeInvalidParentheses(str);
    
    return 0;
}
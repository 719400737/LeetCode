#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char temp=s[i];
            if(temp=='(' || temp=='{' || temp=='[')
                st.push(temp);
            else{
                if(st.empty())
                    return false;
                if(temp==')' && st.top()=='(')    
                    st.pop();
                else if(temp=='}' && st.top()=='{')    
                    st.pop();
                else if(temp==']' && st.top()=='[')    
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};

int main(){
    string s="()";
    Solution s2;
    bool res=s2.isValid(s);
    cout<<res<<endl;
    return 0;
}
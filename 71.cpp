#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string helper(string s){
        string res;
        int m=s.size();
        if(s[m-1]!='/')
            s+='/';
        for(int i=0;i<s.size();i++){
            if(s[i]=='/'){
                res+=s[i];
                for(i=i+1;i<s.size();i++){
                    if(s[i]=='/')
                        continue;
                    else    break;
                }
            }
            res+=s[i];
        }
        return res;
    }
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;
        path=helper(path);
        string temp;
        for(int i=1;i<path.size();i++){
            if(path[i]!='/')
                temp+=path[i];
            else{            //为/时
                if(temp==".")
                    ;
                else if(temp==".."){
                    if(!st.empty())
                        st.pop();
                }
                else
                    st.push(temp);
                temp="";
            }
        }
        if(st.empty())
            res="/";
        while(!st.empty()){
            string s="/";
            s+=st.top();
            st.pop();
            s+=res;
            res=s;
        }

        return res;
    }
};

int main(){
    string s="/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e";
    Solution so;
    string s2=so.simplifyPath(s);
    cout<<s2<<endl;

    return 0;
}
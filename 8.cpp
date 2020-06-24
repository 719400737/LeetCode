#include<bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    void helper(string& s){
        int i=0;
        for(;i<s.size();i++){
            if(s[i]==' ')
                continue;
            else
                break;
        }
        s=s.substr(i);
    }
    int myAtoi(string str) {
        helper(str);
        string s=str;
        long res=0;
        bool b=1;
        if(s[0]=='+' || s[0]=='-'){
            if(s[0]=='-')
                b=0;
            s=s.substr(1);
        }
        else if(s[0]<'0' || s[0]>'9'){
            return 0;
        }
        long temp=0;
        for(int i=0;i<str.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                res=res*10+s[i]-'0';
            }
            else
                break;
            temp=res;
            if(!b)
                temp=-res;
            if(temp>INT_MAX){
                temp=INT_MAX;
                return temp;
            }
            else if(temp<INT_MIN){
                temp=INT_MIN;
                return temp;
            }
            
        }
        return temp;
    }
};

int main(){
    string s1="-91283472332";
    Solution s;
    int res=s.myAtoi(s1);
    cout<<res<<endl;
    return 0;
}
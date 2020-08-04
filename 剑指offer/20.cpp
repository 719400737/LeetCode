#include<bits/stdc++.h>
using namespace std;
class Solution {
    string helper(string s){
        int i=0,j=s.size()-1;
        for( ;i<s.size();i++){
            if(s[i]==' ')
                continue;
            else    break;
        }
        for(;j>=0;j--){
            if(s[j]==' ')
                continue;
            else    break;
        }
        s=s.substr(i,j-i+1);
        return s;
    }
public:
    bool isNumber(string s) {
        s=helper(s);
        bool E=false,D=false,N=false;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                N=true;
                continue;
            }
            else if(s[i]=='.'){
                if(E || (!N)) //出现过E获没有出现过数字
                    return false;
                D=true;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if((!N) || E)
                    return false;
                E=true;
            }
            else if(s[i]=='-' || s[i]=='+'){
                if(i==0 || s[i-1]=='e' || s[i-1]=='E')
                    continue;
                else
                    return false;
            }
            else    return false;
        } 
        return N;
    }
};

int main(){
    Solution s;
    string s2="  12e+5  ";
    bool res=s.isNumber(s2);
    cout<<res<<endl;

    return 1;
}
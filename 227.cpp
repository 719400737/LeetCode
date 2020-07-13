#include<bits/stdc++.h>
using namespace std;
class Solution {
    string prase(string s,int& index){
        string tmp;
        for(int i=index;i<s.size();i++){
            while(s[i]==' ')
                i++;
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                tmp+=s[i];
                index=i+1;
                break;
            }
            while(isdigit(s[i])){
                tmp+=s[i];
                i++;
                index=i;
            }
            break;
        }
        return tmp;
    }
public:
    int calculate(string s) {
        stack<int> s1;
        int res=0;
        int index=0;
        while(index<s.size()){
            string ss=prase(s,index);
            if(ss=="")
                break;
            if(ss=="+" || ss=="-" || ss=="*" || ss=="/"){
                string tmp=prase(s,index);
                if(ss=="*"){
                    int v2=stoi(tmp);
                    int v1=s1.top();
                    s1.pop();
                    int v=v1*v2;
                    s1.push(v);
                }
                else if(ss=="/"){
                    int v2=stoi(tmp);
                    int v1=s1.top();
                    s1.pop();
                    int v=v1/v2;
                    s1.push(v);
                }
                else if(ss=="+"){
                    int v=stoi(tmp);
                    s1.push(v);
                }
                else{
                    int v=stoi(tmp);
                    s1.push(-v);
                }
            }
            else{
                int v=stoi(ss);
                s1.push(v);                
            }
        }
        while(!s1.empty()){
            res+=s1.top();
            s1.pop();
        }
        return res;
    }
};

int main(){
    Solution s;
    string s2="  3+ 5 /2* 5-2 ";
    int res=s.calculate(s2);
    cout<<res<<endl;
    return 0;
}
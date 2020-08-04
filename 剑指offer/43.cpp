#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDigitOne(int n) {
        string s;
        stringstream ss;
        ss<<n;
        ss>>s;
        int res=0,cur=0,pre=0,last=0;
        for(int i=0;i<s.size();i++){
            cur=s[i]-'0';
            if(i==0)
                pre=0;
            else{
                string p=s.substr(0,i);
                pre=stoi(p);
            }    
            if(i==s.size()-1)
                last=0;
            else{
                string l=s.substr(i+1,s.size()-i-1);
                last=stoi(l);
            }
            int digit=pow(10,s.size()-i-1);
            if(cur==0)
                res+=pre*digit;
            else if(cur==1)
                res+=pre*digit+last+1;
            else
                res+=(pre+1)*digit;
        }
        return res;
    }
};

int main(){

    int n;
    Solution s;
    int res=0;
    cin>>n;
    res=s.countDigitOne(n);
    cout<<res<<endl;
    return 1;
}
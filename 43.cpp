#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string add(string s1,string s2){
        string res;
        int he=0,jin=0;
        int i=s1.size()-1,j=s2.size()-1;
        if(i>j){
            string tmp;
            tmp.append(i-j,'0');
            tmp+=s2;
            s2=tmp;
            j=i;    
        }
        else{
            string tmp;
            tmp.append(j-i,'0');
            tmp+=s1;
            s1=tmp;
            i=j;
        }
        while(i>=0 && j>=0){
            he=((s1[i]-'0')+(s2[j]-'0')+jin)%10;
            jin=((s1[i]-'0')+(s2[j]-'0')+jin)/10;
            res+=he+'0';
            i--;
            j--;
        }
        if(jin)
            res+='0'+jin;
        reverse(res.begin(),res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        string res;
        int jin=0,ji=0;
        if((num1.size()==1 && num1[0]=='0') || (num2.size()==1 && num2[0]=='0') )
            {res+='0';
            return res;}
        for(int j=num2.size()-1;j>=0;j--){
            string tmp;
            tmp.append(num2.size()-1-j,'0');
            jin=0,ji=0;
            for(int i=num1.size()-1;i>=0;i--){
                int t1=num1[i]-'0';
                //假定num2就一个树
                int t2=num2[j]-'0';
                ji=(t1*t2+jin)%10;
                tmp+='0'+ji;
                jin=(t1*t2+jin)/10;
            }
            if(jin)
                tmp+='0'+jin;
            reverse(tmp.begin(),tmp.end());
            cout<<tmp<<endl;
            res=add(res,tmp);
            cout<<res<<endl;
        }
        return res;
    }
};

int main(){
    string s1="123",s2="12";
    Solution s;
    string res;
    res=s.multiply(s1,s2);
    // res=s.add(s1,s2);
    // cout<<res<<endl;
    return 0;
}
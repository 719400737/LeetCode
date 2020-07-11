#include<bits/stdc++.h>
using namespace std;
class Solution {
    string helper(string s){
        string res;
        int num=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                while(s[i]>='0' && s[i]<='9'){
                    num=10*num+s[i]-'0';
                    i++;
                }
                int j=i;
                while(s[j]!=']')
                    j++;
                string temp=s.substr(i+1,j-i-1);
                for(int i=0;i<num;i++)
                    res+=temp;
                i=j;
            }
            else    res+=s[i];
        }
        return res;
    }
public:
    string decodeString(string s) {
        
        string res;
        
        int j=0;
        while(j<s.size() && s[j]!=']'){
            j++;
        }
        if(j==s.size()){
            res=s;
            return res;
        }
        int k=j;
        while(k>=0 && s[k]!='[')
            k--;
        if(s[k]=='['){
            k--;
            while(k>=0 && s[k]>='0' && s[k]<='9')
                k--;
        }
        string temp=s.substr(k+1,j-k); //第一个【】的位置
        string temp1=s.substr(0,k+1);
        string temp2=s.substr(j+1,s.size()-j-1);
        string temp3=helper(temp);
        string temp4=temp1+temp3+temp2;
        res=decodeString(temp4);
        return res;
    }
};

int main(){
    string s="2[a10[leet]]";
    Solution s1;
    string res=s1.decodeString(s);
    cout<<res<<endl;

    return 0;
}
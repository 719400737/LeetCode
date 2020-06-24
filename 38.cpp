#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    string countAndSay(int n) {
        string s="1";
        string tmp;
        for(int i=1;i<n;i++){
            tmp="";
            int num=1;
            for(int j=0;j<s.size();j++){

                if(j>0 && s[j]==s[j-1]){
                    num++;
                }
                else{
                    if(j!=0){
                        tmp.append(1,num+'0');
                        tmp.append(1,s[j-1]);
                        num=1;
                    }
                }
                if(j==s.size()-1){   
                    tmp.append(1,num+'0');
                    tmp.append(1,s[j]);   
                }

            }
            s=tmp;
        }
        return s;
    }
};

int main(){
    Solution s;
    string res;
    res=s.countAndSay(6);
    cout<<res<<endl;

    return 0;
}
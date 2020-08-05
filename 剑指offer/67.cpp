#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        long long res=0;
        bool flag=false; //引入辅助变量，来进行判断，遇到空格或符号时，进行继续遍历还是跳出来
        bool num=false;
        bool fuhao=true;
        for(int i=0;i<str.size();i++){
            if(str[i]==' '){
                if(flag || num)
                    break;
                continue;
            }
            else if(isdigit(str[i])){
                num=true;
                res=res*10+str[i]-'0';
                if(res>INT_MAX)
                    break;
            }
            else if(str[i]=='+' || str[i]=='-'){
                if(flag || num)
                    break;
                flag=true;
                if(str[i]=='-')
                    fuhao=false;
            }
            else
                break;
            
        }
        if(!fuhao)
            res*=-1;
        if(res>INT_MAX)
            res=INT_MAX;
        else if(res<INT_MIN)
            res=INT_MIN;
        return res;
    }
};

int main(){
    string s="20000000000000000000";
    Solution s1;
    int res=s1.strToInt(s);
    cout<<res<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool res=false;
    int count=0;
    string add(string& a,string& b){
        int n1=a.size()-1;
        int n2=b.size()-1;
        int carry=0;
        string ans;
        while(n1>=0||n2>=0||carry>0){
            int t1=n1>=0?a[n1--]-'0':0;
            int t2=n2>=0?b[n2--]-'0':0;
            ans+=(t1+t2+carry)%10+'0';
            carry=(t1+t2+carry)>=10?1:0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void helper(string& num,int start,string prenum1,string prenum2){
        if(count>=3 && start==num.size()){
            res=true;
            return;
        }
        int i=start;
        if(num[i]=='0'){
            string now="0";
            if(count<2 || now == add(prenum1,prenum2)){
                count++;
                helper(num,i+1,prenum2,now);
                count--;
            };

        }
        else{
            for(int j=start+1;j<=num.size();j++){
                string now;
                now=num.substr(i,j-i);
                if(count<2 || now == add(prenum1,prenum2)){
                    count++;
                    helper(num,j,prenum2,now);
                    count--;
                }
                else
                    continue;
            }
        }
    }
public:
    bool isAdditiveNumber(string num) {
        helper(num,0,"","");
        return res;
    }
};

int main(){
    string s="101222";
    Solution so;
    bool res=so.isAdditiveNumber(s);
    cout<<res<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        /*
        string res;
        int val=k;
        int m=num.size();
        if(k>=m){
            res+="0";
            return res;
        }
        for(int i=0;i<m;i++){
            if(i==0)
                continue;
            if(num[i-1]<=num[i])
                continue;
            else{
                for(int j=i-1;j>=0;j--){
                    if(num[j]!='a' && num[j]>num[i]){
                        num[j]='a';
                        k--;
                    }
                    if(k==0)
                    break;
                }
            }
            if(k==0)
                break;
        }
        for(int i=0;i<m;i++){
            if(num[i]!='a')
                res+=num[i];
        }
        res=res.substr(0,m-val);
        int i=0;
        while(res[i]=='0')
            i++;
        res=res.substr(i);
        if(res.size()==0)
            res="0";
        return res;
        */
        //用栈来实现
        stack<char> st;
        string res;
        int val=k;
        int m=num.size();
        if(k>=m){
            res+="0";
            return res;
        }
        for(int i=0;i<m;i++){
            while(!st.empty() && st.top()>num[i]){
                st.pop();
                k--;
                if(k==0){
                    while(i<m)
                        st.push(num[i++]);
                    break;
                }
                    
            }
            st.push(num[i]);
        }
        while(!st.empty()){
            char c=st.top();
            res+=c;
            st.pop();
        }
        reverse(res.begin(),res.end());
        res=res.substr(0,m-val);
        int i=0;
        while(res[i]=='0')
            i++;
        res=res.substr(i);
        if(res.size()==0)
            res="0";
        return res;
    }
};
int main(){
    Solution s;
    string temp="10100";
    string res=s.removeKdigits(temp,3);
    cout<<res<<endl;

    return 0;
}
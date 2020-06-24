#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
       if(s.size()==0)
            return s;
        int n=0;
       if(numRows==1)
            n=1;
       else n=2*numRows-2;//n个一次循环
       int len=s.size();
       //吧s补充为n的倍数
       int buchong=len%n;
       s.append(n-buchong,'!');
       string res;
       for(int i=0;i<numRows;i++){
            for(int j=0;j<len/n+1;j++){
                if(i==0 || i==numRows-1){
                    if(s[j*n+i]!='!'){
                        res.push_back(s[j*n+i]);
                    } 
                }
                else{
                    if(s[j*n+i]!='!')
                        res.push_back(s[j*n+i]);
                    if(s[j*n+n-i]!='!')   
                        res.push_back(s[j*n+n-i]);
                }
            }       
       }
        return res;
    }
};

int main(){
    Solution s;
    string s1="LEETCODEISHIRING";
    int num=3;
    string res;
    res=s.convert(s1,num);
    cout<<res<<endl;
    return 0;
}
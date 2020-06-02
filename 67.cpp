#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string s1, string s2) {
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
            he=((s1[i]-'0')+(s2[j]-'0')+jin)%2;
            jin=((s1[i]-'0')+(s2[j]-'0')+jin)/2;
            res+=he+'0';
            i--;
            j--;
        }
        if(jin)
            res+='0'+jin;
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num1,num2;
        int i=0,j=0;
        while(i<version1.size()||j<version2.size()){//分别取出了.之前的部分进行比较
            string r1,r2;
            if(i>=version1.size())
                num1=0;
            else{
                while(i<version1.size() && version1[i]!='.'){
                    r1+=version1[i];
                    i++;   
                }
                num1=stoi(r1);
                
                i++;
            }
            if(j>=version2.size())
                num2=0;
            else{
                while(j<version2.size() && version2[j]!='.'){
                    r2+=version2[j];
                    j++;
                }
                num2=stoi(r2);
                j++;
            }
            if(num1<num2)
                return -1;
            else if(num1>num2)
                return 1;
        }
        return 0;
    }
};
int main(){
    string s1="1",s2="0";
    Solution s;
    int res=s.compareVersion(s1,s2);
    cout<<res<<endl;
    return 0;
}
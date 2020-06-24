#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string tmp;
        int res=0;
        while(ss>>tmp){
            res=tmp.size();
        }               
        return res;
    }
};

int main(){
    string s1="hello world";
    Solution s;
    int res=s.lengthOfLastWord(s1);
    cout<<res<<endl;

    return 0;
}
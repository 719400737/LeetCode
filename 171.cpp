#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            int num=s[i]-'A'+1;
            res=res*26+num;
        }
        return res;
    }
};

int main(){
    string s1="ZY";
    Solution s;
    int res=s.titleToNumber(s1);
    cout<<res<<endl;

    return 0;
}
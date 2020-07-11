#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        int shang,yu;
        string res;
        shang = n;
        while(shang){
            yu=shang%26;
            shang=shang/26;
            if(yu==0){
                shang--;
                res+='Z';
            }
            else
                res+='A'+yu-1;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){

    int n=28;
    Solution s;
    string res=s.convertToTitle(n);
    cout<<res<<endl;
    return 0;
}
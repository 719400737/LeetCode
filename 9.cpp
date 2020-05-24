#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string huiwen;
        huiwen=to_string(x);
        int s=huiwen.size();
        for(int i=0;i<s/2;i++){
            if(huiwen[i]==huiwen[s-i-1])
                continue;
            else
                return false;
        }
        return true;
    }
};

int main(){


    return 0;
}
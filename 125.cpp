#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(!isalnum(s[i]) || !isalnum(s[j]))
            {
                if(!isalnum(s[i]))
                    i++;
                if(!isalnum(s[j]))
                    j--;
                continue;
            }
            else{
                if(tolower(s[i])!=tolower(s[j]))
                    return false;
                i++;
                j--;
            }

        }
        return true;
    }
};

int main(){
    Solution s;

    return 0;
}
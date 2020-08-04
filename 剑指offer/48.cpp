#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> se;
        int pre=0,last=0;
        int res=0;
        while(pre!=s.size()){
            if(!se.count(s[pre])){
                se.insert(s[pre]);
                res=max(res,pre-last+1);
                pre++;
            }
            else{
                se.erase(s[last]);
                last++;
            }
        }
        return res;
    }
};

int main(){



    return 1;
}
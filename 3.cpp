#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        unordered_map<char,int> m;
        int res=0;
        while(right<s.size()){
            m[s[right]]++;
            while(m[s[right]]>1){
                m[s[left]]--;
                left++;
            }
            res=max(res,right-left+1);
            right++;
        }
        return res;
    }
};

int main(){
    string s="dvdf";
    Solution s1;
    int res=s1.lengthOfLongestSubstring(s);
    cout<<res<<endl;
    return 0;
}
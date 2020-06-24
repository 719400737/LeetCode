#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        for(auto i:t){
            need[i]++;
        }
        string res;
        int vaild=0;//满足条件的字符个数
        int left=0,right=0,min_num=INT_MAX;
        while(right<s.size()){
            char c=s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(need[c]==window[c])
                    vaild++;
            }
            while(vaild==need.size()){
                int len=right-left;
                if(len<min_num){
                    min_num=len;
                    res=s.substr(left,len);
                }
                char d=s[left];
                left++;
                if(need.count(d)){  
                    if(need[d]==window[d])
                        vaild--;
                    window[d]--;
                }
            }

        }
        return res;
    }
};

int main(){
    string s1="ADOBECODEBANC",s2="ABCA";
    Solution s;
    string res=s.minWindow(s1,s2);
    cout<<res<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        if(haystack.size()==0 && needle.size()!=0)
            return -1;
        unordered_map<char,int> m;
        unordered_map<char,int> h;
        for(int i=0;i<needle.size();i++){
            m[needle[i]]++;
        }
        int left=0,right=0;
        int match=0;
        while(right<haystack.size()){
            char c1=haystack[right];
            if(m.count(c1)){
                h[c1]++;
                if(h[c1]==m[c1])
                    match++;
            }
            right++;
            while(match==m.size()){ 
                if(right-left==needle.size()){
                    int i=left,j=0;
                    for(;i<right;i++,j++){
                        if(haystack[i]==needle[j])
                            continue;
                        else
                            break;
                    }
                    if(i==right)
                        return left;   
                }
                char c2=haystack[left];
                if(m.count(c2)){
                    h[c2]--;
                    if(h[c2]<m[c2])
                        match--;
                }    
                left++;
            }
        }
        return -1;
    }
};

int main(){
    string s1="mississippi";
    string s2="pi";
    Solution s;
    int res=0;
    res=s.strStr(s1,s2);
    cout<<res<<endl;
    return 0;
}
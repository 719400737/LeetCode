#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len=s.size();
        vector<int> vec(256,0); //建立数组，表示字符的使用情况
        unordered_map<char,char> m; //表示字符的映射关系，两个相同字符必须映射到同一个字符
        for(int i=0;i<len;i++){
            if(m.count(s[i])){
                if(m[s[i]]!=t[i])
                    return false;
                else    continue;
            }
            if(vec[t[i]-'\0']==0){ //‘\0’表示ascii码为0的字符
                m[s[i]]=t[i];
                vec[t[i]-'\0']=1;
            }
            else    return false;
        }
        return true;

    }
};

int main(){


    return 0;
}
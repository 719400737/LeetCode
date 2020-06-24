#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size()==0)
            return res;
        for(int i=0;i<strs[0].size();i++){
            char c=strs[0][i];
            int j=1;
            for(;j<strs.size();j++){
                if (c==strs[j][i])
                    continue;
                else
                    break;
            }
            if(j==strs.size())
                res.append(1,c);
            else    return res;
        }
        return res;       
    }
};

int main(){


    return 0;
}
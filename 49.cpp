#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,int> m;
        for(int i=0;i<strs.size();i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            if(m.count(tmp)==0){//判断是否在
                vector<string> vec;
                vec.push_back(strs[i]);
                int index=res.size();
                m[tmp]=index;
                res.push_back(vec);
            }
            else{
                res[m[tmp]].push_back(strs[i]);
            }
        }
        return res;
    }
};

int main(){


    return 0;
}
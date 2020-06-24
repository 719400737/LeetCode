#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> res;
    unordered_map<char,string> m{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    string current;
public:
    void backtrack(string s,int start){
        if(start==s.size()){
            res.push_back(current);
            return;
        }
        for(int i=0;i<m[s[start]].size();i++){
            current.push_back(m[s[start]][i]);
            backtrack(s,start+1);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return res;
        backtrack(digits,0);
        return res;
        
    }
};
int main(){



    return 0;
}
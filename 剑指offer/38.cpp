#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> res;
    string path;
    vector<int> vec;
    void helper(string s){
        if(path.size()==s.size()){
            res.push_back(path);
            return;
        }
        unordered_set<char> se;
        for(int i=0;i<s.size();i++){
            if(vec[i]==1 || se.count(s[i]))
                continue;
            path+=s[i];
            vec[i]=1;
            se.insert(s[i]);
            helper(s);
            path.pop_back();
            vec[i]=0;
        }
    }
public:
    vector<string> permutation(string s) {
        int m=s.size();
        vector<int> v(m,0);
        this->vec=v;
        helper(s);
        return res;
    }
};

int main(){

    Solution s;
    vector<string> res=s.permutation("aac");
    for(auto i:res)
        cout<<i<<endl;
    return 1;
}
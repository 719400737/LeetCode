#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start,int k,vector<int>& tag){//1-n个数中，k个数的组合
        if(path.size()==k){
            res.push_back(path);
            return;
        }
        for(int i=start;i<=tag.size();i++){
            if(tag[i])
                continue;
            path.push_back(i+1);
            tag[i]=1;
            DFS(i,k,tag);
            path.pop_back();
            tag[i]=0;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tag(n,0);
        DFS(0,k,tag);
        return res;
    }
};

int main(){

    int n=4,k=2;
    Solution s;
    s.combine(4,2);

    return 0;
}
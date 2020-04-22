#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<int> vec;
public:
    void DFS(int start,int n,vector<int>& tag){
        if(path.size()==n){
            res.push_back(path);
            return;
        }
        for(int i=start;i<n;i++){
            if(tag[i]==1)
                continue;
            path.push_back(vec[i]);
            tag[i]=1;
            DFS(start,n,tag);
            path.pop_back();
            tag[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vec=nums;
        int n=vec.size();
        vector<int> tag(n,0);
        DFS(0,n,tag);
        return res;
    }
};
int main(){



    return 0;
}
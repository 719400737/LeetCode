#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<int> vec;
    bool b=false;
public:
    void DFS(int start,int n,vector<int>& tag){
        if(path.size()==n){
            res.push_back(path);
            return;
        }
        for(int i=start;i<n;i++){
            if(i>0 && vec[i]==vec[i-1] &b)
                continue;
            b=false;
            if(tag[i]==1)
                continue;
            path.push_back(vec[i]);
            tag[i]=1;
            DFS(start,n,tag);
            path.pop_back();
            b=true;
            tag[i]=0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vec=nums;
        sort(vec.begin(),vec.end());
        int n=vec.size();
        vector<int> tag(n,0);
        DFS(0,n,tag);
        return res;
    }
};
int main(){
    vector<int> vec={1,1,2,2};
    Solution s;
    s.permuteUnique(vec);


    return 0;
}
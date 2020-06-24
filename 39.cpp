#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<int> vec;
    int sum=0;
public:
    void DFS(int start,int target){
        if(sum==target){
            res.push_back(path);
            return;
        }
        for(int i=start;i<vec.size();i++){
            if(sum+vec[i]>target)
                break;
            path.push_back(vec[i]);
            sum+=vec[i];
            DFS(i,target);
            path.pop_back();
            sum-=vec[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vec=candidates;
        sort(vec.begin(),vec.end());
        DFS(0,target);
        return res;
    }
};
int main(){



    return 0;
}
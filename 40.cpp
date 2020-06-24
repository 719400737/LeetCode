#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<int> vec;
    int sum=0;
    bool b=false;
public:
    void DFS(int start,int target){
        if(sum==target){
            res.push_back(path);
            return;
        }
        for(int i=start;i<vec.size();i++){
            if(i>0 && vec[i]==vec[i-1] & b)
                continue;
            if(sum+vec[i]>target)
                break;
            path.push_back(vec[i]);
            b=false;
            sum+=vec[i];
            DFS(i+1,target);
            path.pop_back();
            b=true;
            sum-=vec[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vec=candidates;
        sort(vec.begin(),vec.end());
        DFS(0,target);
        return res;
    }
};
int main(){



    return 0;
}
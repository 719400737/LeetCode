#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> candidates;
public:
    void dfs(int start,int target){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size()&&target-candidates[i]>=0;i++){
            if(i>start&&candidates[i]==candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            dfs(i,target-candidates[i]);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        this->candidates=candidates;
        dfs(0,target);
        return res;
    }
};
int main(){



    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<int> nums;
public:
    void DFS(int start,vector<int>& tag){//1-n个数中，k个数的组合

        res.push_back(path);       
        for(int i=start;i<tag.size();i++){
            if(tag[i])
                continue;
            path.push_back(nums[i]);
            tag[i]=1;
            DFS(i,tag);
            path.pop_back();
            tag[i]=0;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> tag(n,0);
        this->nums=nums;
        DFS(0,tag);
        return res;
    }
};

int main(){
    vector<int> vec={1,2,3};
    Solution s;
    s.subsets(vec);


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<int> nums;
    bool back=false;
public:
    void DFS(int start,vector<int>& tag){//1-n个数中，k个数的组合

        res.push_back(path);       
        for(int i=start;i<tag.size();i++){
            if(tag[i] || (back && i>0 && nums[i]==nums[i-1]))
                continue;
            back=false;
            path.push_back(nums[i]);
            tag[i]=1;
            DFS(i,tag);
            path.pop_back();
            tag[i]=0;
            back=true;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> tag(n,0);
        this->nums=nums;
        DFS(0,tag);
        return res;
    }
};
int main(){



    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
vector<vector<int>> res;
vector<int> path;
vector<int> nums;
vector<int> num_tag;

public:
    void DFS(int begin){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            if(num_tag[i]==1)
                continue;
            path.push_back(nums[i]);
            num_tag[i]=1;
            DFS(0);
            path.pop_back();
            num_tag[i]=0;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums=nums;
        for(int i=0;i<nums.size();i++){
            num_tag.push_back(0);
        }
        DFS(0);
        return res;
    }
};
int main(){



    return 0;
}
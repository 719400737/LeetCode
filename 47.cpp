#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
vector<vector<int>> res;
vector<int> path;
vector<int> nums;
vector<int> num_tag;
public:
    void DFS(int start){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(num_tag[i]==1)
                continue;
            if(i>start&&nums[i]==nums[i-1]&&num_tag[i-1]==0)
                continue;
            path.push_back(nums[i]);
            num_tag[i]=1;
            DFS(0);
            num_tag[i]=0;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        this->nums=nums;
        for(int i=0;i<nums.size();i++){
            num_tag.push_back(0);
        }
        DFS(0);
        return res;
    }
};
int main(){
    vector<int> vec={3,3,0,3};
    Solution s;
    vector<vector<int>> res;
    res=s.permuteUnique(vec);
    for(auto i:res){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}
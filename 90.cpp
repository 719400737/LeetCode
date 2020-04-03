#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> tag;
    vector<int> nums;
public:
    void DFS(int start){
        for(int i=start;i<nums.size();i++){
            if(tag[i]==1)//需要去掉一些不满足的情况
                continue;
            if(i>0&&nums[i]==nums[i-1]&&tag[i-1]==0)
                continue;
            path.push_back(nums[i]);
            res.push_back(path);
            tag[i]=1;
            
            DFS(i);

            path.pop_back();
            tag[i]=0;
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        this->nums=nums;
        for(int i=0;i<nums.size();i++){
            tag.push_back(0);
        }
        DFS(0);
        vector<int> a;
        res.push_back(a);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec={4,4,4,1,4};
    vector<vector<int>> res;
    res=s.subsetsWithDup(vec);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
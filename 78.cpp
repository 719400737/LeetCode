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
            path.push_back(nums[i]);
            res.push_back(path);
            tag[i]=1;
            
            DFS(i);

            path.pop_back();
            tag[i]=0;
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums=nums;
        sort(nums.begin(),nums.end());
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
    vector<int> vec={1,2,3};
    vector<vector<int>> res;
    res=s.subsets(vec);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> path;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        bool back2=false;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1] && back2){
                m[nums[i]]--;
                continue;
            }
            int sum2=-nums[i];//找到两个数和为sum2
            m[nums[i]]--;
            bool back=false;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==nums[j-1] && back){
                    continue;
                } 
                m[nums[j]]--;
                if(m.count(sum2-nums[j]) && m[sum2-nums[j]]>0 && nums[j]<=(sum2-nums[j])){
                    res.push_back({nums[i],nums[j],sum2-nums[j]});
                    cout<<nums[i]<<" "<<nums[j]<<" "<<sum2-nums[j]<<endl;
                }
                m[nums[j]]++;
                back=true;
            }
            back2=true;
        }
        return res;
    }
};
*/

class Solution {//双指针 数组问题一般是首尾双指针
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int sum2=-nums[i];
            int first=i+1;
            int second=nums.size()-1;
            while(first<second){
                if(nums[first]+nums[second]==sum2){
                    res.push_back({nums[i],nums[first],nums[second]});
                    //cout<<nums[i]<<" "<<nums[first]<<" "<<nums[second]<<endl;
                    first++;
                    while(nums[first]==nums[first-1] && first<second)
                        first++;
                }
                else if(nums[first]+nums[second]<sum2){
                    first++;
                }
                else{
                    second--;
                    
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec={-1,0,1,2,-1,-4};
    s.threeSum(vec);

    return 0;
}
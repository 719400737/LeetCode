#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> vec=nums;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==target){
                break;
            }
            else if(nums[l]+nums[r]<target)
                l++;
            else
                r--;
        }
        for(int i=0;i<nums.size();i++){
            if(vec[i]==nums[l] || vec[i]==nums[r])
                res.push_back(i);
            if(res.size()==2)
                break;
        }
        
        return res;
    }
};
int main(){


    return 0;
}
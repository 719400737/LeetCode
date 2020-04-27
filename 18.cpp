#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int sum2=target-(nums[i]+nums[j]);
                int first=j+1;
                int second=nums.size()-1;
                while (first<second)
                {
                    if(nums[first]+nums[second]==sum2){
                        res.push_back({nums[i],nums[j],nums[first],nums[second]});
                        cout<<nums[i]<<" "<<nums[j]<<" "<<nums[first]<<" "<<nums[second]<<endl;
                        first++;
                        while(nums[first]==nums[first-1] && first<second)
                            first++;
                    }

                    else if(nums[first]+nums[second]<sum2)
                        first++;
                    else
                        second--;
                }
                
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec={0,0,0,0,0};
    s.fourSum(vec,0);

    return 0;
}
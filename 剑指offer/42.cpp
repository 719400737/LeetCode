#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        for(int i=0;i<nums.size();i++){
            if(i==0)
                continue;
            nums[i]=max(nums[i],nums[i-1]+nums[i]);
            res=max(res,nums[i]);
        }
        return res;
    }
};

int main(){



    return 1;
}
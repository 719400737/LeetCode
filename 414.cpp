#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int res=1;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]!=nums[i-1])
                res++;
            if(res==3)
                return nums[i];
        }
        return nums[0];
        
        
    }
};

int main(){


    return 0;
}
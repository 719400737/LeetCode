#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        for(int i=0;i<nums.size()-1;i++){
             if(nums[i]>nums[i+1])
                return i;
        }
        return nums.size()-1;
    }
};

int main(){


    return 0;
}
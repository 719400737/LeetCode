#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int pre=0,last=nums.size()-1;
        int mid;
        while(pre<last){
            mid=(pre+last)/2;
            if(nums[mid]==mid)
                pre=mid+1;
            else
                last=mid; 
        }
        if(nums[pre]==pre)
            pre++;
        return pre;
    }
};

int main(){



    return 1;
}
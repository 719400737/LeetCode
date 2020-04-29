#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]==nums[i+1])
//                 return nums[i];
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0,slow=0;
        while(1){
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(fast==slow){
                slow=0;
                while(nums[fast]!=nums[slow]){
                    fast=nums[fast];
                    slow=nums[slow];
                }
                return nums[fast];
            }
        }
        return nums[fast];
    }
};

int main(){


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left=0,right=0;
        int res=INT_MAX;
        int sum=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>=s){
                res=min(res,right-left+1);
                sum-=nums[left++];
            }            
            right++;
        }
        if(res==INT_MAX)
            return 0;
        return res;
    }
};

int main(){


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int m=(l+r)/2;
            if(nums[m]<nums[r])
                r=m;
            else
                l=m+1;
        }
        return nums[l];

    }
};

int main(){


    return 0;
}
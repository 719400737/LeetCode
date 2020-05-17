#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<r)
        {              
            int m=(l+r)/2;
            if(nums[m]>m)
                r=m;
            else
                l=m+1;
        }
        if(nums[l]==l)
            return l+1;
        return l;
    }
};

int main(){


    return 0;
}
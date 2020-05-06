#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int m=0;
        while (l<r)
        {
            m=(l+r)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m]<target)
                l=m+1;
            else
                r=m-1;
        }
        m=(l+r)/2;
        if(nums[m]<target)
            return m+1;
        else
            return m;
   
    }
};

int main(){

    vector<int> vec={1,3,5,6};
    int a=0;
    Solution s;
    s.searchInsert(vec,a);
    return 0;
}
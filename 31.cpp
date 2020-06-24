#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        for(i=n-1;i>=1;i--){
            if(nums[i]<=nums[i-1])
                continue;
            else break;
        }
        //i大于i-1
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(j=n-1;j>i-1;j--){
            if(nums[j]<=nums[i-1])
                continue;
            else break;
        }
        int temp=nums[j];
        nums[j]=nums[i-1];
        nums[i-1]=temp;
        vector<int>::iterator it=nums.begin();
        it=it+i;
        reverse(it,nums.end());

    }
};

int main(){
    vector<int> nums={3,2,1};
    Solution s;
    s.nextPermutation(nums);
    for(auto i:nums)
        cout<<i<<" ";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        if(right<0)
            return -1;
        int mid=0;
        while(left<right){
            mid=(right+left)/2;
            if(nums[mid]==target)
                return mid;
            bool a=nums[mid]>=nums[left] && nums[mid]<=nums[right];
            bool b=nums[mid]>=nums[left] && nums[mid]>=nums[right];
            bool c=nums[mid]<=nums[left] && nums[mid]<=nums[right];
            if(a){
                if(nums[mid]>target)
                    right=mid-1;
                else
                    left=mid+1;
            }
            else if(b){
                if(nums[mid]>=target && nums[left]<=target)
                    right=mid-1;
                else
                    left=mid+1;
            }
            else{
                if(nums[mid]<=target && nums[right]>=target)
                    left=mid+1;
                else
                    right=mid-1;
            }
            
            
        }
        mid=(right+left)/2;
        if(nums[mid]==target)
            return mid;
        else
            return -1;
        
    }
};

int main(){
    vector<int> vec={3,5,1};
    int a=3;
    Solution s;
    int res=s.search(vec,a);
    cout<<res<<endl;
    return 0;
}
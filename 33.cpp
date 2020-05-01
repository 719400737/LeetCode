#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {.sh
        int left=0,right=nums.size()-1;
        int mid=(left+right)/2;
        while(left<=right && nums[mid]!=target){
            if(nums[mid]>target)
                right=mid-1;
            else
                left=mid+1;
            mid=(right+left)/2;
        }
        if(nums[mid]==target)
            return mid;
        else{
            return 0;
        }
    }
};

int main(){
    vector<int> vec={0,1,2,3,5,7};
    int a=5;
    Solution s;
    int res=s.search(vec,a);
    cout<<res<<endl;
    return 0;
}
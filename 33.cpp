#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
            int l=0,h=nums.size()-1;
        while(l<h){
            int mid=(h+l)/2;
            if((nums[0]>nums[mid])^(nums[0]>target)^(target>nums[mid]))
                l=mid+1;
            else
                h=mid;
        }
        return l==h&&nums[l]==target?l:-1;
}
int main(){

    vector<int>vec={4,5,6,7,1,2};
    int a=search( vec, 2);
    cout<<a<<endl;

    return 0;
}
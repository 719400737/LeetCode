#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int i=0;
        while(i<=right){
            if(nums[i]==0){
                int temp=nums[left];
                nums[left]=nums[i];
                nums[i]=temp;
                left++;
                i++;
            }
            else if(nums[i]==2){
                int temp=nums[right];
                nums[right]=nums[i];
                nums[i]=temp;
                right--;
            }
            else{
                i++;
            }
        }
    }
};

int main(){


    return 0;
}
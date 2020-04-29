#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first=0,second=0;
        while(second<nums.size()){
            if(nums[second]!=0){
                nums[first++]=nums[second++];
            }
            else
                second++;
        }
        while(first<nums.size()){
            nums[first++]=0;
        }
    }
};

int main(){


    return 0;
}
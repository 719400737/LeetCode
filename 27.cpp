#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int first=0,second=0;
        while(second<nums.size()){
            if(nums[second]==val)
                second++;
            else{
                nums[first++]=nums[second++];
            }
        }
        return first+1;
    }
};

int main(){


    return 0;
}
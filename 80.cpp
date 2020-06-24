#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        int first=0,second=0;
        while(first<nums.size()){
            if(count>1 && nums[first]==nums[first-1]){
                first++;
                continue;
            }
            if(first>0 && nums[first]==nums[first-1]){
                nums[second++]=nums[first];
                count++;
                continue;
            }
            count=1;
            nums[second++]=nums[first++];
        }
        return second;
    }
};

int main(){


    return 0;
}
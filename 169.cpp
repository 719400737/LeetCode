#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            int n=m[nums[i]];
            if(n>nums.size()/2)
                return nums[i];
        }
        return 0;
    }
};

int main(){


    return 0;
}
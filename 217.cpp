#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> s;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i]))
                return true;
            s[nums[i]]++;
        }
        return false;
    }
};

int main(){


    return 0;
}
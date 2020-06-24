#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        int res=0;
        int i=0;
        while(i<nums.size()){
            if(m.count(nums[i])){
                vector<int>::iterator it=nums.begin()+i;
                nums.erase(it);
                continue;
            }
            m[nums[i]]++;
            res++;
            i++;
        }
        return res;
    }
};
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int left=0,right=0;
        while(right<nums.size()){
            if(nums[right]==nums[left])
                right++;
            else
                nums[++left]=nums[right++];
        }
        return left+1;
    }
};
int main(){


    return 0;
}
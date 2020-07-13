#include<bits/stdc++.h>
using namespace std;

/* 使用map解答，可以通过，但是使用了额外的内存空间
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> res;
        int mod=nums.size()/3;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second>mod)
                res.push_back(i.first);
        }
        return res;

    }
};*/
class Solution { //采用摩尔投票法
//本文找票数>1/3的，需要两个候选人，候选人的票数进行抵消最后找到存在票数的两个候选人。
//在进行一次遍历，找到这两个候选人是否满足条件。
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if(nums.size()==0)
            return res;
        pair<int,int> p1=make_pair(nums[0],0);
        pair<int,int> p2=p1;
        for(int i=0;i<nums.size();i++){
            if(p1.first==nums[i]){
                p1.second++;
                continue;
            }
            if(p2.first==nums[i]){
                p2.second++;
                continue;
            }
            if(p1.second==0){
                p1.first=nums[i];
                p1.second=1;
                continue;
            }
            if(p2.second==0){
                p2.first=nums[i];
                p2.second=1;
                continue;
            }
            p1.second--;
            p2.second--;
        }
        int res1=0,res2=0;
        for(auto i:nums){
            if(p1.first==i)
                res1++;
            else if(p2.first==i)
                res2++;
        }
        if(res1>nums.size()/3)
            res.push_back(p1.first);
        if(res2>nums.size()/3)
            res.push_back(p2.first);
        return res;
    }
};


int main(){


    return 0;
}
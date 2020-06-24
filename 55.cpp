#include<bits/stdc++.h>
using namespace std;
//贪心算法 每次找到能跳的最远距离
//当遍历到的i>当前能跳最远时，表示不能完成目的
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res=0,n=nums.size();//i表示目前可以到达的最远距离
        for(int i=0;i<n;i++){
            if(res>=n)
                return true;
            if(i>res)
                return false;
            res=max(res,i+nums[i]);
        }

        return true;
    }
};

int main(){


    return 0;
}
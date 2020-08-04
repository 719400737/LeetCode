#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int,int> res;
        res=make_pair(nums[0],0);
        for(auto i:nums){
            if(i==res.first){
                res.second++;
                continue;
            }
            if(res.second==0){
                res.first=i;
                res.second=1;
                continue;
            }
            res.second--;
        }
        return res.first;
    }
};

int main(){



    return 1;
}
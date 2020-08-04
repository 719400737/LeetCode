#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int temp=INT_MIN;
        if(nums.size()==0)
            return res;
        for(int i=0;i<=nums.size()-k;i++){
            for(int j=i;j<i+k;j++)
                temp=max(temp,nums[j]);
            res.push_back(temp);
            temp=INT_MIN;
        }
        return res;
    }
};

int main(){
    vector<int> ve={1,3,-1,-3,5,3,6,7};
    Solution s;
    s.maxSlidingWindow(ve,3);


    return 1;
}
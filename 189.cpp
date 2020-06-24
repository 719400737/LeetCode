#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res=nums;
        k%=nums.size();
        copy(nums.begin(),nums.end()-k,res.begin()+k);
        copy(nums.end()-k,nums.end(),res.begin());
        nums=res;
    }
};


int main(){


    return 0;
}
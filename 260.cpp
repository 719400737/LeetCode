#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        if(nums.size()==0)
            return res;
        int mask=nums[0];
        for(int i=1;i<nums.size();i++){
            mask^=nums[i];//异或得到两个只有一次出现两个数的异或值
        }
        int diff=mask&(-mask);//找到只有最右边是1的这个位置1的值
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & diff)
                x^=nums[i];
        }
        int y=mask^x;
        res.push_back(x);
        res.push_back(y);
        return res;
    }
};

int main(){

    

    return 0;
}
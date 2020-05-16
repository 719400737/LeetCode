#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> L(nums.size(),0);
        vector<int> R(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(i==0){
                L[i]=1;
            }
            else{
                L[i]=L[i-1]*nums[i-1];
            }
        }
        for(int j=nums.size()-1;j>=0;j--){
            if(j==nums.size()-1)
                R[j]=1;
            else{
                R[j]=R[j+1]*nums[j+1];
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=L[i]*R[i];
        }
        return nums;
    }
};

int main(){


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l1=0,r1=nums.size()-1;
        int l2=0,r2=nums.size()-1;
        vector<int> res;
        int lres=INT_MAX,rres=-1;
        int mid1=0;//1找左界，2找右界
        int mid2=0;
        while (l1<=r1 || l2<=r2)
        {
            if(l1<=r1){
                mid1=(l1+r1)/2;
                if(nums[mid1]==target){
                    lres=min(lres,mid1);
                    r1=mid1-1;

                }
                else if(nums[mid1]<target)
                    l1++;
                else
                    r1--;
            }
            if(l2<=r2){
                mid2=(l2+r2)/2;               
                if(nums[mid2]==target){
                    rres=max(rres,mid2);
                    l2=mid2+1;
                }
                
                else if(nums[mid2]<target)
                    l2++;
                else
                    r2--;
            }
        }
        res.push_back(lres==INT_MAX? -1:lres);       
        res.push_back(rres);
        return res;
        
    }
};

int main(){
    vector<int> vec={};
    int tag=7;
    Solution s;
    s.searchRange(vec,tag);

    return 0;
}
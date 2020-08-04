#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<int>& ratings){//暴力解，N2复杂度，不能通过
        vector<int> nums(ratings.size(),0);
        for(int i=0;i<ratings.size();i++){
            if(i==0){
                nums[i]=1;
            }
            else{
                if(ratings[i]<=ratings[i-1])
                    nums[i]=1;
                else if(ratings[i]>ratings[i-1])
                    nums[i]=nums[i-1]+1;
            }
            for(int j=i-1;j>=0;j--){
                if(ratings[j]>ratings[j+1]){
                    if(nums[j]>nums[j+1])
                        break;
                    else
                        nums[j]=nums[j+1]+1;
                }
                else if(ratings[j]==ratings[j+1])
                    break;
            }
        }
        int res=0;
        for(auto i:nums)
            res+=i;
        
        return res;
    }
    int candy(vector<int>& ratings) { //从正反两方向进行遍历，若遇到比前面大的就+1，否则就置1；
        vector<int> nums1(ratings.size(),0);
        vector<int> nums2=nums1;
        for(int i=0;i<ratings.size();i++){
            if(i==0)
                nums1[i]=1;
            else{
                if(ratings[i]>ratings[i-1])
                    nums1[i]=nums1[i-1]+1;
                else    nums1[i]=1;
            }
        }
        for(int i=ratings.size()-1;i>=0;i--){
            if(i==ratings.size()-1)
                nums2[i]=1;
            else{
                if(ratings[i]>ratings[i+1])
                    nums2[i]=nums2[i+1]+1;
                else    nums2[i]=1;
            }
        }
        int res=0;
        for(int i=0;i<nums1.size();i++){
            int temp=max(nums1[i],nums2[i]);
            res+=temp;
        }
        return res;

    }
};

int main(){
    vector<int> v={1,2,5,4,8,1,2,4,9,5,2,1};
    Solution s;
    int res=s.candy(v);
    cout<<res<<endl;

    return 0;
}
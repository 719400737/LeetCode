#include<bits/stdc++.h>
using namespace std;
class Solution {
    int res=0;
    void merge(vector<int>& nums,vector<int>& temp,int start,int mid,int end){
        int i=mid,j=start;
        i=start;j=mid;
        int k=i;
        while(i<mid && j<end){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
                res+=j-mid;
            }
            else    temp[k++]=nums[j++];
        }
        while(i<mid){
            temp[k++]=nums[i++];
            res+=j-mid;
        }
        while(j<end)
            temp[k++]=nums[j++];
        for(int i=start;i<end;i++)
            nums[i]=temp[i];
    }
    void helper(vector<int>& vec,vector<int>& temp,int start,int end){
        if(start>=end-1)
            return;
        int mid=(start+end)/2;
        helper(vec,temp,start,mid);
        helper(vec,temp,mid,end);
        merge(vec,temp,start,mid,end);
    }
public:
    int reversePairs(vector<int>& nums) {
        int start=0,end=nums.size();
        vector<int> temp(end,0);
        helper(nums,temp,start,end);
        return res;
    }
};

int main(){
     vector<int> v={7,5,4,1};
    Solution s;
    int res=s.reversePairs(v);
    cout<<res<<endl;
    return 0;
}


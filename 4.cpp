#include<bits/stdc++.h>
using namespace std;

class Solution {//使用归并排序来降低逆序对的复杂度，快手面试题
    int merge(vector<int>& nums,vector<int>& temp,int start,int end){
        if(start>=end-1)
            return 0;
        int mid=(start+end)/2;
        int a=merge(nums,temp,start,mid);
        int b=merge(nums,temp,mid,end);
        int res=a+b;
        int i=start,j=mid,k=i;
        while(i<mid && j<end){
            if(nums[i]<nums[j]){
                res+=(end-j)*nums[i];
                temp[k++]=nums[i++];
            }
            else
                temp[k++]=nums[j++];
        }
        while(i<mid){
            temp[k++]=nums[i++];
            //res+=j-mid;
        }
        while(j<end)
            temp[k++]=nums[j++];
        for(int i=start;i<end;i++){
            nums[i]=temp[i];
        }
        return res;
    }
public:
    int reversePairs(vector<int>& nums) {
        int start=0,end=nums.size();
        vector<int> temp(end,0);
        int res=merge(nums,temp,start,end);
        return res;
    }
};
int main(){
    Solution s;
    vector<int> v={1,3,5,2,6,4};
    int res=s.reversePairs(v);
    cout<<res<<endl;

    return 0;
}
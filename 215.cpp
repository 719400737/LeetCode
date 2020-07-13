#include<bits/stdc++.h>
using namespace std;
class Solution {
    int res=0;
    void swap(int& a,int& b){
        int temp=a;
        a=b;
        b=temp;
    }
    void quickSort(vector<int>& nums,int start,int end,int k){
        int i=start,j=end;
        if(i>=j){
            if(i==k)
                res=nums[k];
            return;
        }
        int cur=nums[i];
        while(i<j){
            while(i<j && nums[j]>=cur)
                j--;
            if(i<j)
                swap(nums[i],nums[j]);
            while(i<j && nums[i]<=cur)
                i++;
            if(i<j)
                swap(nums[i],nums[j]);
        }
        if(i==k){
            res=nums[k];
        }
        else{
            quickSort(nums,start,i-1,k);
            quickSort(nums,i+1,end,k);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {//快排
        int len=nums.size();
        quickSort(nums,0,nums.size()-1,len-k);
        return res;
    }
};

int main(){
    vector<int> vec={1};
    Solution s;
    int res=s.findKthLargest(vec,1);
    cout<<res<<endl;
    return 0;
}
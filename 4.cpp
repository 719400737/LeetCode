#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& v1,int s1,int e1,vector<int>& v2,int s2,int e2,int k){
        int l1=e1-s1+1;
        int l2=e2-s2+1;
        if(l1>l2)
            return helper(v2,s2,e2,v1,s1,e1,k);
        if(l1==0)
            return v2[k+s2-1];
        if(k==1){
            return min(v1[s1],v2[s2]);
        }
        int i=s1+min(k/2,l1)-1;
        int j=s2+min(k/2,l2)-1;3
        if(v1[i]<v2[j]){
            return helper(v1,i+1,e1,v2,s2,e2,k-(i-s1+1));
        }
        else{
            return helper(v1,s1,e1,v2,j+1,e2,k-(j-s2+1));
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size(); 
        //判断奇偶，找到k
        int k;
        if((m+n)%2){
            k=(m+n+1)/2;
            return helper(nums1,0,m-1,nums2,0,n-1,k);
        }
        else{
            k=(m+n)/2;
            double a=helper(nums1,0,m-1,nums2,0,n-1,k);
            double b=helper(nums1,0,m-1,nums2,0,n-1,k+1);
            return (a+b)/2;
        }
        
    }
};

int main(){
    vector<int> a={1,3};
    vector<int> b={2};
    Solution s;
    double res=s.findMedianSortedArrays(a,b);
    cout<<res<<endl;

    return 0;
}
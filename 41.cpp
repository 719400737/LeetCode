#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int temp=1;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]<=0)
        //         continue;
        //     else{
        //         if(nums[i]==temp)
        //             temp++;
        //         if(nums[i]>temp)
        //             return temp;
        //     }
        // }
        // return temp;
        int n=nums.size();
        string s(n+2,'0');
        for(int i=0;i<n;i++){
            if(nums[i]<=0)
                s[0]='1';
            else{
                if(nums[i]>n)
                    s[n+1]='1';
                else
                    s[nums[i]]='1';
            }

        }
        for(int i=1;i<n+2;i++){
            if(s[i]=='0')
                return i;
        }
        return n+1;
    }
};

int main(){
    vector<int> nums={0,1,2,-1,3};
    Solution s;
    int res;
    res=s.firstMissingPositive(nums);
    cout<<res<<endl;
    return 0;
}
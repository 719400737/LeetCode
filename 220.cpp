#include<bits/stdc++.h>
using namespace std;
/* 以下使用暴力方法，复杂度为n^2,超时
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<=i+k && j<nums.size();j++){
                long long a=nums[j];
                long long b=nums[i];
                long long res=abs(a-b);
                if(res<=t)
                    return true;
            }
        }
        return false;
    }
};
*/
//使用通排序
typedef long long LL;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t<0) return false;  //k为窗口大小，t为两值绝对值
        LL mod=t+1LL; //桶的mod
        unordered_map<LL,LL> buck;
        for(int i=0;i<nums.size();i++){
            LL nth=nums[i]/mod;//第nth个桶
            if(nums[i]<0)   nth--;//若为负数，需要桶数减1.
            if(buck.count(nth))  //若本桶内有则返回true
                return true;
            else if(buck.count(nth+1) && abs(nums[i] - buck[nth+1]) <= t) //相邻桶有则比较两数大小，满足条件返回true
                return true;
            else if(buck.count(nth-1) && abs(nums[i] - buck[nth-1]) <= t)
                return true;
            buck[nth]=nums[i];
            if(i>=k){  //删除窗口外的内容
                buck.erase(nums[i-k]/mod);
            }
        }
        return false;
    }
};

int main(){
    vector<int> vec={1,5,9,1,5,9};
    Solution s;
    bool res=s.containsNearbyAlmostDuplicate(vec,2,3);
    cout<<res<<endl;
    return 0;
}
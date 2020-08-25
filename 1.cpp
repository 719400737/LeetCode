#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> vec=nums;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==target){
                break;
            }
            else if(nums[l]+nums[r]<target)
                l++;
            else
                r--;
        }
        for(int i=0;i<nums.size();i++){
            if(vec[i]==nums[l] || vec[i]==nums[r])
                res.push_back(i);
            if(res.size()==2)
                break;
        }

        return res;
    }
};

int main(){
    
    int T;
    cin>>T;
    vector<int> vv;
    while(T--){
        int n,m;
        cin>>n>>m;
        Solution s;
        vector<vector<int>> vec;
        while(n--){
            int a,b;
            cin>>a>>b;
            vector<int> temp={a,b};
            vec.push_back(temp);
        }
        int res=s.result(vec,m);
        if(res==INT_MAX)
            res=-1;
        vv.push_back(res);
    }
    for(auto i:vv)
        cout<<i<<endl;

    return 0;
}

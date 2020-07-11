#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        unordered_map<int,int> m2;
        int s=nums.size();
        int res=1;
        if(s<=1)
            return s;
        for(int i=0;i<s;i++){
            m[nums[i]]=1;
        }
        for(int i=0;i<s;i++){
            int tmp=nums[i]+1;
            int res_now=1;
            int j=i+1;
            for(;m.count(tmp);tmp++){
                if(m2.count(tmp)){
                    res_now+=m2[tmp];
                    break;
                }
                res_now++;
            }
            m2[nums[i]]=res_now;
            res=max(res,res_now);
            
        }
        return res;
    }
};

int main(){
    vector<int> v={100,4,200,1,3,2};
    Solution s;
    int res=s.longestConsecutive(v);
    cout<<res<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string s;
        bool b=false;
        if(nums.size()==0){
            return res;
        }
        for(int i=0,j=0;i<nums.size();i++){ //j表示起点 i表示现在的点
            if(i<nums.size()-1 && nums[i+1]==nums[i]+1)
                continue;
            if(i==j)
                s+=to_string(nums[i]);
            else
            {
                s=s+to_string(nums[j])+"->"+to_string(nums[i]);
            }
            j=i+1;
            cout<<s<<endl;
            res.push_back(s);
            s.clear();
        }
        
        return res;
    }
};

int main(){
    vector<int> vec={-1};
    Solution s;
    s.summaryRanges(vec);

    return 0;
}
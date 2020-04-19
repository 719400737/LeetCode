#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];    
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec={4,1,2,1,2};
    int res=s.singleNumber(vec);
    cout<<res<<endl;
    return 0;
}
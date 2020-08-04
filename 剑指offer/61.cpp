#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int> s;
        int first=0;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
                continue;
            }
            if(s.count(nums[i]))
                return false;
            s.insert(nums[i]);
        }
        first=nums[zero];
        int count=nums[4]-nums[zero];
        if(count<=4)
            return true;
        return false;
        
    }
};

int main(){



    return 0;
}
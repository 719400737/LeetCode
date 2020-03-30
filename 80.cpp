#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // map<int,int> m;//使用map
        // int cur=0;
        // for(int i=0;i<nums.size();i++){
        //     if(m[nums[i]]>1)
        //         continue;
        //     m[nums[i]]++;
        //     nums[cur++]=nums[i];
        // }
        // return cur;
        int cur=0;
        for(int i=0;i<nums.size();i++){
            if(i>0&&i<nums.size()-1&&nums[i]==nums[i-1]&&nums[i]==nums[i+1])
                continue;
            nums[cur++]=nums[i];
        }
        return cur;
    }
};

int main(){
    Solution s;

    return 0;
}
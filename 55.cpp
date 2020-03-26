#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=0;
        for(int i=0;i<nums.size();i++){
            if(len<i)
                return false;
            len=max(len,i+nums[i]);

        }
        return true;
   
    }
};

int main(){
    Solution s;
    vector<int> vec={3,2,1,0,4};
    if(s.canJump(vec))
        cout<<"can"<<endl;
    else
    {
        cout<<"can't"<<endl;
    }
    
    return 0;
}
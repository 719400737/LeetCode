#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int m=nums.size();
        if(k==0)
            return res;
        deque<int> wind;//双端队列，从队头到队尾，依次存放窗口内最大元素的index和第二大的index
        int right=0;
        while(right<m){
            if(!wind.empty() && wind.front()<=right-k) //若队首的序列不在窗口范围内
                wind.pop_front();
            if(!wind.empty() && nums[right]>nums[wind.front()]){//当前比队首元素大
                wind.clear();
            }
            while(!wind.empty() && nums[right]>nums[wind.back()]){//当前比队尾的元素大
                wind.pop_back();
            }
            wind.push_back(right);
            right++;
            if(right>=k)
                res.push_back(nums[wind.front()]);
        }
        // for(auto i:res)
        //     cout<<i<<endl;
            
        return res;
    }
};

int main(){
    vector<int> vec={9,10,9,-7,-4,-8,2,-6};
    int k=5;
    Solution s;
    s.maxSlidingWindow(vec,k);
    
    return 0;
}
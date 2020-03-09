#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1.第一次尝试，确定1个核心变量，去找另外两个，
vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(),nums.end());
    int s=nums.size();
    vector<vector<int>> res;
    for(int cur=0;cur<s;cur++){
        if((cur>0&&nums[cur]==nums[cur-1]))
            continue;
        int first=cur+1;
        int second=s-1;
        int need=-nums[cur];
        while (first<second)
        {
            if(nums[first]+nums[second]==need){
                res.push_back({nums[first],nums[second],nums[cur]});
                second--;
                while(second>first&&nums[second]==nums[second+1])
                    second--;        
            }
            else if(nums[first]+nums[second]<-nums[cur]){
                first++;
            }
            else if(nums[first]+nums[second]>-nums[cur]){
                second--;
            }
        }
    
    }
    return res;
    
}


int main(){
    vector<int> vec={-1,0,1,2,-1,-4};
    vector<vector<int>>res= threeSum(vec);
    for(auto i:res){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}
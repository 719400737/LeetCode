#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    void swap(int &a,int &b){
        int tmp;
        tmp=a;
        a=b;
        b=tmp;
    }
    void sortColors(vector<int>& nums) {
        int head=0;
        int tail=nums.size()-1;
        int cur=head;
        while(cur<=tail){
            if(nums[cur]==0){
                swap(nums[cur++],nums[head++]);
            }
            else if(nums[cur]==2){
                swap(nums[cur],nums[tail--]);
            }
            else{
                cur++;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> vec={2,0,2,1,1,0};
    s.sortColors(vec);
    for(auto i:vec)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int s=nums.size();
    int i;
    int j;
    for(i=s-1;i>0;i--){
        if(nums[i]<=nums[i-1])
            continue;
        else
            break;
    }
    if(i<=0){
        reverse(nums.begin(),nums.end());
        return;
    }
    //i-1表示要换的数
    for(j=s-1;j>=i;j--){
        if(nums[j]<=nums[i-1])
            continue;
        else
            break;
    }
    //j表示要和i-1换的数
    int tmp=nums[j];
    nums[j]=nums[i-1];
    nums[i-1]=tmp;
    vector<int>::iterator b=nums.end()-(s-i);
    reverse(b,nums.end());
    return ;
}
int main(){

    vector<int> vec={3,2,1};
    nextPermutation(vec);
    for(auto i:vec)
        cout<<i<<" ";

    return 0;
}
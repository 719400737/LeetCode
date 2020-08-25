#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> res;
    vector<int> index;//改进版，建立索引数组，“原始数组不变，用于比较连个元素的大小，真正位置变化的是索引数组的位置”
    //map<int,int> m;//本意是建立索引，结果遇到含有相同元素时，失败
    void helper(vector<int>& nums,vector<int>& temp,int start,int end){//start 表示开始的位置，end表示最后位置的后一个，是没有元素的
        if(start>=end-1)   //temp用来存储变化后正确的,当前的序列用index来存储
            return ;
        int mid=(start+end)/2;
        helper(nums,temp,start,mid);
        helper(nums,temp,mid,end);
        int t1=start,t2=mid,k=start;
        int num=0;
        while(t1<mid && t2<end){
            if(nums[index[t1]]<=nums[index[t2]]){
                temp[k]=index[t1++];
                res[temp[k]]+=num;
                k++;
            }
            else{
                temp[k++]=index[t2++];
                num++;
            }
        }
        while(t1<mid){
            temp[k]=index[t1++];
            res[temp[k]]+=num;
            k++;
        }
        while(t2<end){
            temp[k++]=index[t2++];
        }
        for(int i=start;i<end;i++){
            index[i]=temp[i];
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> temp=nums;
        int ss=nums.size();
        vector<int> a(ss,0);
        res=move(a);
        vector<int> index(ss,0);//记录了当前操作数对应的原始数组的下标
        for(int i=0;i<ss;i++){
            index[i]=i;
        }
        this->index=index;
        temp=index;
        helper(nums,temp,0,nums.size());
        return res;
    }
};

int main(){

    vector<int> v={26,78,27,100,33,67,90,23,66,5,38,7,35,23};
    Solution s;
    vector<int> res = s.countSmaller(v);
    for(auto i:res)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
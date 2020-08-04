#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> Q;//默认建立最大堆 ，若要建立最小堆应为
        // priority_queue<int,vector<int>,greater<int>> Q;
        //题目要求最小的k个数，应建立一个大小为k的最大堆。
        vector<int> res;
        if(k==0)
            return res;
        for(int i=0;i<k;i++){
            Q.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(Q.top()>arr[i]){
                Q.pop();
                Q.push(arr[i]);
            }
        }
        
        while(!Q.empty()){
            int i=Q.top();
            res.push_back(i);
            Q.pop();
        }
        return res;
    }
};

int main(){

    vector<int> v={0,0,0,2,0,5};
    Solution s;
    v=s.getLeastNumbers(v,2);
    for(auto i:v)
        cout<<i<<" ";
    return 1;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    int sum=0;
public:
    void DFS(int start,int k,int n){//k个数的和为n
        if(path.size()==k && sum==n){
            res.push_back(path);
        }
        if(path.size()==k){
            return;
        }
        for(int i=start;i<=9;i++){
            if(sum+i<=n){
                sum+=i;
                path.push_back(i);
                DFS(i+1,k,n);
                path.pop_back();
                sum-=i;
            }
            else{
                return;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        DFS(1,k,n);
        for(auto i:res){
            for(auto j:i)
                cout<<j<<" ";
            cout<<endl;
        }
        return res;
    }
};
int main(){
    Solution s;
    s.combinationSum3(3,0);


    return 0;
}
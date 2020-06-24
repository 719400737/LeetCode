#include<bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<int>> res;
vector<int> path;
public:
    void helper(int n){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i)
                    path.push_back(1);
                else{
                    path.push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
            res.push_back(path);
            path.clear();
        }
    }
    vector<int> getRow(int rowIndex) {
        helper(rowIndex);
        return res[rowIndex];
    }
};
int main(){
    Solution s;

    int n=3;
    vector<int> res;
    res=s.getRow(n);
    for(auto i:res)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
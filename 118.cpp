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
    vector<vector<int>> generate(int numRows) {
        helper(numRows-1);
        return res;
    }
};
int main(){
    Solution s;

    int n=3;
    vector<vector<int>> res;
    res=s.generate(n);
    for(auto i:res){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
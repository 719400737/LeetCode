#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> res;
    string path;
public:
    void DFS(int n,int left,int right){
        if(path.size()==2*n){
            res.push_back(path);
            return;
        }
        if(left<n){
            path.push_back('(');
            DFS(n,left+1,right);
            path.pop_back();
        }
        if(right<left){
            path.push_back(')');
            DFS(n,left,right+1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        DFS(n,0,0);
        return res;
    }
};
int main(){



    return 0;
}
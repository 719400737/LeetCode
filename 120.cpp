#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> vec;
public:
    void helper(){
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size();j++){
                if(i==0)
                    continue;
                if(j==0)
                    vec[i][j]+=vec[i-1][j];
                else if(j==vec[i].size()-1)
                    vec[i][j]+=vec[i-1][j-1];
                else
                    vec[i][j]+=min(vec[i-1][j-1],vec[i-1][j]);
            }
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        this->vec=triangle;
        helper();
        int i=vec.size()-1;
        int ma=INT_MAX;
        for(int j=0;j<vec[i].size();j++)
            ma=min(ma,vec[i][j]);
        return ma;
    }
};

int main(){
    Solution s;

    return 0;
}
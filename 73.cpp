#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> clom;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    clom.insert(j);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(row.count(i) || clom.count(j)){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int>bm;
        vector<int>bn;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    bm.push_back(i);
                    bn.push_back(j);
                }
            } 
        } 
        for(int i = 0; i < bm.size(); i++)
        {
            for( int x = 0; x < n; x++)
            {
                matrix[bm[i]][x] = 0;
            }
            for( int x = 0; x < m; x++)
            {
                matrix[x][bn[i]] = 0;
            }
        }
    }
};
*/

int main(){


    return 0;
}
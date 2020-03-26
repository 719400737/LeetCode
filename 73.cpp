#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> col;
        set<int> row;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
                    
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(row.count(i)||col.count(j))
                    matrix[i][j]=0;
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec={{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(vec);
    for(auto i:vec){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
    //cout<<vec.size()<<endl<<vec[1].size()<<endl;
    return 0;
}
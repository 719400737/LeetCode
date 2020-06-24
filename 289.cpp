#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(i==0 && j==0)
                    res[i][j]=board[i][j];
                else if(i==0)
                    res[i][j]=res[i][j-1]+board[i][j];
                else if(j==0)
                    res[i][j]=res[i-1][j]+board[i][j];
                else res[i][j]=-res[i-1][j-1]+res[i-1][j]+res[i][j-1]+board[i][j];
            }
        }
        vector<vector<int>> nums=board;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int temp=0;
                int i1= i==0 ? 0:i-1;
                int i2= i==board.size()-1 ? i:i+1;
                int j1= j==0 ? 0:j-1;
                int j2= j==board[i].size()-1 ? j:j+1; 
                if(i1==0 && j1==0)
                    temp=res[i2][j2];
                else if(j1==0)
                   temp=res[i2][j2]-res[i1-1][j2]; 
                else if(i1==0)
                    temp=res[i2][j2]-res[i2][j1-1];
                else
                    temp=res[i2][j2]-res[i2][j1-1]-res[i1-1][j2]+res[i1-1][j1-1];  
                if(board[i][j]==1){ //2为右下角，1为左上角
                    temp--;
                    if(temp>1 && temp<4)
                        board[i][j]=1;
                    else
                        board[i][j]=0;
                }
                else{
                    if(temp==3)
                        board[i][j]=1;
                }
            }
        }
    }
};

int main(){
    vector<vector<int>> b={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution s;
    s.gameOfLife(b);
    for(auto i:b){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
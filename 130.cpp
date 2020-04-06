#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
private:
    int M;
    int N;
public:
    void solve(vector<vector<char>>& board) {
        M=board.size();    //M行
        if(M==0)
            return;
        N=board[0].size(); //N列
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(i==0||i==M-1||j==0||j==N-1){
                        DFS(board,i,j);
                }
            }
        }

        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
    void DFS(vector<vector<char>>& board,int m,int n){
        if(m<0 || m==M || n<0 || n==N || board[m][n]!='O')
            return;
            
            board[m][n]='#';
        //[m-1][n],[m+1][n],[m][n-1],[m][n+1]

            DFS(board,m-1,n);
 
            DFS(board,m+1,n);

            DFS(board,m,n-1);

            DFS(board,m,n+1);  
         
    }
};

int main(){
    Solution s;

    return 0;
}
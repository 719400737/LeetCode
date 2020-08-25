#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> hang(9,vector<int>(10,0));
        vector<vector<int>> lie=hang,kuai=hang;
        //块号=(i/3)*3+j/3;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int num=(i/3)*3+j/3;
                if(board[i][j]=='.')
                    continue;
                else{
                    int temp=board[i][j]-'1';
                    if(hang[i][temp]!=0 || lie[j][temp]!=0 || kuai[num][temp]!=0)
                        return false;
                    else{
                        hang[i][temp]=1;
                        lie[j][temp]=1;
                        kuai[num][temp]=1;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    vector<vector<char>> v={{'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}};
  Solution s;
  bool res=s.isValidSudoku(v);
    cout<<res<<endl;
    

    return 0;
}
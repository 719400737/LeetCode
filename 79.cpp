#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
private:
    vector<char> vec;
    string word;
    vector<vector<char>> board;
    vector<vector<int>> tag;
    int b=0;
public:
    void DFS(int i,int j,int n){
        if(vec.size()==word.size()){
            b=1;
            return;
        }   
        //以 i,j为中心周边4个元素：i,j-1; i,j+1; i-1,j; i+1,j
        if(j-1>=0&&board[i][j-1]==word[n]&&tag[i][j-1]==0){
            tag[i][j-1]=1;
            vec.push_back(word[n]);
            DFS(i,j-1,n+1);
            tag[i][j-1]=0;
            vec.pop_back();
        }
        if(j+1<board[i].size()&&board[i][j+1]==word[n]&&tag[i][j+1]==0){
            tag[i][j+1]=1;
            vec.push_back(word[n]);
            DFS(i,j+1,n+1);
            tag[i][j+1]=0;
            vec.pop_back();
        }
        if(i-1>=0&&board[i-1][j]==word[n]&&tag[i-1][j]==0){
            vec.push_back(word[n]);
            tag[i-1][j]=1;
            DFS(i-1,j,n+1);
            tag[i-1][j]=0;
            vec.pop_back();
        }
        if(i+1<board.size()&&board[i+1][j]==word[n]&&tag[i+1][j]==0){
            vec.push_back(word[n]);
            tag[i+1][j]=1;
            DFS(i+1,j,n+1);
            tag[i+1][j]=0;
            vec.pop_back();
        }
        
        return ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;
        this->word=word;
        char c=word[0];
        int N=board.size();
        int M=board[0].size();
        vector<int> a(M);
        for(int i=0;i<N;i++){
            tag.push_back(a);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==c){
                    vec.push_back(c);
                    tag[i][j]=1;
                    DFS(i,j,1);
                    if(b==1)
                        return true;
                    tag[i][j]=0;
                    vec.pop_back();
                }                
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<vector<char>> bord={{'a'},{'a'}};
    string t="aaa";
    if(s.exist(bord,t))
        cout<<"yes"<<endl;
    else
    {
        cout<<"no"<<endl;
    }
    
    return 0;
}
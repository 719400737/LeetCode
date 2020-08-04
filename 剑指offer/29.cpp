#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        char des='D';
        vector<int> res;
        int m=matrix.size();
        if(m==0)
            return res;
        int n=matrix[0].size();
        int i=0,j=0,count=0;
        while(count<m*n){
            if(des=='D'){
                if(j==n || matrix[i][j]==INT_MIN ){
                    des='S';i++;j--;
                }
                else{
                    res.push_back(matrix[i][j]);
                    matrix[i][j]=INT_MIN;
                    j++;
                    count++;
                }   
            }
            else if(des=='S'){
                if(i==m || matrix[i][j]==INT_MIN){
                    des='A';j--; i--;
                }
                else{ 
                    res.push_back(matrix[i][j]);
                    matrix[i][j]=INT_MIN;
                    i++;
                    count++;
                }
            }
            else if(des=='A'){
                
                if(j<0 || matrix[i][j]==INT_MIN){
                    des='W';i--;j++;
                }
                else{
                    res.push_back(matrix[i][j]);
                    matrix[i][j]=INT_MIN;
                    j--;
                    count++;
                }
            }
            else if(des=='W'){
                
                if(i<0 || matrix[i][j]==INT_MIN){
                    des='D';j++;i++;
                }
                else{
                    res.push_back(matrix[i][j]);
                    matrix[i][j]=INT_MIN;
                    i--;
                    count++;
                }
            }
        }
        return res;
    }
};
int main(){

    vector<vector<int>> vec={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution s;
    vector<int> res=s.spiralOrder(vec);
    for(auto i:res)
        cout<<i<<endl;
    return 1;
}
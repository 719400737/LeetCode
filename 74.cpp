#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)
            return false;
        int n=matrix[0].size();
        if(n==0)
            return false;;
        int f=0,s=m-1;
        while (f<s)
        {
            int m=(f+s)/2;
            if(m==f || m==s)
                break;
            if(matrix[m][0]<=target)
                f=m;
            else
                s=m;
        }
        if(matrix[s][0]<=target)
            f=s;
        int a=0,b=n-1;
        while(a<b){
            int m=(a+b)/2;
            if(m==a || m==b)
                break;
            if(matrix[f][m]<=target)
                a=m;
            else
                b=m;
        }
        if(matrix[f][a]==target || matrix[f][b]==target)
            return true;
        return false;
        
    }
};

int main(){


    return 0;
}
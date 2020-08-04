#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool helper(vector<int>& postorder,int begin,int end){
        if(begin>=end)
            return true;
        int p=begin;
        while(postorder[p]<postorder[end])
            p++;
        int m=p;
        while(postorder[p]>postorder[end])
            p++;
        return (p==end && helper(postorder,begin,m-1) && helper(postorder,m,end-1));
        
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder,0,postorder.size()-1);
    }
};

int main(){



    return 1;
}

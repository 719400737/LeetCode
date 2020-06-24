#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        vector<vector<int>>::iterator it=intervals.begin();
        if(it==intervals.end()) return res;
        vector<vector<int>>::iterator it2=it+1;
        vector<int> v1=*it;  
        while(it2!=intervals.end()){
            vector<int> v2=*it2; 
            if(v1[1]<v2[0]){
                res.push_back(v1);
                it=it2;
                v1=*it;
                it2++;
            }
            else if(v1[1]>v2[1]){
                it2++;
            }
            else{
                v1[1]=v2[1];
                it2++;
            }
        }
        res.push_back(v1);
            return res; 
    }
};

int main(){


    return 0;
}
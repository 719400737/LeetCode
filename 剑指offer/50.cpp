#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> m;
        char res;
        bool b=true;
        for(auto i:s){
            m[i]++;
        }
        for(auto i:s){
            if(m[i]==1){
                res=i;
                b=false;
                break;
            }
        }
        if(b)
            return " ";
        return res;
    }
};

int main(){



    return 1;
}
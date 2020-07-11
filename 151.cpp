#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        stringstream ss(s);
        string temp;
        while(ss>>temp)
            vec.push_back(temp);
        reverse(vec.begin(),vec.end());
        string res;
        for(int i=0;i<vec.size();i++){
            if(i==vec.size()-1)
                res+=vec[i];
            else{
                res+=vec[i]+" ";
            }
        }
        return res;
    }
};

int main(){


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string t1=s.substr(0,n);
        string t2=s.substr(n);
        return t2+t1;
    }
};

int main(){



    return 1;
}
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode* temp=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=vec.size()-1;
        while(i<j){
            if(vec[i++]==vec[j--])
                continue;
            else
                return false;
        }
        return true;
    }
};

int main(){


    return 0;
}
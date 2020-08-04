#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode* cur=head;
        while(cur!=NULL){
            res.push_back(cur->val);
            cur=cur->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){



    return 1;
}
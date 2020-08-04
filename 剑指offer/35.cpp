#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {//深拷贝，使用map来实现
        if(head==NULL)
            return NULL;
        unordered_map<Node*,Node*> m;
        Node* cur=head;
        while(cur!=NULL){
            m[cur]=new Node(cur->val);
            cur=cur->next;
        }

        cur=head;
        while(cur!=NULL){
            m[cur]->next=m[cur->next];
            m[cur]->random=m[cur->random];
            cur=cur->next;
        }
        return m[head];
    }
};

int main(){



    return 1;
}
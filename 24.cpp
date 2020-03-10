#include<iostream>

using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 ListNode* Creat(int a[],int N){ 
	ListNode *tail;
	ListNode *prehead=new ListNode(-1);
	ListNode *head=prehead;
	for(int i=0;i<N;i++){
		tail=new ListNode(a[i]);
		head->next=tail;
		head=tail;
	}
	return prehead->next;
}

ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        ListNode* first=head;
        ListNode* second=head->next;
        if(!second)
            return first;
        if(second->next)
            first->next=swapPairs(second->next);
        else
            first->next=second->next;
        second->next=first;
        return second;
}

int main(){

    int a2[]={1};
    cout<<"Creat list"<<endl;
	ListNode *head=Creat(a2,1);
    head=swapPairs(head);
	cout<<"l2 mumber :"<<endl;
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
    return 0;
}
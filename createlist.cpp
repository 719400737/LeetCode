ListNode* CreateList(vector<int> vec){
    if(vec.size()==0)
        return NULL;
    ListNode* prehead=new ListNode(-1);
    ListNode* cur=prehead;
    for(int i=0;i<vec.size();i++){
        cur->next=new ListNode(vec[i]);
        cur=cur->next;
    }
    ListNode* res=prehead->next;
    delete prehead;
    return res;
}
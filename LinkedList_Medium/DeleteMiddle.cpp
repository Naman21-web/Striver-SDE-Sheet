Node* deleteMid(Node* head)
{
    // Your Code Here
    if(head->next==NULL) return NULL;
    Node* prev;
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        prev=slow;
        slow = slow->next;
        fast=fast->next->next;
    }
    Node* todelete = prev->next;
    prev->next = slow->next;
    delete todelete;
    return head;
}
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            int cnt=0;
            do{
                slow = slow->next;
                cnt++;
            }while(slow!=fast);
            return cnt;
        }
    }
    return 0;
}
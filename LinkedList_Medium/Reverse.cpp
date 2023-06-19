    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* currptr=head;
        Node* nextptr;
        Node* prevptr=NULL;
        while(currptr!=NULL){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr=nextptr;
        }
        return prevptr;
    }
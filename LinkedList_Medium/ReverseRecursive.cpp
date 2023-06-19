Node* reverse(Node* currptr,Node* prevptr){
        if(currptr==NULL) return prevptr;
        Node* nextptr=currptr->next;
        currptr->next = prevptr;
        prevptr=currptr;
        return reverse(nextptr,currptr);
    }
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* currptr=head;
        Node* prevptr=NULL;
        return reverse(currptr,prevptr);   
    }
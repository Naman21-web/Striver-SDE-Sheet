Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node* temp=head;
        while(temp){
            while(temp->next && temp->data==temp->next->data){
                Node* todelete = temp->next;
                temp->next = todelete->next;
                if(todelete->next) todelete->next->prev = temp;
                delete todelete;
            }
            temp = temp->next;
        }
        return head;
    }
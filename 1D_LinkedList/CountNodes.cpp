int getCount(struct Node* head){
    
        //Code here
        Node* temp=head;
        int l=0;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        return l;
    }
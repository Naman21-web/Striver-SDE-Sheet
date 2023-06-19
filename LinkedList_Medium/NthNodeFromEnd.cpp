int getNthFromLast(Node *head, int n)
    {
           // Your code here
           Node* temp1=head;
           Node* temp2=head;
           while(n--) {
               temp1=temp1->next;
               if(temp1==NULL && n!=0) return -1;
           }
           while(temp1!=NULL){
               temp1=temp1->next;
               temp2=temp2->next;
           }
           return temp2->data;
    }
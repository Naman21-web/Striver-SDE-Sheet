struct Node* reverse(struct Node *head)
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
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        int carry = 0;
        Node* dummyNode = new Node(-1);
        Node* temp=dummyNode;
        while(first && second){
            int x = first->data + second->data + carry;
            carry = x/10;
            temp->next = new Node(x%10);
            first = first->next;
            second = second->next;
            temp=temp->next;
        }
        while(first){
            int x = first->data+carry;
            carry = x/10;
            temp->next = new Node(x%10);
            first = first->next;
            temp=temp->next;
        }
        while(second){
            int x = second->data+carry;
            carry = x/10;
            temp->next = new Node(x%10);
            second = second->next;
            temp=temp->next;
        }
        if(carry) temp->next = new Node(carry);
        dummyNode->next = reverse(dummyNode->next);
        return dummyNode->next;
    }
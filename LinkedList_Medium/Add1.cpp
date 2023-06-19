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
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        int carry=1;
        Node* temp = head;
        while(temp!=NULL && carry != 0){
            int x = temp->data;
            x =x + carry;
            carry = x/10;
            temp->data = x % 10;
            if(temp->next!=NULL)temp = temp->next;
            else {
                if(carry) {temp->next = new Node(carry); carry=0;}
                temp= temp->next;
            }
        }
       
        head=reverse(head);
        return head;
    }
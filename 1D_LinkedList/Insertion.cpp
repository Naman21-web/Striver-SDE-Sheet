Node *insertAtBegining(Node *head, int x) {
       // Your code here
        Node* Linkedlist = new Node(x);
        Linkedlist->next=head;
        return Linkedlist;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
       Node* Linkedlist = new Node(x);
       if(head==NULL) return Linkedlist;
       Node* temp=head;
       while(temp->next!=NULL) temp=temp->next;
       temp->next=Linkedlist;
       return head;
    }
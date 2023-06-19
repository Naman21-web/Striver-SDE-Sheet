Node* deleteNode(Node *head_ref, int x)
    {
      //Your code here
      if(x==1){
          head_ref->next->prev=NULL;
          head_ref=head_ref->next;
          return head_ref;
      }
      Node* temp=head_ref;
      int pos=1;
      while(pos!=x-1){
          temp=temp->next;
          pos++;
      }
    //   cout<<temp->next->data;
      Node* todelete = temp->next;
      temp->next = todelete->next;
      if(todelete->next!=NULL)todelete->next->prev = temp;
      delete todelete;
      return head_ref;
    }
Node* reverseDLL(Node * head)
{
    //Your code here
    Node* temp=head;
    while(true){
        Node* nextptr = temp->next;
        temp->next = temp->prev;
        temp->prev = nextptr;
        if(nextptr!=NULL)temp = nextptr;
        else return temp;
    }
}

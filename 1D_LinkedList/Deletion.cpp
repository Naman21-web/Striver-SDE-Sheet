Node* deleteNode(Node *head,int x)
{
    //Your code here
    Node* temp=head;
    if(x==1){
        delete head;
        return temp->next;
    }
    while(x>2) {temp=temp->next; x--;}
    Node* todelete = temp->next;
    temp->next = todelete->next;
    delete todelete;
    return head;
}

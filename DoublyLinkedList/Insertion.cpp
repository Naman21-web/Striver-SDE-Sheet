void addNode(Node *head, int pos, int data)
{
   // Your code here
   Node* newNode =  new Node(data);
   int x=0;
   Node* temp =head;
   while(temp!=NULL){
       if(pos==x){
           newNode->next=temp->next;
           if(newNode->next!=NULL)newNode->next->prev = newNode;
           temp->next = newNode;
           newNode->prev=temp;
           break;
       }
       temp = temp->next;
       x++;
   }
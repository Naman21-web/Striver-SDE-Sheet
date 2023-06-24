void MyStack ::push(int x) 
{
    // Your Code
    StackNode* st =new StackNode(x);
    st->next=top;
    top=st;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top==NULL) return -1;
    int x = top->data;
    StackNode* todelete = top;
    top=top->next;
    delete todelete;
    return x;
}
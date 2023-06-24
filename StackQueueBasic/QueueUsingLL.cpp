struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
// front->next=NULL
// rear=front;
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* q = new QueueNode(x);
       if(front==NULL){
           front=q;
           rear=q;
           return;
       }
       rear->next=q;
       rear=q;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code   
        if(front==NULL) return -1;
        int x = front->data;
         QueueNode* todelete = front;
        front = front->next;
        delete todelete;
        return x;
}

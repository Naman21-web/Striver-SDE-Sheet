class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
        if(q1.empty()) return -1;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        while(q2.size()!=0){
            q1.push(q2.front());
            q2.pop();
        }
        return x;
}

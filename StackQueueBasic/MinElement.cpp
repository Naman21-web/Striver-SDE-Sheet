 int minEle;
    stack<int> s1,s2;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           //Write your code here
           if(s2.empty()) return -1;
           return s2.top();
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s1.empty()) return -1;
           int x;
           if(s1.top()==s2.top()){
               x = s1.top();
               s1.pop();
               s2.pop();
           }
           else{x=s1.top(); s1.pop();}
           return x;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(!s2.empty() && x>s2.top()){
               s1.push(x);
           }
           else{
               s1.push(x);
               s2.push(x);
           }
       }
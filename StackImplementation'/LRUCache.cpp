class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class node{
    public:
    node* prev;
    node* next;
    int key;
    int val;
    node(int keyy,int data){
        prev=NULL;
        next=NULL;
        val=data;
        key=keyy;
    }
};
    int capacity;
     unordered_map < int, node * > mp;
    node* tail=new node(-1,-1);
    node* head=new node(-1,-1);
    
    LRUCache(int cap)
    {
        // code here
        capacity=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* list){
        node* listnext=head->next;
        list->next=listnext;
        list->prev=head;
        head->next=list;
        listnext->prev=list;
    }
    
    void deleteNode(node* list){
        node* listnext=list->next;
        node* listprev=list->prev;
        listprev->next=list->next;
        listnext->prev=list->prev;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key)!=mp.end()){
            node* x = mp[key];
            int val = x->val;
            mp.erase(key);
            deleteNode(x);
            addNode(x);
            mp[key] = head->next;
            return val;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here   
        if(mp.find(key)!=mp.end()){
            node* x = mp[key];
            mp.erase(key);
            deleteNode(x);
        }
        while(mp.size()>=capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node* x = new node(key,value);
        addNode(x);
        mp[key]=head->next;
    }
};
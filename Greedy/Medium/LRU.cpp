class node{
    public:
    node* next;
    node* prev;
    int val;
    node(int val_){
        val=val_;
        prev=NULL;
        next=NULL;
    }
};

class Solution{
public:
    node* head=new node(-1);
    node* tail=new node(-1);
    void insertNode(node* nodetoadd){
        node* nextnode=head->next;
        head->next=nodetoadd;
        nodetoadd->prev=head;
        nodetoadd->next=nextnode;
        nextnode->prev=nodetoadd;
    }
    void deleteNode(node* nodetodelete){
        node* prevnode=nodetodelete->prev;
        node* nextnode=nodetodelete->next;
        prevnode->next=nodetodelete->next;
        nextnode->prev=nodetodelete->prev;
    }
    
    int pageFaults(int N, int C, int pages[]){
        // code here
        // unordered_map<int,int> mp2;
        // for(int i=0;i<C;i++){
        //     // mp1[pages[i]]=i;
        //     mp2[pages[i]]=i;
        // }
        // int f=C;
        // for(int i=C;i<N;i++){
        //     if(mp2.find(pages[i])!=mp2.end()){
        //         mp2[pages[i]]=i;
        //         // mp1[pages[i]]=i;
        //     }
        //     else{
        //         f++;
        //         int mini=1000;
        //         int ans;
        //         for(auto x:mp2){
        //             if(x.second<mini){
        //                 mini=x.second;
        //                 ans=x.first;
        //             }
        //         }
        //         mp2.erase(ans);
        //         mp2[pages[i]]=i;
        //         // mp1[pages[i]]=i;
        //     }
        // }
        // return f;
        
        unordered_map<int,node*> mp;
        head->next=tail;
        tail->prev=head;
        int cnt=0;
        for(int i=0;i<N;i++){
            if(mp.find(pages[i])!=mp.end()){
                node* x=mp[pages[i]];
                deleteNode(x);
                insertNode(x);
            }
            else{
                if(mp.size()==C){
                    // deletefromTail();
                    mp.erase(tail->prev->val);
                    deleteNode(tail->prev);
                }
                    node* newnode = new node(pages[i]);
                    insertNode(newnode);
                    mp[pages[i]]=newnode;
                    cnt++;
            }
        }
        return cnt;
    }
};
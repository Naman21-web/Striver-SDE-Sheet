void swap(int* a,int* b){
      int temp = *a;
      *a=*b;
      *b=temp;
  }
  void restore(Node* root){
      Node* first=NULL;
      Node* mid=NULL;
      Node* last=NULL;
      Node* prev=NULL;
      calcPointers(root,&first,&mid,&last,&prev);
      if(first&&last) swap(&(first->data),&(last->data));
      else if(first && mid) swap(&(first->data),&(mid->data));
  }
  void calcPointers(Node* root,Node** first,Node** mid,Node** last,Node** prev){
      if(root==NULL) return;
      calcPointers(root->left,first,mid,last,prev);
      if(*prev && root->data<(*prev)->data){
          if(!*first){
              *first=*prev;
              *mid=root;
          }
          else{
              *last=root;
          }
      }
      *prev=root;
      calcPointers(root->right,first,mid,last,prev);
  }
    void correctBST( struct Node* root )
    {
        // add code here.
        restore(root);
    }
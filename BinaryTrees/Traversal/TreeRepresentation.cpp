//User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution{
public:
    
    void create_tree(node* root, vector<int> &arr){
        //Your code goes here
         root->left=newNode(arr[1]);
        root->right=newNode(arr[2]);
        root->left->left=newNode(arr[3]);
        root->left->right=newNode(arr[4]);
        root->right->left=newNode(arr[5]);
        root->right->right=newNode(arr[6]);
        
    }

};
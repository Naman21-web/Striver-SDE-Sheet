bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if((r1 && !r2) || (!r1 && r2)) return false;
        if(r1==NULL && r2==NULL) return true;
        bool leftidentical = isIdentical(r1->left,r2->left);
        bool rightidentical = isIdentical(r1->right,r2->right);
        if(r1->data==r2->data) return rightidentical && leftidentical;
        return false;
    }
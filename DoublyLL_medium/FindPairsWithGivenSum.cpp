vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        if(head->next==NULL) return {};
        vector<pair<int,int>> ans;
        Node* temp1=head;
        Node* temp2=head;
        while(temp2->next){
            temp2 = temp2->next;
        }
        while(temp1->data < temp2->data){
            int sum = temp1->data+temp2->data;
            if(sum>target){
                temp2 = temp2->prev;
            }
            else if(sum<target) temp1=temp1->next;
            else{
                ans.push_back({temp1->data,temp2->data});
                temp1 = temp1->next;
                temp2 = temp2->prev;
            }
        }
        return ans;
    }
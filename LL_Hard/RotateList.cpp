int lengt(ListNode* temp){
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* newHead;
        ListNode* newTail;
        ListNode* temp=head;
        int l=lengt(temp);
        k = k%l;
        
        int pos=l-k;
        int cnt=0;
        while(temp->next!=NULL){
            cnt++;
            if(cnt==pos){
                newTail=temp;
            }
            if(cnt==pos+1) newHead=temp;
            temp=temp->next;
        }  
        newTail->next=NULL;    
        temp->next=head;
        return newHead;
    }
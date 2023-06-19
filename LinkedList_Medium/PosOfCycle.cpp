ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        if(fast->next==NULL || fast->next->next==NULL) return NULL;
        else{
            slow=head;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return fast;
        }
    }
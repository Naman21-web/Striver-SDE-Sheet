ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        return merge(sortList(head),sortList(fast));
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp=dummyNode;
        while(head1 && head2){
            if(head1->val>head2->val){
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
            else{
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            }
        }
        while(head1){
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }
        while(head2){
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
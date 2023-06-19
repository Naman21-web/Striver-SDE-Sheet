struct Node* reverse(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* currptr=head;
        Node* nextptr;
        Node* prevptr=NULL;
        while(currptr!=NULL){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr=nextptr;
        }
        return prevptr;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL || head->next==NULL) return true;
        Node* fast=head;
        Node* slow=head;
        Node* prev;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        fast=head;
        slow = reverse(slow);
        while(fast){
            if(fast->data != slow->data) return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
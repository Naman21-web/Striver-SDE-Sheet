class Solution {
public:
    ListNode* mergeList(ListNode* list1,ListNode* list2){
        if(list2==NULL) return list1;
        if(list1==NULL) return list2;
        ListNode* list3;
            if(list1->val<list2->val){
                list1->next = mergeList(list1->next,list2);
                return list1;
            }
            else{
                list2->next = mergeList(list1,list2->next);
                return list2;
            }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        while(lists.size()>1){
            lists.push_back(mergeList(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};
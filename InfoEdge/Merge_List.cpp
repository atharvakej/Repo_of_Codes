ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* newHead = dummy;
        ListNode* a = list1, *b = list2;
        while(a && b){
            if(a->val<b->val){
                dummy->next = a;
                dummy = dummy->next;
                a = a->next;
            }
            else{
                dummy ->next = b;
                dummy = dummy->next;
                b = b->next;
            }
        }
        while(a){
            dummy ->next = a;
            dummy = dummy->next;
            a = a->next;
        }
        while(b){
            dummy ->next = b;
            dummy = dummy->next;
            b = b->next;
        }
        return newHead->next;
    }
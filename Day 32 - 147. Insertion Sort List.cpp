class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans = new ListNode(-6000);
        while(head){
            ListNode* curr = ans , *prev = ans;
            while(curr and curr -> val < head -> val){
                prev = curr;
                curr = curr -> next;
            }
            prev -> next = head; 
            head = head -> next; // go to next node before linking the two parts.
            prev -> next -> next = curr; // curr points to the node whose value is just greater than head -> val
        }   
        return ans -> next;
    }
};

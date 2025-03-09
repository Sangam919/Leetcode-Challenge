class Solution {
public:
    ListNode*reverse_LL(ListNode*head){
        if(head==nullptr || head->next==nullptr)return head;
        ListNode*last=nullptr;
        ListNode*prev=head;
        ListNode*curr = head->next;
        while(curr!=nullptr){
            prev->next = last;
            last=prev;
            prev=curr;
            curr=curr->next;
        }
        prev->next = last;
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode*newhead = head;
        newhead=reverse_LL(newhead);
        ListNode*last=newhead;
        ListNode*temp = newhead->next;
        int maxi = newhead->val;
        while(temp!=nullptr){
            if(temp->val<maxi){
                ListNode*curr = temp;
                temp=temp->next;
                last->next = temp;
            }else{
                maxi=max(maxi,temp->val);
                last=temp;
                temp=temp->next;
            }
        }
        newhead = reverse_LL(newhead);
        return newhead;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        vector<int>vec;
        ListNode*temp=head;
        while(temp){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        sort(vec.begin(),vec.end());
        for(auto num:vec){
            temp->val=num;
            temp=temp->next;
        }
        return head;
    }
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        
        map<int,int> hs ;
        
        for (auto i :nums)
            hs[i]++;
        
        ListNode* tmp = head;
        
        int ans = 0;
        
        while(tmp)
        {
            if(hs[tmp->val] !=0 )
            {
                while(tmp->next && hs[tmp->next->val] != 0 )
                {
                    tmp = tmp->next;
                }
                ans++;
            }
            tmp = tmp->next;
        }
        return ans;
    }
};

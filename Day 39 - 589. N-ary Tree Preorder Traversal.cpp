class Solution {
public:

void poh(Node *root, vector<int> &result)
{
    if (root == NULL)
    {
        return ; 
    }

    result.push_back(root -> val) ; 
    for (int i = 0 ; i < root -> children.size() ; i ++)
    {
        poh (root -> children[i], result) ;   
    }
}

    vector<int> preorder(Node* root) {
        vector<int> result ;
        poh (root, result) ; 

        return result; 
    }
};

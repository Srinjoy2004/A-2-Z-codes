//https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1

/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        // Code here
        
        if(root==NULL)
        return 0;
        else  if (root->left==NULL && root->right==NULL)  return 0;
        
        return(1+countNonLeafNodes(root->left)+countNonLeafNodes(root->right));
    }
};
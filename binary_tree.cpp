/* Review:Please give the following C++ code implementation：
  1.Create binary_tree
  2.preorder traversal
    2.1 recursion
    2.2 non_recursion
  3.inorder traversal
    3.1 recursion
    3.2 non_recursion
  4.postorder traversal
    4.1 recursion
    4.2 non_recursion
*/


//create binary_tree
TreeNode *root

//preorder tree

//InOrder traversal
////recursion
void InOrder(TreeNode *root){
  if(root==nullptr) return;
  InOrder(root->left);
  cout<<root->num<<endl;
  InOrder(root->right);
}
////non_recursion(difficult)
stack<TreeNode*> stack;
void InOrder(TreeNode *root){
  TreeNode *cur = root;
     while (cur != nullptr || !stack.empty()) {
        // Visit the left subtree first, and press the stack all the way
        while (cur != nullptr) {
            stack.push(cur);
            cur = cur->left;
        }
        // The current node is the top element of the stack
        cur = stack.top();
        stack.pop();
        // Access the top of the stack node
        std::cout << cur->num << " ";
        // Enter the right subtree
        cur = cur->right;
    }
}

//postorder tree

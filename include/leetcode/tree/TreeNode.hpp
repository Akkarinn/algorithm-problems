 #ifndef LEETCODE_TREE_TREE_NODE_HPP
 #define LEETCODE_TREE_TREE_NODE_HPP
 
 /**
  * Definition for a binary tree node.
  * 
  * Implementation from leetcode.
  */
 
namespace leetcode {
namespace tree {
     struct TreeNode {
         int val;
         TreeNode* left;
         TreeNode* right;

         TreeNode(int v)
            : val(v)
         {
         }
     };

     /**
      * Helper factory
      */
      struct Factory {
        static TreeNode* create(int v, TreeNode* left = 0, TreeNode* right = 0) {
            TreeNode* root(new TreeNode(v));
            root->left = left;
            root->right = right;
            return root;
         }
         static void destroy(TreeNode** root) {
            if (root && *root) {
                destroy(&((*root)->left));
                destroy(&((*root)->right));
                delete *root;
                *root = 0;
            }
         }
    };
}
}

#endif

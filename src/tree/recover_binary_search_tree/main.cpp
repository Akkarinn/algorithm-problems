/**
 * Source: https://leetcode.com/problems/recover-binary-search-tree/
 * 
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
#include <leetcode/tree/TreeNode.hpp>
 
 using leetcode::tree::TreeNode;
 using leetcode::tree::Factory;

 namespace {
 
   class Solution {
   public:
      void recoverTree(TreeNode* root) const {
         if (root) {
            std::vector<TreeNode*> badNodes;
            TreeNode* lastInOrder = 0;
            recoverTree(root, lastInOrder, badNodes);
            if (badNodes.size() == 2)
               std::swap(badNodes.front()->val, badNodes.back()->val);
            else if (badNodes.size() == 4)
               std::swap(badNodes[1]->val, badNodes[2]->val);
         }
      }
   private:
      void recoverTree(TreeNode* node, TreeNode*& lastInOrder, std::vector<TreeNode*>& badNodes) const {
         if (node) {
            recoverTree(node->left, lastInOrder, badNodes);

            if (lastInOrder && node->val < lastInOrder->val) {
               badNodes.push_back(node);
               badNodes.push_back(lastInOrder);
            }
            lastInOrder = node;

            recoverTree(node->right, lastInOrder, badNodes);
         }
      }
   }; 

}

TEST_CASE( "Recover Binary Search Tree", "[test]" ) {
   Solution solver;
   TreeNode* root = 0;
   {
      // Test in same sub tree.
      root =
         Factory::create(4,            // should be 5
            Factory::create(2,
               Factory::create(1),
               Factory::create(5)),    // should be 4
            Factory::create(8,
               Factory::create(7)));

      solver.recoverTree(root);

      CHECK(root->val == 5);
      CHECK(root->left->val == 2);
      CHECK(root->left->left->val == 1);
      CHECK(root->left->right->val == 4);
      CHECK(root->right->val == 8);
      CHECK(root->right->left->val == 7);
      Factory::destroy(&root);
   }
   {
      // Test in same different trees.
      root =
         Factory::create(5,
            Factory::create(2,
               Factory::create(8),     // should be 1
               Factory::create(4)),
            Factory::create(1,         // should be 8
               Factory::create(7)));

      solver.recoverTree(root);

      CHECK(root->val == 5);
      CHECK(root->left->val == 2);
      CHECK(root->left->left->val == 1);
      CHECK(root->left->right->val == 4);
      CHECK(root->right->val == 8);
      CHECK(root->right->left->val == 7);
      Factory::destroy(&root);
   }
}

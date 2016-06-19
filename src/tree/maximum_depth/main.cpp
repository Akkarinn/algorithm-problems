/**
 * Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * 
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
#include <leetcode/tree/TreeNode.hpp>
 
 using leetcode::tree::TreeNode;
 using leetcode::tree::Factory;

 namespace {
 
   class Solution {
   public:
      int maxDepth(TreeNode* root) const {
        return root ? 1 + std::max(maxDepth(root->left), maxDepth(root->right)) : 0;
      }
   }; 

}

TEST_CASE( "Maximum Depth of Binary Tree", "[test]" ) {
    Solution solver;
    TreeNode* root = 0;

    CHECK( solver.maxDepth(root) == 0);

    root = Factory::create(1);
    CHECK( solver.maxDepth(root) == 1);
    Factory::destroy(&root);

    root =
        Factory::create(1,
            Factory::create(11));
    CHECK( solver.maxDepth(root) == 2);
    Factory::destroy(&root);

    root =
        Factory::create(1,
            Factory::create(11,
                Factory::create(111)));
    CHECK( solver.maxDepth(root) == 3);
    Factory::destroy(&root);

    root =
        Factory::create(1,
            Factory::create(11,
                Factory::create(111)),
            Factory::create(12));
    CHECK( solver.maxDepth(root) == 3);
    Factory::destroy(&root);
}

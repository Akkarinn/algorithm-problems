/**
 * Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * 
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
#include <leetcode/tree/TreeNode.hpp>

using leetcode::tree::TreeNode;
using leetcode::tree::Factory;

namespace {

   class Solution {
   public:
      int minDepth(TreeNode* root) const {
         if (root) {
            if (!root->left) {
               if (!root->right)
                     return 1;
               return 1 + minDepth(root->right);
            }
            else if (!root->right) {
               return 1 + minDepth(root->left);
            }
            else {
               return 1 + std::min(minDepth(root->left), minDepth(root->right));
            }
         }
         return 0;
      }
   };
}

TEST_CASE( "Minimum Depth of Binary Tree", "[test]" ) {
   Solution solver;
   TreeNode* root = 0;

   CHECK( solver.minDepth(root) == 0);

   root = Factory::create(1);
   CHECK( solver.minDepth(root) == 1);
   Factory::destroy(&root);

   root =
      Factory::create(1,
         Factory::create(11));
   CHECK( solver.minDepth(root) == 2);
   Factory::destroy(&root);

   root =
      Factory::create(1,
         Factory::create(11,
               Factory::create(111)));
   CHECK( solver.minDepth(root) == 3);
   Factory::destroy(&root);

   root =
      Factory::create(1,
         Factory::create(11,
               Factory::create(111)),
         Factory::create(12));
   CHECK( solver.minDepth(root) == 2);
   Factory::destroy(&root);
}

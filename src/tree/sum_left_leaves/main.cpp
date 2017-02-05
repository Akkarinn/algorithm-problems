/**
 * Source: https://leetcode.com/problems/sum-of-left-leaves/
 * 
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
#include <leetcode/tree/TreeNode.hpp>

using leetcode::tree::TreeNode;
using leetcode::tree::Factory;

namespace {

   class Solution {
      struct Result {
         bool isLeaf;
         int sum;
      };
   public:
      int sumOfLeftLeaves(const TreeNode* root) const {
         auto res = sumOfLeftLeavesImpl(root);
         return res.isLeaf ? 0 : res.sum;
      }
   private:
      Result sumOfLeftLeavesImpl(const TreeNode* root) const {
         Result res = { 0 };
         if (root) {
            if (! root->left && ! root->right)
               return {true, root->val};
            auto lRes = sumOfLeftLeavesImpl(root->left);
            auto rRes = sumOfLeftLeavesImpl(root->right);
            return {false, lRes.sum + (rRes.isLeaf ? 0 : rRes.sum)};
         }
         return {false, 0};
      }
   };
}

TEST_CASE( "Sum Left Leaves", "[test]" ) {
   Solution solver;
   TreeNode* root = 0;

   CHECK(solver.sumOfLeftLeaves(root) == 0);

   root = Factory::create(1);
   CHECK(solver.sumOfLeftLeaves(root) == 0);
   Factory::destroy(&root);

   root =
      Factory::create(1,
         Factory::create(11));
   CHECK(solver.sumOfLeftLeaves(root) == 11);
   Factory::destroy(&root);

   root =
      Factory::create(1,
         Factory::create(11,
            Factory::create(111)));
   CHECK(solver.sumOfLeftLeaves(root) == 111);
   Factory::destroy(&root);

   root =
      Factory::create(1,
         Factory::create(11,
            Factory::create(111)),
         Factory::create(12,
            Factory::create(121),
            Factory::create(122)));
   CHECK(solver.sumOfLeftLeaves(root) == 232);
   Factory::destroy(&root);

   root =
      Factory::create(3,
         Factory::create(9),
         Factory::create(20,
            Factory::create(15),
            Factory::create(7)));
   CHECK(solver.sumOfLeftLeaves(root) == 24);
   Factory::destroy(&root);
}

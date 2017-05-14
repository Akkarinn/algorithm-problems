/**
 * Source: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
 * 
 * You need to find the largest value in each row of a binary tree.
 *
 * Input:
 *
 *       1
 *      / \
 *     3   2
 *    / \   \  
 *   5   3   9 
 *
 * Output: [1, 3, 9].
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
#include <leetcode/tree/TreeNode.hpp>

#include <deque>
#include <vector>

using leetcode::tree::TreeNode;
using leetcode::tree::Factory;

namespace {

   class Solution {
   public:
      std::vector<int> largestValues(TreeNode* root) {
         std::vector<int> res;
         if (root) {
            std::deque<TreeNode*> nodes;

            auto currentLevelMax = root->val;
            auto newLevelMax = std::numeric_limits<int>::min();
            std::size_t remainingNodesInLevel = 1;

            nodes.push_back(root);
            while (!nodes.empty()) {
               auto current = nodes.front();
               if (current->left) {
                  newLevelMax = std::max(newLevelMax, current->left->val);
                  nodes.push_back(current->left);
               }
               if (current->right) {
                  newLevelMax = std::max(newLevelMax, current->right->val);
                  nodes.push_back(current->right);
               }
               nodes.pop_front();

               if (--remainingNodesInLevel == 0) {
                  res.push_back(currentLevelMax);
                  currentLevelMax = newLevelMax;
                  newLevelMax = std::numeric_limits<int>::min();
                  remainingNodesInLevel = nodes.size();
               }
            }
         }
         return res;
      }
   };
}

#define COMA ,

TEST_CASE( "Find Largest Value in Each Tree Row", "[test]" ) {
   Solution solver;
   TreeNode* root = 0;

   CHECK(solver.largestValues(root) == std::vector<int>{});

   root = Factory::create(1);
   CHECK(solver.largestValues(root) == std::vector<int>{1});
   Factory::destroy(&root);

   root =
      Factory::create(1,
         Factory::create(11));
   CHECK(solver.largestValues(root) == std::vector<int>{1 COMA 11});
   Factory::destroy(&root);

   root =
      Factory::create(1,
         Factory::create(11,
            Factory::create(111)));
   CHECK(solver.largestValues(root) == std::vector<int>{1 COMA 11 COMA 111});
   Factory::destroy(&root);

   root =
      Factory::create(1,
         Factory::create(11,
            Factory::create(111)),
         Factory::create(12,
            Factory::create(121),
            Factory::create(122)));
   CHECK(solver.largestValues(root) == std::vector<int>{1 COMA 12 COMA 122});
   Factory::destroy(&root);

   root =
      Factory::create(3,
         Factory::create(9,
            Factory::create(16)),
         Factory::create(20,
            Factory::create(15),
            Factory::create(7)));
   CHECK(solver.largestValues(root) == std::vector<int>{3 COMA 20 COMA 16});
   Factory::destroy(&root);
}

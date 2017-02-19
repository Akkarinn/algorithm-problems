/**
 * Source: https://leetcode.com/problems/find-bottom-left-tree-value/
 * 
 * Given a binary tree, find the leftmost value in the last row of the tree.
 *
 * Example 1:
 * Input:
 *   2
 *  / \
 * 1   3
 * Output: 1
 *
 * Example 2:
 * Input:
 *      1
 *     / \
 *    2   3
 *   /   / \
 *  4   5   6
 * /
 * 7
 * Output: 7
 *
 * Note: You may assume the tree (i.e., the given root node) is not NULL.
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
#include <leetcode/tree/TreeNode.hpp>
 
 using leetcode::tree::TreeNode;
 using leetcode::tree::Factory;

 #include <deque>

 namespace {
 
   class Solution {
   public:
      int findBottomLeftValue(const TreeNode* root) const {
         if (! root)
            return 0;
         const TreeNode* lastFirstNode = root;
         std::deque<const TreeNode*> nodes;
         nodes.push_back(root);
         nodes.push_back(0);
         bool isNewHeight = true;
         while (nodes.size() > 1) {
            auto currentNode = nodes.front();
            if (isNewHeight) {
               lastFirstNode = currentNode;
               isNewHeight = false;
            } 
            if (currentNode) {
               if (currentNode->left)
                  nodes.push_back(currentNode->left);
               if (currentNode->right)
                  nodes.push_back(currentNode->right);
            }
            else {
               isNewHeight = true;
               nodes.push_back(0);
            }
            nodes.pop_front();
         }
         return lastFirstNode->val;
      }
   }; 

}

TEST_CASE( "Find Bottom Left Tree Value", "[test]" ) {
    Solution solver;
    TreeNode* root = 0;

    CHECK( solver.findBottomLeftValue(root) == 0);

    root = Factory::create(1);
    CHECK( solver.findBottomLeftValue(root) == 1);
    Factory::destroy(&root);

    root =
        Factory::create(1,
            Factory::create(11));
    CHECK( solver.findBottomLeftValue(root) == 11);
    Factory::destroy(&root);

    root =
        Factory::create(1,
            Factory::create(11,
                Factory::create(111)));
    CHECK( solver.findBottomLeftValue(root) == 111);
    Factory::destroy(&root);

    root =
       Factory::create(1,
          Factory::create(11,
             Factory::create(111,
                Factory::create(1111))),
          Factory::create(12));
    CHECK(solver.findBottomLeftValue(root) == 1111);
    Factory::destroy(&root);

    root =
       Factory::create(1,
          Factory::create(11,
             Factory::create(111)),
          Factory::create(12,
             Factory::create(121),
             Factory::create(122)));
    CHECK(solver.findBottomLeftValue(root) == 111);
    Factory::destroy(&root);
}

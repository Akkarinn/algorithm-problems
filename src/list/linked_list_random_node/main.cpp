/**
 * Source: https://leetcode.com/problems/linked-list-random-node
 * 
 * Given a singly linked list, return a random node's value from the linked list.
 * Each node must have the same probability of being * chosen.
 *
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you?
 * Could you solve this efficiently without using extra space?
 */
#define CATCH_CONFIG_MAIN 
#include <catch/catch.hpp>
#include <leetcode/list/ListNode.hpp>

using leetcode::list::ListNode;
using leetcode::list::Factory;

#include <unordered_set>

namespace {

   class Solution {
   public:
      /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
      Solution(ListNode* head)
         : m_head(head)
      {
         assert(head);
         std::srand(std::time(0));
      }

      /** Returns a random node's value. */
      int getRandom() {
         int len = 1;
         auto curr = m_head;
         auto selected = curr;
         while (curr) {
            if ((std::rand() % len) == 0)
               selected = curr;
            ++len;
            curr = curr->next;
         }
         return selected->val;
      }

   private:
      ListNode* m_head;
   };
}      

namespace {
   bool TestAndValidateResults(int nbElements) {
      auto head = Factory::create(0);
      auto curr = head;
      for (auto i = 1; i < nbElements; ++i) {
         curr->next = Factory::create(i);
         curr = curr->next;
      }

      Solution solution(head);
      std::unordered_set<int> randomNodes;
      auto thresholIteration = nbElements*100;
      for (auto i = 0; i < thresholIteration; ++i)
         randomNodes.insert(solution.getRandom());

      auto isValid = (randomNodes.size() == nbElements);
      for (auto i = 0; isValid && i < nbElements; ++i)
         isValid = (randomNodes.find(i) != randomNodes.end());
      return isValid;
   }
}
TEST_CASE("Linked List Random Node", "[test]") {
   CHECK(TestAndValidateResults(1));
   CHECK(TestAndValidateResults(2));
   CHECK(TestAndValidateResults(10));
   CHECK(TestAndValidateResults(100));
}

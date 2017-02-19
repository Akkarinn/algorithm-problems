#ifndef LEETCODE_LIST_LIST_NODE_HPP
#define LEETCODE_LIST_LIST_NODE_HPP

/**
* Definition for singly-linked list.
*
* Implementation from leetcode.
*/

namespace leetcode {
   namespace list {
      struct ListNode {
         int val;
         ListNode* next;
         ListNode(int x)
            : val(x)
            , next(NULL)
         {}
      };

      /**
      * Helper factory
      */
      struct Factory {
         static ListNode* create(int v, ListNode* tail = 0) {
            ListNode* head(new ListNode(v));
            head->next = tail;
            return head;
         }
         static void destroy(ListNode** head) {
            if (head && *head) {
               destroy(&((*head)->next));
               delete *head;
               *head = 0;
            }
         }
      };
   }
}

#endif

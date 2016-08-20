// http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-k-sorted-lists.html

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge2Lists (ListNode *h1, ListNode *h2) {
        ListNode *fakeHead = new ListNode (-1), *p = fakeHead;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                p->next = h1;
                h1 = h1->next;
            }
            else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        if (h1 && !h2)
            p->next = h1;
        else if (!h1 && h2)
            p->next = h2;
        return fakeHead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() <= 0)
            return NULL;
        int begin = 0, end = lists.size() - 1;
        while (end > 0) {
            begin = 0;
            while (begin < end) {
                lists[begin] = merge2Lists (lists[begin], lists[end]);
                begin++;
                end--;
            }
        }
        return lists[0];
    }
};

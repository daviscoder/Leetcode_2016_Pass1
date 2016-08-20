/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        unordered_map<RandomListNode *, RandomListNode *> myMap;
        RandomListNode *p = head;
        RandomListNode *newHead = new RandomListNode (head->label), *q = newHead;
        myMap[p] = q;
        while (p) {
            if (p->next) {
                if (myMap.count(p->next) == 0) {
                    q->next = new RandomListNode (p->next->label);
                    myMap[p->next] = q->next;
                }
                else {
                    q->next = myMap[p->next];
                }
            }
            if (p->random) {
                if (myMap.count(p->random) == 0) {
                    q->random = new RandomListNode (p->random->label);
                    myMap[p->random] = q->random;
                }
                else {
                    q->random = myMap[p->random];
                }
            }
            q = q->next;
            p = p->next;
        }
        return newHead;
    }
};

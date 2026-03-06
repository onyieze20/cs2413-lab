// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
// Edge cases: 0 or 1 node => nothing to swap
if (head == NULL || head->next == NULL) {
return head;
}

// After the first swap, the second node becomes the new head
struct ListNode* newHead = head->next;

struct ListNode* prev = NULL; // tail of the last swapped pair
struct ListNode* curr = head; // first node in the current pair

while (curr != NULL && curr->next != NULL) {
struct ListNode* second = curr->next; // second node in pair
struct ListNode* nextPair = second->next; // start of next pair

// Swap the pair by rewiring pointers
second->next = curr;
curr->next = nextPair;

// Connect previous swapped pair to this swapped pair
if (prev != NULL) {
prev->next = second;
}

// Move forward: 'curr' is now the tail of the swapped pair
prev = curr;
curr = nextPair;
}

return newHead;
}
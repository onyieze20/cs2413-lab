#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1009

static int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

static void insert(Node* table[], int key, int value) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[idx];
    table[idx] = newNode;
}

static int find(Node* table[], int key, int* value) {
    int idx = hash(key);
    Node* curr = table[idx];

    while (curr != NULL) {
        if (curr->key == key) {
            *value = curr->value;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[TABLE_SIZE] = { 0 };

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex;

        if (find(table, complement, &foundIndex)) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            freeTable(table);
            return result;
        }

        insert(table, nums[i], i);
    }

    *returnSize = 0;
    freeTable(table);
    return NULL;
}
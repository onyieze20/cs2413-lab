#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* res = (int*)calloc((digitsSize + 1), sizeof(int));
    for (int i = 0; i < digitsSize; i++) res[i] = digits[i];
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (res[i] != 9) {
            res[i] += 1;
            *returnSize = digitsSize;
            return res;
        }
        else res[i] = 0;
    }
    res[0] = 1;
    *returnSize = digitsSize + 1;
    return res;
   
}

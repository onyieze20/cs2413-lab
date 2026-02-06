#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    if (nums == NULL || out_i == NULL || out_j == NULL || out_k == NULL) return 0;
    if (n < 3) return 0;

    for (int i = 0; i < n - 2; ++i) {
        int L = i + 1;
        int R = n - 1;

        while (L < R) {
            long long sum = (long long)nums[i] + (long long)nums[L] + (long long)nums[R];
            if (sum == 0) {
                *out_i = i;
                *out_j = L;
                *out_k = R;
                return 1;
            } else if (sum < 0) {
                ++L;
            } else {
                --R;
            }
        }
    }

    return 0;
}

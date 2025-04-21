#include <stdio.h>

int main() {
    int n, target;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &target);

    int found = 0;
    for (int i = 0; i < n - 1 && !found; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("[%d, %d]\n", i, j);
                found = 1;
                break;
            }
        }
    }

    return 0;
}
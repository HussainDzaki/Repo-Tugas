#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int start = (i + 1) * (i + 2) / 2;
        int row[n];
        row[0] = start;
        for (int j = 1; j < n; j++) {
            if (j - 1 < (n - i - 1)) {
                int increment = (i + 1) + (j - 1);
                row[j] = row[j - 1] + increment;
            } else {
                int m = (j - 1) - (n - i - 1);
                int increment = (i + 1) + (n - i - 2) - m;
                row[j] = row[j - 1] + increment;
            }
        }
        for (int j = 0; j < n; j++) {
            printf("%d ", row[j]);
        }
        printf("\n");
    }
    return 0;
}
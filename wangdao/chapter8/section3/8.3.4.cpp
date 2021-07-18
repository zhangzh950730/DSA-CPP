//
// Created by zhang on 2021/7/17.
//


int setPartition(int a[], int n) {
    int pivotKey, low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n / 2, i;
    int s1 = 0, s2 = 0;
    while (flag) {
        pivotKey = a[low];
        while (low < high) {
            while (low < high && a[high] > pivotKey) {
                high--;
            }
            if (low != high) {
                a[low] = a[high];
            }

            while (low < high && a[low] < pivotKey) {
                low++;
            }
            if (low != high) {
                a[high] = a[low];
            }
        }
        a[low] = pivotKey;
        if (low == k - 1) {
            flag = 0;
        } else {
            if (low < k - 1) {
                low0 = ++low;
                high = high0;
            } else {
                high0 = --high;
                low = low0;
            }
        }
    }
    for (i = 0; i < k; i++) {
        s1 += a[i];
    }
    for (i = k; i < n; i++) {
        s2 += a[i];
    }
    return s2 - s1;
}


typedef enum {
    RED, WHITE, BLUE
} Color;

void swap(Color *a, int j, int k) {
    Color temp = a[j];
    a[j] = a[k];
    a[k] = temp;
}

void flagArrange(Color a[], int n) {
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        switch (a[j]) {
            case RED:
                swap(a, i++, j++);
                break;
            case WHITE:
                j++;
                break;

            case BLUE:
                swap(a, j, k--);
                break;
        }
    }
}

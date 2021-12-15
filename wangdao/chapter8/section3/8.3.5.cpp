//
// Created by 张之豪 on 2021/12/14.
//

int solution(int a[], int low, int high, int k) {
    int pivot = a[low];
    int low_temp = low, high_temp = high;
    while (low < high) {
        while (low < high && a[high] >= pivot) {
            --high;
        }
        a[low] = a[high];

        while (low < high && a[low] <= pivot) {
            ++low;
        }
        a[high] = a[low];
    }
    a[low] = pivot;
    if (low == k) {
        return a[low];
    } else if (low > k) {
        return solution(a, low_temp, low - 1, k);
    } else {
        return solution(a, low + 1, high_temp, k);
    }
}
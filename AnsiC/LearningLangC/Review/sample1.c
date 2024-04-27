#include <stdio.h>

// 删除数组中指定位置的元素
void deleteElement(int arr[], int *prN, int position) {
    if (position < 0 || position >= *prN) {
        printf("Invalid position\n");
        return;
    }

    // 将元素向前移动
    for (int i = position; i < *prN - 1; ++i) {
        arr[i] = arr[i+1];
    }

    (*prN)--;  // 数组大小减小
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int position = 2;

    // 调用删除元素函数
    deleteElement(arr, &n, position);

    // 输出删除元素后的数组
    printf("Array after deletion: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
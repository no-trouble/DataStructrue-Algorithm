//
//  main.c
//  Sort
//
//  Created by lishuai on 2018/11/6.
//  Copyright © 2018 lishuai. All rights reserved.
//

#include <stdio.h>

void printArray(int *a, int n) {
    printf("array: ");
    for (int i = 0; i < n; i++) {
//        printf("%d:(%p)\t", a[i], &(a[i]));
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int find_min(int arr[], int len) {
    int idx = 0;
    for (int i = 1; i<len; i++) {
        if (arr[i] < arr[idx]) {
            idx = i;
        }
    }
    return idx;
}
/// 核心思想： 比较 + 交换
void bubble_sort(int a[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - 1 - i; j++) {
//            if (a[j] > a[j+1]) {
//                swap(&(a[j]), &(a[j+1]));
//            }
//        }
//    }
    int i = 0, s = 0;
    while (i < n - 1) {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                s++;
                swap(&(a[j]), &(a[j+1]));
                flag = 1;
            }
        }
        i++;
        if (flag == 0) {
            break;
        }
    }
    printf("bubble = %d, swap count = %d\n", i, s);
}
/// 核心思想： 比较 + 移动
void insertion_sort(int arr[], int len) {
    printf("--------------------------------------------------------------------------------\n");
    int i, j, key;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
//        while (j >= 0 && arr[j] > key) {
//            arr[j+1] = arr[j];
//            j--;
//        }
        for (; j>=0; j--) {
            if (arr[j] > key) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = key;
        printArray(arr, len);
    }
    printf("--------------------------------------------------------------------------------\n");
}

//void selection_sort(int arr[], int len) {
//    int idx;
//    printf("--------------------------------------------------------------------------------\n");
//    for (int i = 0; i < len-1; i++) {
//        idx = i;
//        for (int j = i+1; j<len; j++) {
//            if (arr[j] < arr[idx]) {
//                idx = j;
//            }
//        }
//        if (idx == i) {
//            continue;
//        }
//        swap(&arr[i], &arr[idx]);
//        printArray(arr, len);
//    }
//    printf("--------------------------------------------------------------------------------\n");
//}

//void selection_sort(int arr[], int len) {
//    int i = 0, j, idx;
//    while (i < len-1) {
//        j = i+1;
//        idx = i;
//        while (j<len) {
//            if (arr[j] < arr[idx]) {
//                idx = j;
//            }
//            j++;
//        }
//        if (idx == i) {
//            i++;
//            continue;
//        }
//        swap(&arr[i], &arr[idx]);
//        i++;
//    }
//}

//void selection_sort(int arr[], int len) {
//    int i = 0, idx;
//    while (i < len-1) {
//        idx = i;
//        for (int j = i+1; j<len; j++) {
//            if (arr[j] < arr[idx]) {
//                idx = j;
//            }
//        }
//        if (idx == i) {
//            i++;
//            continue;
//        }
//        swap(&arr[i], &arr[idx]);
//        i++;
//    }
//}
/// 核心思想： 比较 + 交换
void selection_sort(int arr[], int len) {
    int i = 0, idx, j;
    for (; i < len-1; i++) {
        idx = i;
        j = i+1;
        while (j<len) {
            if (arr[j] < arr[idx]) {
                idx = j;
            }
            j++;
        }
        if (idx == i) {
            continue;
        }
        swap(&arr[i], &arr[idx]);
    }
}

/*
 归并排序： 分治思想，通过递归技巧实现
 递推公式: merge_sort(p...r) = merge(merge_sort(p...q), merge_sort(q+1...r))
 终止条件: p >= r
 
 merge_sort(arr)  0..<10
 arr1 = merge_sort(arr[0]...arr[4])
 arr2 = merge_sort(arr[5]...arr[9])
 merge(arr1, arr2)
 */
void merge_sort_imp(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);
void merge_sort(int arr[], int len) {
    merge_sort_imp(arr, 0, len-1);
}

void merge_sort_imp(int arr[], int p, int r) {
    if (p >= r)  {
        return;
    }
    int q = (p+r)/2;
    merge_sort_imp(arr, p, q);
    merge_sort_imp(arr, q+1, r);
    merge(arr, p, q, r);
}

void merge(int arr[], int p, int q, int r) {
    int *tmp = (int *)malloc(sizeof(int)*(r-p+1));
    if (!tmp) {
        abort();
    }
    int i = p, j = q+1, k = 0;
    while (i < q && j < r) {
        if (arr[i] < arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while (i < p) {
        tmp[k++] = arr[i++];
    }
    while (j < r) {
        tmp[k++] = arr[j++];
    }
    for (int i = 0; i<=r; i++) {
        arr[i] = tmp[i];
    }
}

void mergearray(int a[], int first, int mid, int last, int temp[]) {
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;
    
    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    
    while (i <= m)
        temp[k++] = a[i++];
    
    while (j <= n)
        temp[k++] = a[j++];
    
    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}

int main(int argc, const char * argv[]) {
    
//    int arr[] = { 3, 5, 4, 1, 2, 6 };
//    int arr[] = { 1, 2, 3, 4, 5, 6, 5 };
    int arr[] = { 6, 5, 4, 3, 2, 1, 7, 8 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    printArray(arr, len);
    
//    bubble_sort(arr, len);
//    insertion_sort(arr, len);
//    selection_sort(arr, len);
//    mergesort2(arr, 0, len-1, arr2);
    merge_sort(arr, len);
    
    printArray(arr, len);
    
    return 0;
}


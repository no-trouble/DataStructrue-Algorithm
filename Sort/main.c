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

int main(int argc, const char * argv[]) {
    
    int arr[] = { 3, 5, 4, 1, 2, 6 };
//    int arr[] = { 1, 2, 3, 4, 5, 6, 5 };
//    int arr[] = { 6, 5, 4, 3, 2, 1 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    printArray(arr, len);
    
//    bubble_sort(arr, len);
//    insertion_sort(arr, len);
    selection_sort(arr, len);
    printArray(arr, len);
    
    return 0;
}


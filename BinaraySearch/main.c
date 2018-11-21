//
//  main.c
//  BinaraySearch
//
//  Created by lishuai on 2018/11/21.
//  Copyright © 2018 lishuai. All rights reserved.
//

#include <stdio.h>

/*
 二分查找算法要求:
 ①数据结构为线性结构的顺序存储(数组)
 ②序列有序
 时间复杂度: O(㏒n)
 
 */
int binaray_search(int a[], int len, int val) {
    int low = 0, high = len-1, mid;
    while (low <= high) {
        mid = low+((high-low)>>1);
        if (a[mid] == val) {
            return mid;
        } else if (a[mid] < val) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}

int b_search(int a[], int low, int high, int val) {
    if (low > high) {
        return -1;
    }
    int mid = low + ((high-low)>>1);
    if (a[mid] == val) {
        return mid;
    } else if (a[mid] < val) {
        return b_search(a, mid+1, high, val);
    } else {
        return b_search(a, low, mid-1, val);
    }
}

int binaray_search2(int a[], int len, int val) {
    return b_search(a, 0, len-1, val);
}

int main(int argc, const char * argv[]) {
    int a[6] = { 2, 3, 4, 5, 6, 7 };
    int length = (int)sizeof(a)/sizeof(*a);
    int idx;
//    idx = binaray_search(a, length, 7);
    idx = binaray_search2(a, length, 5);
    printf("idx = %d\n", idx);
    
    return 0;
}

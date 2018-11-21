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
 { 1, 3, 4, 5, 6, 8, 8, 8, 11, 18 }
 { 1, 2, 2, 3}
 */
int binaray_search(int a[], int len, int val) {
    int low = 0, high = len-1, mid;
    while (low <= high) {
        mid = low+((high-low)>>1);
        if (a[mid] == val) {
            if (mid == 0 || a[mid-1] != val) { // 1.mid 等于0说明该元素已经是数组的第一个元素；2.如果 mid 不等于0，如果 mid 的前一个元素不等于 val 的时候也说明 mid 下标的元素的就是第一个等于 val 的元素
                return mid;
            } else {
                high = mid-1;
            }
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
        if (mid == 0 || a[mid-1] != val) {
            return mid;
        } else {
            return b_search(a, low, mid-1, val);
        }
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
    int a[] = { 1, 3, 4, 5, 6, 8, 8, 8, 11, 18 };
//    int a[] = { 2, 3, 4, 5, 6, 7 };
    int length = (int)sizeof(a)/sizeof(*a);
    int idx;
    idx = binaray_search(a, length, 8);
//    idx = binaray_search2(a, length, 8);
    printf("idx = %d\n", idx);
    
    return 0;
}

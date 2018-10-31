//
//  main.cpp
//  Demo_cpp
//
//  Created by lishuai on 2018/10/23.
//  Copyright © 2018年 lishuai. All rights reserved.
//

#include <iostream>
#include <stack>
#include "LinkedList.hpp"
#include <string>

using namespace std;

struct LListNode {
    int _val;
    LListNode *_next;
    LListNode(int x) : _val(x), _next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(LListNode *head) {
        if (!head || !head->_next) {
            return true;
        }
        LListNode *fp = head, *sp = head;
        std::stack<int> s;
        s.push(head->_val);
        while (fp->_next && fp->_next->_next) {
            fp = fp->_next->_next;
            sp = sp->_next;
            s.push(sp->_val);
        }
        if (!fp->_next) {
            s.pop();
        }
        while (sp->_next) {
            sp = sp->_next;
            int tmp = s.top();
            s.pop();
            if (tmp != sp->_val) {
                return false;
            }
        }
        return true;
    }
    
    bool hasCycle(LListNode *head) {
        LListNode *fp = head, *sp = head;
        while (fp && fp->_next) {
            fp = fp->_next->_next;
            sp = sp->_next;
            if (fp == sp) {
                return true;
            }
        }
        return false;
    }
};

bool CheckPalindromeList(LinkedList *list) {
    // 使用快慢指针找链表中点
    ListNode *slow, *fast, *mid2 = nullptr;
    slow = list -> head;
    fast = list -> head;
    while (fast -> next != nullptr) {
        slow = slow -> next;
        fast = fast -> next;
        if (fast -> next != nullptr) {
            fast = fast -> next;
            mid2 = slow -> next;
        } else {
            mid2 = nullptr;
        }
    }
    
    // 从中点向后逆转链表（区分奇偶情况）
    ListNode *mid = slow;
    ListNode *elem, *prev, *save;
    if (mid2 == nullptr) {  // odd
        elem = mid;
        prev = mid -> next;
    } else {  // even
        elem = mid2;
        prev = mid2 -> next;
        mid2 -> next = nullptr;
    }
    save = prev -> next;
    mid -> next = nullptr;
    while (save != nullptr) {
        prev -> next = elem;
        elem = prev;
        prev = save;
        save = save -> next;
    }
    prev -> next = elem;
    
    ListNode *end = prev;
    ListNode *front = list -> head -> next;
    
    // 从头尾同时遍历比较，检测链表是否为回文
    bool palindrome = true;
    while (front != end) {
        // printf("%d, %d\n", front -> val, end -> val);
        if (front -> val != end -> val) {
            palindrome = false;
            break;
        }
        front = front -> next;
        end = end -> next;
    }
    
    palindrome ? printf("The list is palindrome~\n") : printf("The list is not palindrome!\n");
    
    return palindrome;
}

bool isValid(string s) {
    if (s.length() == 0) {
        return true;
    }
    unsigned long length = s.size();
    stack<char> c_stack;
    for (int i = 0; i < length; i++) {
        cout << s[i] << endl;
        if (s[i] == '(') {
            c_stack.push(s[i]);
        } else if (s[i] == '[') {
            c_stack.push(s[i]);
        } else if (s[i] == '{') {
            c_stack.push(s[i]);
        } else if (s[i] == ')' && c_stack.top() == '(') {
            c_stack.pop();
        } else if (s[i] == ']' && c_stack.top() == '[') {
            c_stack.pop();
        } else if (s[i] == '}' && c_stack.top() == '{') {
            c_stack.pop();
        }
    }
    if (c_stack.size() > 0) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    {
        /*
        LListNode *node1 = new LListNode(1);
        LListNode *node2 = new LListNode(2);
        LListNode *node5 = new LListNode(3);
        LListNode *node3 = new LListNode(2);
        LListNode *node4 = new LListNode(1);
        node1->_next = node2;
        node2->_next = node5;
        node5->_next = node3;
        node3->_next = node4;
        node4->_next = NULL;
        
        Solution *sol = new Solution();
    //    bool isPalindrome = sol->isPalindrome(node1);
    //    std::cout << "is palindrome = " << isPalindrome << std::endl;
        
        bool hasCycle = sol->hasCycle(node1);
        std::cout << "has cycle = " << hasCycle << std::endl;*/
    }
    {
        int init[] = {1, 2, 3, 2, 1};
        LinkedList *list = new LinkedList(5);
        for (int i = 0; i < 5; i++) {
            list -> InsertElemAtBack(init[i]);
        }
        list -> PrintList();
        
        CheckPalindromeList(list);  // true
        
        list -> InsertElemAtFront(5);
        list->PrintList();
        CheckPalindromeList(list);  // false
        
        
        int init2[] = {1, 2, 3, 3, 2, 1};
        LinkedList *list2 = new LinkedList(10);
        for (int i = 0; i < 6; i++) list2 -> InsertElemAtBack(init2[i]);
        list2 -> PrintList();
        CheckPalindromeList(list2);
        
        list2 -> InsertElemAtBack(4);
        list->PrintList();
        CheckPalindromeList(list2);
    }
    {
        string s = "([{{}])";
        cout << isValid(s) << endl;
    }
    return 0;
}
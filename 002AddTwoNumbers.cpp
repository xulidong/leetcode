/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
*/

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tmp = NULL;
        int pre = 0;
        while(l1 || l2) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + pre;
            if (sum < 10) {
                pre = 0;
            } else {
                pre = 1;
                sum %= 10;
            }
            ListNode* node = new ListNode(sum);
            if (tmp) {
                tmp->next = node;
                tmp = node;
            } else {
                head = node;
                tmp = node;
            }
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (pre > 0) {
            ListNode* node = new ListNode(pre);
            tmp->next = node;
        }
        return head;
    }
};

int main() {
    // init list 1: 3 4 2
    ListNode e11(2);
    ListNode e12(4);
    ListNode e13(3);

    ListNode* l1 = &e13;
    e13.next = &e12;
    e12.next = &e11;

    // init list 2: 4 6 5
    ListNode e21(5);
    ListNode e22(6);
    ListNode e23(4);

    ListNode* l2 = &e23;
    e23.next = &e22;
    e22.next = &e21;

    Solution sol;
    ListNode* l = sol.addTwoNumbers(l1, l2); 

    ListNode* tmp = l;
    while(tmp) {
        cout << tmp->val << endl;
        tmp = tmp->next; 
    }

    while(l) {
        tmp = l;
        l = l->next;
        delete tmp;
        tmp = NULL;
    }

    return 0;
}
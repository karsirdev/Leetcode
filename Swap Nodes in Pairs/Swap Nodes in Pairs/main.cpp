#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Before: ";
    printList(head);

    Solution sol;
    head = sol.swapPairs(head);

    cout << "After : ";
    printList(head);

    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

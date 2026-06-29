//
//  main.cpp
//  Remove Nth Node From End of List
//
//  Created by Vu Cao Nguyen on 29/6/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        for(int i = 0; i < n; i++) {
            fast = fast -> next;
        }
        
        while (fast != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        ListNode* toDelete = slow -> next;
        slow -> next = slow -> next -> next;
        delete toDelete;
        
        return dummy -> next;
    }
};

ListNode* buildList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (int i = 0; i < vals.size(); i++) {
        cur -> next = new ListNode(vals[i]);
        cur = cur -> next;
    }
    return head;
}

void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head -> val;
        if (head -> next) cout << ",";
        head = head -> next;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    printList(sol.removeNthFromEnd(l1, 2));
    
    ListNode* l2 = buildList({1});
    printList(sol.removeNthFromEnd(l2, 1));
    
    return 0;
}

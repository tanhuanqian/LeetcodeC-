#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createList(const vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;   
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;  
        delete nodeToDelete;
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode* head = createList(values);
    Solution sol;
    head = sol.removeNthFromEnd(head, 2);
    cout << "Linked list: ";
    printList(head);
    return 0;
}

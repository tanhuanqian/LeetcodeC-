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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = new ListNode(0);
        ListNode* h = head;
        while(cur1 && cur2){
            if(cur1->val < cur2->val){
                h->next = cur1;
                cur1 = cur1->next;
            } else if(cur1->val >= cur2->val){
                h->next = cur2;
                cur2 = cur2->next;
            }
            h = h->next;
        }
        if(cur1){
            h->next = cur1;
        } else{
            h->next = cur2;
        }
        return head->next;
    }
};

int main() {
    vector<int> values1 = {};
    vector<int> values2 = {1};
    int n = 2;
    ListNode* head1 = createList(values1);
    ListNode* head2 = createList(values2);
    Solution sol;
    head1 = sol.mergeTwoLists(head1, head2);
    cout << "Linked list: ";
    printList(head1);
    return 0;
}

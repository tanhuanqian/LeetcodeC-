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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* mid1 = getmid(head);
        ListNode* mid2 = mid1->next;
        mid1->next = nullptr;
        ListNode* left  = sortList(head);
        ListNode* right = sortList(mid2);
        return merge(left, right);
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(left && right){
            if(left->val > right->val){
                cur->next = right;
                right = right->next;
            } else{
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }
        if(left)  cur->next = left;
        if(right) cur->next = right;
        return dummy->next;
    }
    ListNode* getmid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = fast;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    vector<int> values = {-1,5,3,4,0};
    ListNode* head = createList(values);
    Solution sol;
    head = sol.sortList(head);
    cout << "Linked list: ";
    printList(head);
    return 0;
}
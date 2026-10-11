/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> mapping;

        Node *curr = head;
        while (curr)
        {
            mapping[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr)
        {
            Node* copy = mapping[curr];
            copy->next = mapping.count(curr->next) ? mapping[curr->next] : nullptr;
            copy->random = mapping.count(curr->random) ? mapping[curr->random] : nullptr;
            curr = curr->next;
        }
        return mapping[head];
    }
};

#include <vector>
using namespace std;

class LinkedList {
private:
    struct Node {
        int val;
        Node* next;

        Node(int val) : val(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {

    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->val;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }

        size++;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size)
            return false;

        if (index == 0) {
            Node* toDelete = head;

            head = head->next;
            delete toDelete;

            size--;

            if (size == 0) {
                tail = nullptr;
            }

            return true;
        }

        Node* current = head;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* toDelete = current->next;
        current->next = toDelete->next;

        if (toDelete == tail) {
            tail = current;
        }

        delete toDelete;
        size--;

        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        Node* current = head;

        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }

        return values;
    }
};
class MyCircularDeque {
public:
    struct DLNode {
        int val;
        DLNode* next;
        DLNode* prev;
        DLNode() : val(-1), next(NULL), prev(NULL) {}
        DLNode(int v) : val(v), next(NULL), prev(NULL) {}
    };
    int size, capacity;
    DLNode* head;
    DLNode* tail;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = 0;
        capacity = k;
        head = new DLNode();
        tail = new DLNode(); 
        head->next = tail;
        tail->prev = head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        DLNode* inserted_node = new DLNode(value);
        inserted_node->next = head->next;
        inserted_node->prev = head;
        inserted_node->next->prev = inserted_node;
        head->next = inserted_node;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        DLNode* inserted_node = new DLNode(value);
        inserted_node->next = tail;
        inserted_node->prev = tail->prev;
        inserted_node->prev->next = inserted_node;
        tail->prev = inserted_node;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        auto dummy_node = head->next;
        head->next = dummy_node->next;
        dummy_node->next->prev = head;
        delete dummy_node;
        dummy_node = NULL;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        auto dummy_node = tail->prev;
        tail->prev = dummy_node->prev;
        dummy_node->prev->next = tail;
        delete dummy_node;
        dummy_node = NULL;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return head->next->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return tail->prev->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
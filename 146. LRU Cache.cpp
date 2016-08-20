class LRUCache{
    struct Node {
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int k, int v):key(k),val(v) {}
    };
private:
    int capacity;
    Node *head, *tail;
    unordered_map <int, Node*> myMap;
    void moveToEnd (int key) {
        if (myMap[key] == tail) return;
        Node *p = myMap[key];
        if (p == head) {
            head = head->next;
            head->prev = NULL;
        }
        else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        tail->next = p;
        p->prev = tail;
        tail = p;
        p->next = NULL;
    }
    void removeHead () {
        if (head == NULL) return;
        myMap.erase (head->key);
        Node *tmp = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }
        delete (tmp);
    }
    void insertToEnd (int key, int val) {
        Node *p = new Node (key, val);
        myMap[key] = p;
        if (head == NULL) {
            head = p;
            tail = p;
        }
        else {
            tail->next = p;
            p->prev = tail;
            p->next = NULL;
            tail = p;
        }
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if (myMap.count (key) == 0)
            return -1;
        moveToEnd (key);
        return myMap[key]->val;
    }
    
    void set(int key, int value) {
        if (get (key) != -1)
            myMap[key]->val = value;
        else {
            if (myMap.size() >= capacity)
                removeHead ();
            insertToEnd (key, value);
        }
    }
};

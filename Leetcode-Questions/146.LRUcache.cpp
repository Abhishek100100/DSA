class LRUCache {
public:
    // creating a public class
    class Node
    {
        public:
        // data members
        int key, value;
        Node* next;
        Node* prev;

        //constructors
        Node(int k, int v)
        {
            key = k;
            value =v;
            prev = next = nullptr;
        }
    };

    // Data members
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> m; // to keep the operations in O(1)
    int limit;

    // helper member functions
    void addNode(Node* newNode)
    {
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->prev = head;
        newNode->next = oldNext; 
    }

    void delNode(Node* oldNode)
    {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // objective : get the value at that node, and move it to front of the DLL
        
        // if the key doesnt exist
        if(m.find(key)==m.end()) return -1;

        Node* ansNode = m[key];
        delNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;
        return ansNode->value;
    }
    
    void put(int key, int value) {
        // if that key already exists
        if(m.find(key)!=m.end())
        {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }
        
        // if we exhaust the cache capacity
        if(m.size()==limit)
        {
            // delete node prev to tail from DLL and remove key from map
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key,value);
        addNode(newNode);
        m[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
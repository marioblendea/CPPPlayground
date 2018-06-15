#pragma once
#include <unordered_map>
#include <exception>
#include <string>

struct Node {
    Node* pPrev;
    Node* pNext;
    int data;
    int key;
};

class LRUCache {
    public:
        LRUCache(int cacheSize) noexcept;
        virtual ~LRUCache() noexcept;

        int Get(int key);
        void Put(int key, int value);

    private:

        Node* CreateAtHead(int key, int value);
        void MoveToHead(Node* pNode) ;

        std::unordered_map<int, Node*> _hashTable;
        Node* _pHead;
        size_t _cacheSize;


};

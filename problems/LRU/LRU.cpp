#include "LRU.h"

LRUCache::LRUCache(int cacheSize) noexcept
{
    _pHead = nullptr;
    _cacheSize = cacheSize;
}

LRUCache::~LRUCache() noexcept {}

int LRUCache::Get(int key)
{
    // handle invalid key
    auto val = _hashTable.find(key);
    if (val == _hashTable.end())
    {
        //throw new std::exception(std::string("not found");
        return -1;
    }

    MoveToHead(val->second);
    return val->second->data;
}

void LRUCache::Put(int key, int value)
{
    auto val = _hashTable.find(key);
    if (val == _hashTable.end())
    {
        if (_hashTable.size() < _cacheSize)
        {
            _hashTable[key] = CreateAtHead(key, value);
        }
        else
        {
            _pHead = _pHead->pPrev;
            _pHead->data = value;
            _hashTable.erase(_pHead->key);
            _hashTable[key] = _pHead;
        }
    }
    else
    {
        val->second->data = value;
        MoveToHead(val->second);
    }
}

Node *LRUCache::CreateAtHead(int key, int value)
{
    Node *pNewNode = new Node();
    pNewNode->data = value;
    pNewNode->key = key;
    if (_pHead == nullptr) {
        pNewNode->pNext = pNewNode;
        pNewNode->pPrev = pNewNode;
    }
    else
    {
        pNewNode->pNext = _pHead;
        pNewNode->pPrev = _pHead->pPrev;
        _pHead->pPrev = pNewNode;
        pNewNode->pPrev->pNext = pNewNode;
    }
    _pHead = pNewNode;

    return _pHead;
}

void LRUCache::MoveToHead(Node *pNode)
{
    // remove pNode
    pNode->pPrev->pNext = pNode->pNext;
    pNode->pNext->pPrev = pNode->pPrev;
    // insert at head
    pNode->pNext = _pHead;
    pNode->pPrev = _pHead->pPrev;
    pNode->pPrev->pNext = pNode;
    _pHead->pPrev = pNode;
    _pHead = pNode;
}

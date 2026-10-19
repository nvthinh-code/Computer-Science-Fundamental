#include <iostream>
#include <vector>
const int size = 5;

// ---------------------------------------------------------------- Cấu trúc dữ liệu ------------------------------------------------------------

struct Node
{
    int data;
    Node *pNext;
};

Node *InitNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = nullptr;

    return p;
}

struct Bucket
{
    Node *pHead;
    Node *pTail;
};

void InitBucket(Bucket &bk)
{
    bk.pHead = nullptr;
    bk.pTail = nullptr;
}

struct Hashtable
{
    std::vector<Bucket> buckets;
};

void InitHashtable(Hashtable &h)
{
    h.buckets.resize(size);
    for (int i = 0; i < size; i++)
        InitBucket(h.buckets[i]);
}

int HashFunction(int value)
{
    return value % size;
}

int HashFunction(Node *p)
{
    return p->data % size;
}

void Push(Bucket &bk, Node *p)
{
    if (bk.pHead == nullptr)
    {
        bk.pHead = p;
        bk.pTail = p;
    }
    else
    {
        bk.pTail->pNext = p;
        bk.pTail = p;
    }
}

void Add(Hashtable &h, Node *p)
{
    Push(h.buckets[HashFunction(p->data)], p);
}

void Add(Hashtable &h, int key)
{
    Push(h.buckets[HashFunction(key)], InitNode(key));
}

void PrintHashtable(const Hashtable &h)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "index " << i << ": ";
        Node *ptr = h.buckets[i].pHead;
        while (ptr != nullptr)
        {
            std::cout << ptr->data << " ";
            ptr = ptr->pNext;
        }

        std::cout << "\n";
    }
}

void DeleteBucket(Bucket &bk)
{
    Node *ptr = bk.pHead;
    while (ptr != nullptr)
    {
        Node *temp = ptr;
        ptr = ptr->pNext;
        delete temp;
    }
    bk.pHead = nullptr;
    bk.pTail = nullptr;
}

void DeleteHashtable(Hashtable &h)
{
    for (int i = 0; i < size; i++)
        DeleteBucket(h.buckets[i]);
}

// ---------------------------------------------------------------- Bài Tập ----------------------------------------------------------------------

Node *Search(const Hashtable &h, int key)
{
    Node *ptr = h.buckets[HashFunction(key)].pHead;
    while (ptr != nullptr)
    {
        if (ptr->data == key)
            return ptr;

        ptr = ptr->pNext;
    }

    return nullptr;
}

void DeleteElement(Hashtable &h, int key)
{
    int pos = HashFunction(key);
    Node *ptr = h.buckets[pos].pHead;
    Node *prev = nullptr;

    while (ptr != nullptr)
    {
        if (ptr->data == key)
        {
            if (prev == nullptr) 
                h.buckets[pos].pHead = ptr->pNext;
            else
                prev->pNext = ptr->pNext;

            if (ptr == h.buckets[pos].pTail)
                h.buckets[pos].pTail = prev;

            delete ptr;
            return; 
        }
        prev = ptr;
        ptr = ptr->pNext;
    }
}

int main()
{
    Hashtable h;
    InitHashtable(h);

    for (int i = 0; i < 3; i++)
    {
        int x;
        std::cin >> x;
        Add(h, InitNode(x));
    }

    DeleteElement(h, 14);
    PrintHashtable(h);

    DeleteHashtable(h);
    return 0;
}
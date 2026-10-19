#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE* pNext;
};

NODE* CreateNode(int x)
{
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

struct LIST
{
    NODE* pHead;
    NODE* pTail;
};

void InsertHead(LIST& L, NODE* p)
{
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

void CreateEmptyList(LIST& L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void DeleteHead(LIST& L)
{
    if (L.pHead == NULL)
        return;

    NODE* temp = L.pHead;
    L.pHead = L.pHead->pNext;
    delete temp;   
}

void InsertTail(LIST& L, NODE* p)
{
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = p;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}


void DeleteTail(LIST& L)
{
    if (L.pHead == NULL)
        return;

    NODE* it = L.pHead;
    NODE* temp = L.pHead;
    while (it->pNext != NULL)
    {
        temp = it;
        it = it->pNext;
    }
    L.pTail = temp;
    temp->pNext = NULL;
    delete it;
}

int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertHead(L, CreateNode(x));
    }
    DeleteTail(L);
    PrintList(L);
    return 0;
}

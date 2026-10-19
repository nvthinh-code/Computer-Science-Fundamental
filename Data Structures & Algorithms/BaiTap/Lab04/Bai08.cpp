
#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
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

void TimKiemVaThem(LIST &L, int k)
{
    NODE* p = L.pHead;
    bool foundK = false;
    while (p != NULL)
    {
        if (p->info == k)
        {
            foundK = true;
            break;
        }
        p = p->pNext;
    }

    if (!foundK)
        InsertTail(L, CreateNode(1999));
    else
    {
        NODE* temp = CreateNode(1999);
        temp->pNext = p->pNext;
        p->pNext = temp;
    }
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

void TimKiemVaXoa(LIST& L, int k)
{
    bool foundK = false;
    if (L.pHead == NULL)
        return;
    while (L.pHead->info == k)
    {
        foundK = true;
        NODE* temp = L.pHead;
        L.pHead = L.pHead->pNext;
        delete temp;
    }

    NODE* p = L.pHead;
    NODE* prev = NULL;
    while (p != NULL)
    {
        if (p->info == k)
        {
            NODE* temp = p;
            p = p->pNext;
            prev->pNext = p;
            delete temp;
            foundK = true;
        }
        else
        {
            prev = p;
            p = p->pNext;
        }
    }

    if (!foundK)
        cout << -1;
    else
        PrintList(L);
}

void ReverseLinkedList(LIST& L)
{
    if (L.pHead == NULL)
        return;
    
    NODE* cur = L.pHead;
    NODE* prev = NULL;
    NODE* next = NULL;

    while (cur != NULL)
    {
        next = cur->pNext;
        cur->pNext = prev;
        prev = cur;
        cur = next;
    }
    L.pTail = L.pHead;
    L.pHead = prev;
}

void SelectionSortPointer(LIST& L)
{
    if (L.pHead == NULL || L.pHead->pNext == NULL)
        return;

    NODE* prevCurr = NULL;
    NODE* curr = L.pHead;

    while (curr != NULL)
    {
        NODE* minNode = curr;
        NODE* prevMin = prevCurr;

        NODE* temp = curr->pNext;
        NODE* prevTemp = curr;

        while (temp != NULL)
        {
            if (temp->info < minNode->info)
            {
                minNode = temp;
                prevMin = prevTemp;
            }
            prevTemp = temp;
            temp = temp->pNext;
        }

        if (minNode != curr)
        {
            if (prevCurr == NULL) {
                L.pHead = minNode;
            } else {
                prevCurr->pNext = minNode;
            }

            if (curr->pNext == minNode) {
                curr->pNext = minNode->pNext;
                minNode->pNext = curr;
            } else {
                prevMin->pNext = curr;
                NODE* tempNext = minNode->pNext;
                minNode->pNext = curr->pNext;
                curr->pNext = tempNext;
            }

            if (curr->pNext == NULL) {
                L.pTail = curr;
            }
            if (minNode->pNext == NULL) {
                L.pTail = minNode;
            }

            prevCurr = minNode;
            curr = minNode->pNext;
        }
        else
        {
            prevCurr = curr;
            curr = curr->pNext;
        }
    }
}

void SelectionSortInfo(LIST& L)
{
    NODE* p = L.pHead;
    while (p != NULL)
    {
        NODE* minPos = p;

        NODE* temp = p;
        while (temp != nullptr)
        {
            if (minPos->info > temp->info)
                minPos = temp;
            temp = temp->pNext;
        }
        swap(p->info, minPos->info);
        p = p->pNext;
    }
}

int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    SelectionSortPointer(L);
    PrintList(L);
    return 0;
}

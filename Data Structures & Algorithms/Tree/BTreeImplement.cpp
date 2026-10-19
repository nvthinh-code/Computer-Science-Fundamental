#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class cBTree
{
private:
    struct Node
    {
        vector<int> key;
        vector<Node*> child;
        bool isLeaf;

        Node(bool _isLeaf) : isLeaf(_isLeaf) {}
    };
    Node* root;
    int m; // order

    pair<Node*, int> Search(Node* current, int k)
    {
        if (current == NULL)
            return {NULL, -1};

        auto it = lower_bound(current->key.begin(), current->key.end(), k);
        int i = it - current->key.begin();

        if (i < current->key.size() && current->key[i] == k)
            return {current, i};
        
        if (current->isLeaf)
            return {NULL, -1};

        return Search(current->child[i], k);
    }

    void SplitChild(Node* parrent, int i, Node* current)
    {
        // Tao khoa moi ngang hang
        Node* atarashi = new Node(current->isLeaf ? true : false); 

        // Day khoa o giua len cha
        int mid = current->key.size()/2;
        parrent->key.insert(parrent->key.begin() + i, current->key[mid]);
        parrent->child.insert(parrent->child.begin() + i, atarashi);

        // Day cac phan tu qua atarashi
        for (int k = mid + 1; k < current->key.size(); k++)
            atarashi->key.push_back(current->key[k]);

        // Xu ly con tro child
        if (!current->isLeaf)
        {
            for (int k = mid + 1; k < current->child.size(); k++)
                atarashi->child.push_back(current->child[k]);
            
            current->child.erase(current->child.begin() + mid + 1, current->child.end());
        }

        // Xoa cac khoa da dua sang atarashi
        current->key.erase(current->key.begin() + mid, current->key.end());
    }

    void Insert(int k)
    {
        if (root == NULL)
        {
            root = new Node(true);
            root->key.push_back(k);
            return;
        }

        // Goc cua cay bi day
        if (root->key.size() == m - 1)
        {
            Node* newRoot = new Node(false);
            newRoot->child.push_back(root);
            SplitChild(newRoot, 0, root);
            this->root = newRoot;
        }
        
        // auto it = lower_bound(root->key.begin(), root->key.end(), k);
        // int i = it - root->key.begin();

        // if (root->isLeaf)
        //     root->key.insert(it, k);
        // else    
        // {
        //     if ()
        // }
    }

public:
    cBTree() : root(NULL), m(0) {}
    cBTree(int order) : root(NULL), m(order) {}

    pair<Node*, int> Search(int k) { return Search(root, k); }
};
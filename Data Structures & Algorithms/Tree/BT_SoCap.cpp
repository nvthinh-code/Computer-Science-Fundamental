#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* InitNode(int key)
{
    Node* p = new Node;
    if (p == NULL)
        return NULL;
    p->data = key;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void InitTree(Node* &root)
{
    root = NULL;
}

bool insertNode(Node* &root, int key)
{
    if (root == NULL) 
    {
        root = InitNode(key); // Cấp phát động Node mới
        return true;
    }

    if (root->data == key)
        return false;

    if (root->data > key)
        insertNode(root->left, key);

    else
        insertNode(root->right, key);

    return false;
}

// void LNR(Node* root)
// {
//     if (root != NULL)
//     {
//         LNR(root->left);
//         std::cout << root->data << " ";
//         LNR(root->right);
//     }
// }

Node* findMax(Node* root)
{
    if (root == NULL)
        return NULL;

    Node* res = root;
    while (root != NULL)
    {
        res = root;
        root = root->right;
    }

    return res;
}

Node* findMin(Node* root)
{
    if (root == NULL)
        return NULL;
    
    Node* res = root;
    while (root != NULL)
    {
        res = root;
        root = root->left;
    }

    return res;
}

int countNode(Node* root)
{
    if (root == nullptr)
        return 0;

    int left = countNode(root->left);
    int right = countNode(root->right);

    return left + right + 1;
}

int countLeaf(Node* root)
{
    // if (root == nullptr)
    //     return 0;

    // int current = (root->left == NULL && root->right == NULL) ? 1 : 0;
    // return current + countLeaf(root->left) + countLeaf(root->right);
    
    if (root == nullptr)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int L = countLeaf(root->left);
    int R = countLeaf(root->right);

    return L + R;
}


int getHeight(Node* root) 
{
    if (root == nullptr)
        return -1;
    
    int left = getHeight(root->left);
    int right = getHeight(root->right);

    return std::max(left, right) + 1;
}

// bool isBST(Node* root, int max, int min)
// {
//     if (root == NULL)
//         return;

//     isBST(root->left, root->data, INT_MIN);
//     isBST(root->right, INT_MAX, root->data);


// }

//Dem so Node co 2 Node con
int countNode2(Node* root)
{
    if (root == nullptr)
        return 0;
    
    int current = (root->left != NULL && root->right != NULL) ? 1 : 0;

    return current + countNode2(root->left) + countNode2(root->right);
}


int main()
{
    std::cout << "Vui lòng nhập số lượng Node: ";
    int n;
    std::cin >> n;
    
    std::cout << "Vui lòng nhập các Node: ";
    std::vector<int> v(n);
    for (int& x : v)
        std::cin >> x;

    Node* t;
    InitTree(t);
    for (int x : v)
        insertNode(t, x);
    
    // std::cout << "Danh sách thu được khi duyệt LNR là:\n";
    // LNR(t);

    // std:: cout << "Node có giá trị lớn nhất trong cây là:\n";
    // Node* resMax = findMax(t);
    // std::cout << resMax->data << "\n";

    // std:: cout << "Node có giá trị nhỏ nhất trong cây là:\n";
    // Node* resMin = findMin(t);
    // std::cout << resMin->data << "\n";

    // std::cout << "Số lượng Node trong cây:\n";
    // int quantity = countNode(t);
    // std::cout << quantity << "\n";   

    std::cout << "Số lượng Leaf trong cây:\n";
    int leaf = countLeaf(t);
    std::cout << leaf << "\n";   

    // std::cout << "Chiều cao của cây là:\n";
    // int height = getHeight(t);
    // std:: cout << height << "\n";

    // std::cout << "Số Node có 2 con là:\n";
    // std::cout << countNode2(t);

    return 0;
}
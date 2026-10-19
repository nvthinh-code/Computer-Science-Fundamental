#include <iostream>
#include <vector>

// 1. Định nghĩa Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// 2. Khởi tạo một Node mới
Node *InitNode(int value)
{
    Node *p = new Node;
    if (p == NULL)
        return NULL;
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// 3. Khởi tạo Cây chuẩn nhất
void InitTree(Node *&root)
{
    root = NULL; // Cây rỗng ban đầu chỉ cần gán gốc bằng NULL
}

// 4. Hàm thêm Node (Chuẩn thuật toán BST)
bool insertNode(Node *&root, int value)
{
    // Nếu tìm thấy chỗ trống, chèn Node vào
    if (root == NULL)
    {
        root = InitNode(value);
        return true;
    }

    // Nếu giá trị đã tồn tại, không chèn
    if (root->data == value)
    {
        return false;
    }

    // Đệ quy tìm vị trí: nhỏ sang trái, lớn sang phải
    if (root->data > value)
    {
        return insertNode(root->left, value);
    }
    else
    {
        return insertNode(root->right, value);
    }
}

// 5. Các hàm duyệt cây (Lưu ý: truyền Node* là đủ, không cần Node*&)
void NLR(Node *root)
{
    if (root != NULL)
    {
        std::cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

// Tăng dần (Trái - Gốc - Phải)
void LNR(Node *root)
{
    if (root != NULL)
    {
        LNR(root->left);
        std::cout << root->data << " ";
        LNR(root->right);
    }
}

// Giảm dần (Phải - Gốc - Trái)
void RNL(Node *root)
{
    if (root != NULL)
    {
        RNL(root->right);
        std::cout << root->data << " ";
        RNL(root->left);
    }
}

// Tìm kiếm value có tồn tại trong cây không
Node *searchForValue(Node *root, int value)
{
    while (root != NULL)
    {
        if (root->data == value)
            return root;
        else if (root->data > value)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// Xóa Node có data bằng với value
// Trả về Node* để móc nối lại cây sau khi xóa
Node *deleteNode(Node *root, int value)
{
    if (root == NULL) 
        return NULL;
    
    // Bước 1: Tìm Node cần xóa
    if (root->data > value)
    {
        root->left = deleteNode(root->left, value); // Đệ quy sang trái, móc nối lại nhánh trái
    }
    else if (root->data < value)
    {
        root->right = deleteNode(root->right, value); // Đệ quy sang phải, móc nối lại nhánh phải
    }
    else
    {
        // Bước 2: Đã tìm thấy Node cần xóa (root->data == value)

        // TH1 và TH2: Có 1 con hoặc Không có con (Node lá)
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp; // Trả đứa con bên phải lên cho Node cha móc vào
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp; // Trả đứa con bên trái lên cho Node cha móc vào
        }

        // TH3: Có 2 con
        // Tìm Node lớn nhất bên cây con trái (hoặc nhỏ nhất bên phải)
        Node *temp = root->left; // Sang trái 1 bước
        while (temp->right != NULL)
        {
            temp = temp->right; // Tìm Node lớn nhất bến trái
        }

        // Chép dữ liệu của Node thế mạng lên Node hiện tại
        root->data = temp->data;

        // Đi xuống nhánh trái để xóa cái Node thế mạng kia đi
        root->left = deleteNode(root->left, temp->data);
    }

    return root;
}

int main()
{
    std::vector<int> v{12, 8, 23, 15, 2, 7, 9, 3, 25, 18};
    Node *t;
    InitTree(t);

    for (int i = 0; i < 10; i++)
        insertNode(t, v[i]);

    // std::cout << "Cây sau khi duyệt trước:\n";
    // NLR(t);
    // std::cout << "\n";

    std::cout << "Cây sau khi duyệt giữa tăng dần:\n-> ";
    LNR(t);
    std::cout << "\n";

    // std::cout << "Cây sau khi duyệt giữa giảm dần:\n";
    // RNL(t);
    // std::cout << "\n";

    std::cout << "Nhập giá trị muốn tìm: ";
    int value;
    std::cin >> value;
    if (searchForValue(t, value) != NULL)
    {
        std::cout << "-> Tìm thấy " << value << " trong cây\n";

        std::cout << "Xóa Node có giá trị là " << value << ": (Y/N)\n";
        char remove;
        std::cin >> remove;
        // Xóa Node
        if (remove == 'Y')
            t = deleteNode(t, value);
        std::cout << "Cây sau khi xóa Node có giá trị " << value << " là:\n-> ";
        LNR(t);
    }
    else
        std::cout << "-> Không tìm thấy " << value << " trong cây\n";

    return 0;
}
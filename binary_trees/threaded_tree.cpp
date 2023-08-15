#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild = nullptr;
    Node *rightChild = nullptr;
    // is left and right avialable to accept new children
    bool leftAvail = 1;
    bool rightAvail = 1;
    Node(int data)
    {
        this->data = data;
    }
};
Node *root = nullptr;

class ThreadedTree
{
public:
    Node *insert(Node *root, int data)

    {
        auto newNode = new Node(data);
        if (root == nullptr)
        {
            root = newNode;
            // root->leftChild = root;
            // root->rightChild = root;
            return root;
        }
        //  Node *parent = root;
        Node *parent = root;
        while (true)
        {
            //   parent = parent;
            if (data < parent->data)
            {
                if (!parent->leftAvail)
                {
                    // if parent->left is not a threaded pointer
                    parent = parent->leftChild;
                }
                else
                {
                    break;
                }
            }
            else if (data > parent->data)
            {
                if (!parent->rightAvail)
                {
                    // if parent->right is not a threaded pointer
                    parent = parent->rightChild;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cout << "Data Already Exists" << endl;
                return root;
            }
        }
        if (data < parent->data)
        {
            // insert as leftChild
            newNode->leftChild = parent->leftChild;
            newNode->rightChild = parent;
            parent->leftChild = newNode;
            parent->leftAvail = false;
        }
        else
        {
            newNode->leftChild = parent;
            newNode->rightChild = parent->rightChild;
            parent->rightChild = newNode;
            parent->rightAvail = false;
        }

        // if(data<root->data)
        // {
        //     root->leftChild=insert(root->leftChild,data);
        // }
        // else if(data>root->data)
        // {
        //     root->rightChild=insert(root->rightChild,data);
        // }
        // else
        // {
        //     //data==root->data=>data already exists
        //     cout<<"data Already Exists"<<endl;
        //     return root;
        // }
        return root;
    }
    Node *getLeftMost(Node *node)
    {
        while (!node->leftAvail)
        {
            // find node that has availability for leftChild
            node = node->leftChild;
        }
        return node;
    }
    void inorderTraversal(Node *root)
    {
        Node *current = getLeftMost(root);
        cout << "it is leftmost " << current->data;
        while (current != nullptr)

        {
            cout << current->data << "--";
            // cout << current->rightChild << "--";
            // current = getLeftMost(current->rightChild->rightChild);
            if (current->rightAvail)
            {
                //=>rightChild is threadNode
                // here we use it for back tracking
                current = current->rightChild;
            }
            else
            {
                //=>get inorder successor of current
                // which leftmost of right subtree
                current = getLeftMost(current->rightChild);
            }
        } // while (current != root);
    }
};

int main()
{

    auto tree = ThreadedTree();
    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 20);
    root = tree.insert(root, 10);
    root = tree.insert(root, 25);
    root = tree.insert(root, 40);
    root = tree.insert(root, 22);
    root = tree.insert(root, 35);
    root = tree.insert(root, 45);
    root = tree.insert(root, 100);
    root = tree.insert(root, 75);
    root = tree.insert(root, 125);
    root = tree.insert(root, 120);
    tree.inorderTraversal(root);
    return 0;
}
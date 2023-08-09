#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data, height = 1;
    Node *right = NULL;
    Node *left = NULL;
    Node(int x)
    {
        this->data = x;
    }
};
class Avl
{

public:
    int getHeight(Node *node)
    {
        if (node != NULL)
        {
            return node->height;
        }
        return 0;
    }
    int max(int h1, int h2)
    {
        // h1>h2?return h1:return h2;
        return h1 > h2 ? h1 : h2;
    }
    int getBFactor(Node *node)
    {

        return getHeight(node->left) - getHeight(node->right);
    }
    Node *balanceHeight(Node *node, Node *newRoot)
    {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
        return newRoot;
    }
    Node *rotateRight(Node *node)
    {
        // we've to rotate towards right
        Node *newRoot = node->left;
        Node *temp = newRoot->right;
        newRoot->right = node;
        node->left = temp;
        // balancing height
        return balanceHeight(node, newRoot);
    }
    Node *rotateLeft(Node *node)
    {
        Node *newRoot = node->right;
        Node *temp = newRoot->left;
        newRoot->left = node;
        newRoot->left->right = temp;
        // balancing height
        return balanceHeight(node, newRoot);
    }
    Node *insert(Node *root, int val)
    {
        if (root == NULL)
        {
            // height of leaf node is always 0
            return new Node(val);
        }
        if (val < root->data)
        {
            root->left = insert(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = insert(root->right, val);
        }
        else
        {
            cout << "Data Already exists\n";
            return root;
        }

        // before returning the parent node we balance it first
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

        int balanceFactor = getBFactor(root);

        // left imbalanced or left-heavy
        if (balanceFactor > 1)
        {

            if (val < root->left->data)
            {
                // LLImbalanced
                // Left Left case
                root = rotateRight(root);
            }
            else
            {
                // LRImbalanced
                // Left Right Case
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        }
        // right imbalanced or right-heavy
        if (balanceFactor < -1)
        {
            if (val > root->right->data)
            {
                // RRImbalanced
                root = rotateLeft(root);
            }
            else
            {
                // RLImbalanced
                root->right = rotateRight(root->right);
                root = rotateLeft(root);
            }
        }
        return root;
    }
    void levelOrderTraversal(Node *node)
    {
        if (!node)
        {
            cout << "Empty avl tree " << endl;
            return;
        }
        queue<Node *> myQueue;
        myQueue.push(node);
        while (!myQueue.empty())
        {
            Node *current = myQueue.front();
            if (current->left)
            {
                myQueue.push(current->left);
            }
            if (current->right)
            {
                myQueue.push(current->right);
            }
            cout << current->data << "(h:" << current->height << ")--";
            myQueue.pop();
        }
        cout << endl;
    }
};
Node *root = NULL;
int main()
{
    int choice, data;
    Avl avlTree1 = Avl();
    avlTree1.levelOrderTraversal(root);
    root = avlTree1.insert(root, 30);
    root = avlTree1.insert(root, 20);
    avlTree1.levelOrderTraversal(root);
    root = avlTree1.insert(root, 10);
    avlTree1.levelOrderTraversal(root);
    root = avlTree1.insert(root, 5);
    root = avlTree1.insert(root, 2);
    avlTree1.levelOrderTraversal(root);
    do
    {
        cout << "enter choice : " << endl
             << "1.  insert" << endl
             << "2.  level order traversal" << endl
             << "3.  Display " << endl
             << "4.  Delete " << endl
             << "5.  Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter data : " << endl;
            cin >> data;
            root = avlTree1.insert(root, data);
            break;
        case 2:
             avlTree1.levelOrderTraversal(root);
            break;
        case 3:
            //  display(root);
            break;
        case 4:
            cout << "enter value :" << endl;
            cin >> data;
            // deleteNode(root,data);
            // root = recursiveDelete(root, data);
            break;
        case 5:
            break;
        }
    } while (choice != 5);

    return 0;
}
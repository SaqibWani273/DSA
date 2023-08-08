#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;
    Node(int x)
    {
        this->data = x;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};
Node *root = NULL;
void insert(int data)
{
    Node *newNode = new Node(data);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    Node *temp = root;
    Node *parent = root;
    while (temp != NULL)
    {

        parent = temp;
        if (data < temp->data)
        {
            temp = temp->leftChild;
        }
        else if (data > temp->data)
        {
            temp = temp->rightChild;
        }
        else
        {
            cout << "Data already exists\n";
            return;
        }
    }
    if (data < parent->data)
    {
        parent->leftChild = newNode;
    }
    else
    {
        parent->rightChild = newNode;
    }
}

Node *recursiveInsert(Node *currentRoot, int data)
{
    if (currentRoot == NULL)
    {
        return new Node(data);
    }
    if (data < currentRoot->data)
    {
        currentRoot->leftChild = recursiveInsert(currentRoot->leftChild, data);
    }
    else if (data > currentRoot->data)
    {
        currentRoot->rightChild = recursiveInsert(currentRoot->rightChild, data);
    }
    else
    {
        cout << "data already exists\n";
        return currentRoot;
    }
    return currentRoot;
}
void display(Node *node)
{
    if (node == root)
        cout << "Postorder Traversal = \n";
    if (node == NULL)
    {
        return;
    }

    display(node->leftChild);
    display(node->rightChild);
    cout << node->data << "--";
}
void levelOrderTraversal(Node *node)
{
    if (!node)
    {
        return;
    }
    queue<Node *> myQueue;
    myQueue.push(node);
    while (!myQueue.empty())
    {
        Node *current = myQueue.front();
        if (current->leftChild)
        {
            myQueue.push(current->leftChild);
        }
        if (current->rightChild)
        {
            myQueue.push(current->rightChild);
        }
        cout << current->data << "--";
        myQueue.pop();
    }
}
int inOrderPredessor(Node *leftSubtree)
{
    Node *temp = leftSubtree;
    while (temp->rightChild)
    {
        temp = temp->rightChild;
    }
    return temp->data;
}
void deleteNode(Node *currentRoot, int val)
{
    Node *temp = currentRoot;
    Node *parent = currentRoot;
    while (temp != NULL && temp->data != val)
    {
        parent = temp;
        if (val < temp->data)
        {
            temp = temp->leftChild;
        }
        else
        {
            temp = temp->rightChild;
        }
    }
    if (temp == NULL)
    {
        cout << val << " is not present in this BST" << endl;
        return;
    }
    // to check the relation b/w parent and child
    bool isLeft = temp == parent->leftChild ? true : false;
    // when deleting node has no children
    //  if(temp->leftChild==NULL&&temp->rightChild==NULL)
    //  {
    //          if(isLeft)
    //          {
    //              parent->leftChild=NULL;
    //          }
    //          else
    //          {
    //              parent->rightChild=NULL;
    //          }
    //  delete(temp);
    //  }
    // when deleting node has only right child
    if (temp->leftChild == NULL)
    {
        if (isLeft)
        {
            parent->leftChild = temp->rightChild;
        }
        else
        {
            parent->rightChild = temp->rightChild;
        }

        if (temp == root)
            root = root->leftChild;
        delete (temp);
    }
    // when deleting node has only left child
    else if (temp->rightChild == NULL)
    {
        if (isLeft)
        {
            parent->leftChild = temp->leftChild;
        }
        else
        {
            parent->rightChild = temp->leftChild;
        }

        if (temp == root)
            root = root->rightChild;
        delete (temp);
    }

    //=>node has both the children
    else
    {
        int maxVal = inOrderPredessor(temp->leftChild);
        if (isLeft)
        {
            parent->leftChild->data = maxVal;
        }
        else
        {
            parent->rightChild->data = maxVal;
        }
        deleteNode(temp->leftChild, maxVal);
    }
    if (currentRoot == root)
    {
        cout << "Deleted Successfully !" << endl;
    }
}

Node *recursiveDelete(Node *currentRoot, int val)
{
    if (currentRoot == NULL)
    {
        return NULL;
    }
    if (val < currentRoot->data)
    {
        currentRoot->leftChild = recursiveDelete(currentRoot->leftChild, val);
    }
    else if (val > currentRoot->data)
    {
        currentRoot->rightChild = recursiveDelete(currentRoot->rightChild, val);
    }
    //=>currentRoot->data=val
    else
    {
        //=>currentRoot has only leftChild
        if (currentRoot->rightChild == NULL)
        {
            return currentRoot->leftChild;
        }
        //=>currentRoot has only rightChild
        else if (currentRoot->leftChild == NULL)
        {
            return currentRoot->rightChild;
        }
        //=>currentRoot has both children
        else
        {
            // to swap data with maxValue in leftSubtree
            int maxValue = inOrderPredessor(currentRoot->leftChild);
            currentRoot->data = maxValue;
            // to delete that particular node
            currentRoot->leftChild = recursiveDelete(currentRoot->leftChild, maxValue);
        }
    }
    return currentRoot;
}
int main()
{

    int choice, data, deleted;
    root = recursiveInsert(root, 100);
    root = recursiveInsert(root, 500);
    root = recursiveInsert(root, 10);
    root = recursiveInsert(root, 250);
    root = recursiveInsert(root, 150);
    root = recursiveInsert(root, 600);
    root = recursiveInsert(root, 120);
    root = recursiveInsert(root, 550);
    root = recursiveInsert(root, 110);
    root = recursiveInsert(root, 130);
    root = recursiveInsert(root, 510);
    root = recursiveInsert(root, 560);
    levelOrderTraversal(root);

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
            insert(data);
            break;
        case 2:
            levelOrderTraversal(root);
            break;
        case 3:
            display(root);
            break;
        case 4:
            cout << "enter value :" << endl;
            cin >> data;
            // deleteNode(root,data);
            root = recursiveDelete(root, data);
            break;
        case 5:
            break;
        }
    } while (choice != 5);
    return 0;
}
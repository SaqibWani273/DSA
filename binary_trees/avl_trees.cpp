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
   
   int inOrderPredessor(Node *leftSubtree)
{
    Node *temp = leftSubtree;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp->data;
}
Node *recursiveDelete(Node *currentRoot, int val)
{
    //initially same as for bst
    //then need to update heights and balance if necessary
    if (currentRoot == NULL)
    {
        return NULL;
    }
    if (val < currentRoot->data)
    {
        currentRoot->left = recursiveDelete(currentRoot->left, val);
    }
    else if (val > currentRoot->data)
    {
        currentRoot->right = recursiveDelete(currentRoot->right, val);
    }
    //=>currentRoot->data=val
    else
    {
        //=>currentRoot has only leftChild
        if (currentRoot->right == NULL)
        {
            return currentRoot->left;
        }
        //=>currentRoot has only rightChild
        else if (currentRoot->left == NULL)
        {
            return currentRoot->right;
        }
        //=>currentRoot has both children
        else
        {
            // to swap data with maxValue in leftSubtree
            int maxValue = inOrderPredessor(currentRoot->left);
            currentRoot->data = maxValue;
            // to delete that particular node
            currentRoot->left= recursiveDelete(currentRoot->left, maxValue);
        }
    }
    //update heights and balance node if needed
    currentRoot->height=max(getHeight(currentRoot->left),getHeight(currentRoot->right))+1;
    
    if(getBFactor(currentRoot)>1)
    {
        
        //leftImbalanced=>element deleted was on the right of the node
        Node* x=currentRoot->left;
        //check if it is Left  Left  case or Left Right
        // if(x->left->height>x->right->height)
        if(getBFactor(x)>=0)
        {
            //Left Left case
            currentRoot=rotateRight(currentRoot);

        }
        else
        {
            //Left Right Case
            currentRoot->left=rotateLeft(currentRoot->left);
            currentRoot=rotateRight(currentRoot);

        }

    }
    else if(getBFactor(currentRoot)<-1)
    {
      
        //rightImbalanced=>element deleted was on the left of the node
        Node* x=currentRoot->right;
        //check if it is Right Right case or Right Left
       // if(x->right->height>x->left->height)
       if(getBFactor(x)<=0)
        {
            //Right Right case
            currentRoot=rotateLeft(currentRoot);
        }
        else{
            //Right Left Case
            currentRoot->right=rotateRight(currentRoot->right);
             currentRoot=rotateLeft(currentRoot);
        }
    }
    else
    {
        return currentRoot;
    }
    return currentRoot;
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
             root =avlTree1.recursiveDelete(root, data);
            break;
        case 5:
            break;
        }
    } while (choice != 5);

    return 0;
}
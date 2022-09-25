#include <iostream>
#include <stack>
using namespace std;

class BSTnode
{
public:
    int val;
    BSTnode *parent;
    BSTnode *left;
    BSTnode *right;
    BSTnode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};
class BST
{
    void inorder(BSTnode *root)
    {
        if (root == NULL)
            return;

        cout << root->val << " ";
        inorder(root->left);
        inorder(root->right);
    }

public:
    BSTnode *node;

    BST()
    {
        this->node = NULL;
    }
    void insert(BSTnode *&root, int val)
    {
        BSTnode *temp = new BSTnode(val);
        if (root == NULL)
        {
            cout << "Control is here" << endl;
            root = temp;
            cout << root << ' ' << node << endl;
        }
        else if (root->val > val)
        {
            if (root->left == NULL)
            {
                root->left = temp;
                temp->parent = root;
                cout << "Control is here1" << endl;
                cout << root->left << ' ' << node << endl;
            }

            else
            {
                cout << "Control is here2" << endl;
                insert(root->left, val);
                cout << root->right << ' ' << node << endl;
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = temp;
                temp->parent = root;
            }
            else
                insert(root->right, val);
        }
    }

    BSTnode *&search(BSTnode *&root, int val)
    {
        // cout << root->val << "//";
        if (root == NULL || root->val == val)
            return root;

        else if (root->val < val)
            return search(root->right, val);
        else
            return search(root->left, val);
    }

    void insert(int val)
    {
        this->insert(node, val);
    }

    void remove(int val)
    {
        BSTnode *root = node;
        BSTnode *temp = search(node, val);
        // cout << temp->val;
        if (temp == NULL)
            cout << "Element not found" << endl;
        else if (temp->right && temp->left)
        {
            cout << "Element found but cannot be removed" << endl;
            BSTnode *successorNode = findSuccessor(temp->right);
            // cout << "Successor val - " << successorNode->val << endl;
            BSTnode *successorParent = successorNode->parent;
            // updating temp left parent
            BSTnode *tempLeft = temp->left;

            // remove successor node from the right subtree of the temp
            remove(successorNode->val);
            BSTnode *tempParent = temp->parent;
            cout << "TempParent val " << tempParent << endl;
            // chang temp parent to successor node;
            if (tempParent && tempParent->left == temp)
                tempParent->left = successorNode;
            else if (tempParent)
                tempParent->right = successorNode;

            BSTnode *lft = temp->left;
            BSTnode *rht = temp->right;
            successorNode->left = lft;
            successorNode->right = rht;
            successorNode->parent = temp->parent;
            tempLeft->parent = successorNode;
            if (!tempParent)
                node = successorNode;
        }
        else
        {
            BSTnode *dummy;
            if (temp->left != NULL)
                dummy = temp->left;
            else
                dummy = temp->right;

            BSTnode *lft = NULL;
            BSTnode *rht = NULL;
            if (dummy)
            {
                lft = dummy->left;
                rht = dummy->right;
                temp->val = dummy->val;
                temp->left = lft;
                temp->right = rht;
            }
            else
            {

                BSTnode *&par = temp->parent;
                cout << "temp parent address " << temp->parent << endl;
                cout << "temp address - " << temp << " temp value - " << temp->val << endl;
                cout << "Parent address - " << par << endl;
                // cout << temp << " compare parent left " << par->left << endl;
                if (par && par->right == temp)
                    par->right = NULL;
                else if (par)
                    par->left = NULL;

                // cout << "Par - " << par->left << "Node - " << node << endl;
                cout << "Node value - " << node;
            }
            // Only in case of single node
            if (!temp->parent)
                node = NULL;
        }
    }
    BSTnode *findSuccessor(BSTnode *&root)
    {
        // cout << "root value- " << root->val << endl;
        if (root && root->left)
            return findSuccessor(root->left);
        return root;
    }

    void preorder()
    {
        // this->inorder(node);
        BSTnode *root = node;
        stack<BSTnode *> st;
        cout << "Inside Pre-order traversal" << endl;
        while (root || !st.empty())
        {
            if (root)
            {
                cout << root->val << " ";
                st.push(root);
                root = root->left;
            }
            else
            {
                BSTnode *temp = st.top();
                root = temp->right;
                st.pop();
            }
        }
        cout << endl;
    }
    void inorder()
    {
        stack<BSTnode *> st;
        BSTnode *root = node;
        cout << "Inside In-order traversal" << endl;

        while (root || !st.empty())
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                BSTnode *temp = st.top();
                cout << temp->val << " ";
                st.pop();
                root = temp->right;
            }
        }
        cout << endl;
    }

    void postorder()
    {
        cout << "postorder traversal :" << endl;
        BSTnode *root = node;
        stack<BSTnode *> st;
        st.push(root);
        BSTnode *pre = NULL;

        while (!st.empty())
        {
            BSTnode *current = st.top();

            if (pre == NULL || pre->left == current || pre->right == current)
            {
                if (current->left)
                    st.push(current->left);
                else if (current->right)
                    st.push(current->right);
                else
                {
                    cout << current->val << " ";
                    st.pop();
                }
            }
            else if (current->left == pre)
            {
                if (current->right)
                    st.push(current->right);
                else
                {
                    cout << current->val << " ";
                    st.pop();
                }
            }
            else
            {
                cout << current->val << " ";
                st.pop();
            }
            pre = current;
        }
        cout << endl;
    }

    void postorder1()
    {
        stack<BSTnode *> st;
        BSTnode *root = node;
        while (root || !st.empty())
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                BSTnode *temp = st.top();
                if (temp->right)
                    root = root->right;
                else
                {
                    cout << temp->val << " ";
                    st.pop();
                    root = temp;
                }
            }
        }
    }
};

void tc1(BST &b)
{
    b.insert(30);
    b.insert(20);
    b.insert(15);
    b.insert(17);
    b.insert(10);
    b.insert(40);
    b.insert(60);
    b.insert(16);
    b.insert(19);
    b.inorder();
    // b.remove(10);
    b.inorder();
    // b.remove(15);
    b.inorder();
    // b.remove(15);
    b.preorder();
    b.postorder();
}

void tc2(BST &b)
{
    b.insert(2);
    b.insert(1);
    b.insert(3);
    cout << "node address - " << b.node << " node val - " << b.node->val;

    b.remove(2);
    // b.remove(2);
    BSTnode *b1 = b.search(b.node, 1);
    // BSTnode *b2 = b.search(b.node, 2);
    // BSTnode *b3 = b.search(b.node, 3);

    cout << b1 << ' ' << b1->left << ' ' << b1->right << ' ' << b1->parent << endl;
    // cout << b2 << ' ' << b2->left << ' ' << b2->right << ' ' << b2->parent << endl;
    // cout << b3 << ' ' << b3->left << ' ' << b3->right << ' ' << b3->parent << endl;
    cout << "node address - " << b.node << " node val - " << b.node->val;
    b.inorder();
    cout << "removing 1" << endl;
    b.remove(1);
    b.inorder();
    BSTnode *b3 = b.search(b.node, 3);
    cout << b3 << ' ' << b3->left << ' ' << b3->right << ' ' << b3->parent << endl;
    b.remove(3);
    b.remove(3);
    cout << "before printing" << endl;
    b.inorder();
}

void tc3(BST &b)
{
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(10);
    b.insert(15);
    b.insert(5);
    b.insert(7);
    b.remove(3);
    b.inorder();
}

void tc4(BST &b)
{
    b.insert(2);
    b.insert(1);
    b.insert(3);

    b.remove(2);
    // b.remove(2);

    BSTnode *b1 = b.search(b.node, 1);
    BSTnode *b2 = b.search(b.node, 2);
    BSTnode *b3 = b.search(b.node, 3);

    cout << b1 << ' ' << b1->left << ' ' << b1->right << ' ' << b1->parent << endl;
    cout << b2 << ' ' << b2->left << ' ' << b2->right << ' ' << b2->parent << endl;
    cout << b3 << ' ' << b3->left << ' ' << b3->right << ' ' << b3->parent << endl;
}

int main()

{
    BST b;
    tc2(b);
    tc1(b);

    return 0;
}

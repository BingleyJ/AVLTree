#include "AVLTree.h"
#include <conio.h>
#include <iostream>

using namespace std;


AVLTree::AVLTree()
{
    root = NULL;
}

AVLTree::~AVLTree()
{
    //dtor
}

AvlNode *AVLTree::GetRoot()
{
    AvlNode *temp = root;
    return temp;
}


int AVLTree::Height(AvlNode *node)
{
    int height = 0;
    if(node != NULL)
    {
        int leftHeight = Height(node->left);
        int rightHeight = Height(node->right);
        int maxHeight = max(leftHeight, rightHeight);
        height = maxHeight + 1;
    }
    return height;
}


int AVLTree::Diff(AvlNode *node)
{
    int leftHeight = Height(node->left);
    int rightHeight = Height(node->right);
    int b_factor = leftHeight - rightHeight;
    return b_factor;
}
AvlNode *AVLTree::RRRotation(AvlNode *parent)
{
    AvlNode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
AvlNode *AVLTree::LLRotation(AvlNode *parent)
{
    AvlNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
AvlNode *AVLTree::LRRotation(AvlNode *parent)
{
    AvlNode *temp;
    temp = parent->left;
    parent->left = this->RRRotation(temp);
    return this->LLRotation(parent);
}
AvlNode *AVLTree::RLRotation(AvlNode *parent)
{
    AvlNode *temp;
    temp = parent->right;
    parent->right = this->LLRotation(parent);
    return this->RRRotation(parent);
}
AvlNode *AVLTree::BalanceTree(AvlNode *node)
{
    cout << "Balance Tree/n";
    int balanceFactor = this->Diff(node);
    if(balanceFactor > 1)
    {
        if(this->Diff(node->left) > 0)
        {
            node = LLRotation(node);
        }
        else
        {
            node = LRRotation(node);
        }
    }
    else if(balanceFactor < -1)
    {
        if(this->Diff(node->right) > 0)
        {
            node = RLRotation(node);
        }
        else
        {
            node = RRRotation(node);
        }
    }
    return node;
}
void AVLTree::InsertNode(char data)
{
    root = InsertNode(root, data);
}
AvlNode *AVLTree::InsertNode(AvlNode *root, char data)
{
    if(root == NULL)
    {
        root = new AvlNode;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(data < root->data)
    {
        root->left = this->InsertNode(root->left, data);
        root = this->BalanceTree(root);
    }
    else if(data >= root->data)
    {
        root->right = this->InsertNode(root->right, data);
        root = this->BalanceTree(root);
    }
    return root;
}
void AVLTree::Display()
{
    int level = 0;
    this->Display(root, level);
}

void AVLTree::Display(AvlNode *node, int level)
{
    int i;
    if (node!=NULL)
    {
        Display(node->right, level + 1);
        cout<<"\n";
        if (node == root)
        cout<<"ROOT->";
        for (i = 0; i < level && node != root; i++)
            cout<<"        ";
        cout<<node->data;
        Display(node->left, level + 1);
    }
}

void AVLTree::InOrder(AvlNode *node)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        this->InOrder(node->left);
        cout << node->data << " ";
        this->InOrder(node->right);
    }
}
void AVLTree::PostOrder(AvlNode *node)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        this->PostOrder(node->left);
        this->PostOrder(node->right);
        cout << node->data << " ";
    }
}
void AVLTree::PreOrder(AvlNode *node)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        cout << node->data << " ";
        this->PreOrder(node->left);
        this->PreOrder(node->right);
    }
}

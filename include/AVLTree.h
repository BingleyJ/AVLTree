#ifndef AVLTREE_H
#define AVLTREE_H

struct AvlNode
{
    char data;
    AvlNode *right;
    AvlNode *left;
};

class AVLTree

{
public:
    AVLTree();
    virtual ~AVLTree();
    void InsertNode(char data);
    int Height(AvlNode *node);
    int Diff(AvlNode *node);
    void InOrder(AvlNode *node);
    void PreOrder(AvlNode *node);
    void PostOrder(AvlNode *node);
    AvlNode *RRRotation(AvlNode *parent);
    AvlNode *LLRotation(AvlNode *parent);
    AvlNode *LRRotation(AvlNode *parent);
    AvlNode *RLRotation(AvlNode *parent);
    AvlNode *BalanceTree(AvlNode *node);
    AvlNode *InsertNode(AvlNode *root, char data);
    void Display();
    void Display(AvlNode *node, int level);
    AvlNode *GetRoot();
protected:
private:
     AvlNode *root;
};

#endif // AVLTREE_H

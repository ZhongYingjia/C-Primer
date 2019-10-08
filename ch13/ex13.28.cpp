#include "ex13.28.h"

TreeNode& TreeNode::operator=(const TreeNode &rhs)
{
    ++*rhs.count;
    if(--*count == 0){
        if(left){
            delete left;
            left = nullptr;
        }
        if(right){
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
    }

    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    return *this;
}

TreeNode::~TreeNode()
{
    if(--*count == 0){
        if(left){
            delete left;
            left = nullptr;
        }
        if(right){
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
    }
}

BinStrTree& BinStrTree::operator=(const BinStrTree& rhs)
{
    TreeNode* new_root = new TreeNode(*rhs.root);
    delete root;
    root = new_root;
    return *this;

}
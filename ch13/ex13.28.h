#ifndef EX13_28_H
#define EX13_28_H

#include <string>

class TreeNode{
public:
    TreeNode(std::string s = std::string()):
        value(s), count(new int(1)), left(nullptr), right(nullptr){ }
    TreeNode(const TreeNode &rhs):
        value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right){
            ++*count;
        }
    TreeNode& operator=(const TreeNode &);
    ~TreeNode();

private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};


class BinStrTree{
public:
    BinStrTree():root(new TreeNode()){ }
    BinStrTree(const BinStrTree&orgi):root(new TreeNode(*orgi.root)){ }
    BinStrTree& operator=(const BinStrTree&);
    ~BinStrTree(){ delete root; }
private:
    TreeNode *root;
};




#endif
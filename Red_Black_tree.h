//
// Created by ts on 25/05/19.
//

#ifndef ADT_BTS_RED_BLACK_TREE_H
#define ADT_BTS_RED_BLACK_TREE_H

enum Color{RED, BLACK, DOUBLE_BLACK};

struct Node{
    int data;
    bool color;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data){
        this->data = data;
        this->left =  nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

};

class Red_Black_tree{

private:
    Node *root;
    Node *nil;

protected:

    Node *insertBST(Node *&, Node *&);
    Node *deleteBST(Node *&, int);

    Node *minValueNode(Node *&);
    Node *maxValueNode(Node *&);

    void inorderShow(Node *&);
    void levelOrderShow(Node *&);

    void rotateLeft(Node *&);
    void rotateRight(Node *&);
    void fixInsertRBTree(Node *&);
    void fixDeleteRBTree(Node *&);


    void setColor(Node *&, int);
    int isEquals(Node *&, Node *&);
    int getBlackHeight(Node *&);
    int getColor(Node *&);

public:



    Red_Black_tree() {
        this->root = nullptr;

    }
    void insertValue(const int &address_data);
    void inorder();
    void levelOrder();

};


#endif //ADT_BTS_RED_BLACK_TREE_H

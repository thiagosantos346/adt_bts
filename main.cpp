#include <iostream>
#include <bits/stdc++.h>

using namespace std;

enum Color{RED, BLACK};

struct Node{
    int data;
    bool color;
    Node *left;
    Node *right;
    Node *parente;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->parente = NULL;
    }

};

class Red_Black_tree{
private:
    Node *root;
protected:

    void fixViolation(Node *&, Node &&);

public:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    Red_Black_tree() {
        this->root = NULL;
    }
    void insert(const int &address_data);
    void inorder();
    void levelOrder();

};

void inorder_view(Node *root_adrres){
    if(root_adrres == NULL){
        return;
    }

    inorder_view(root_adrres->left);
    cout << root_adrres->data << " ";
    inorder_view(root_adrres->right);
}

void levelOrder_view(Node *root_adrres){
    if(root_adrres == NULL){
        return;
    }

    std::queue<Node *> queue_nodes;
    queue_nodes.push(root_adrres);

    while (! queue_nodes.empty()){
        Node *temp_node = queue_nodes.front();
        cout << temp_node->data << " ";
        queue_nodes.pop();

        if(temp_node->left != NULL){
            queue_nodes.push(temp_node->left);
        }

        if(temp_node->right != NULL){
            queue_nodes.push(temp_node->right);
        }
    }
}

Node *insert_node(Node *root_address, Node *node_to_insert ){

    if(root_address == NULL){

        return node_to_insert;

    }
    if(node_to_insert->data < root_address->data ){

        root_address->left = insert_node(root_address->left, node_to_insert);
        root_address->left->parente = root_address;

    }else if(node_to_insert->data > root_address->data){
        root_address->right = insert_node(root_address->right, node_to_insert);
        root_address->right = insert_node(root_address->right, node_to_insert);
    }

    return root_address;

}

void Red_Black_tree::rotateLeft(Node *&root_local, Node *&node_position){
    Node *copy_right_child = node_position->right;

    node_position->right = copy_right_child->left;

    if(node_position != NULL){
        node_position->parente = node_position;
    }

    copy_right_child->parente = node_position->parente;

    if(node_position->parente == NULL){

        root_local = copy_right_child;

    }else if(node_position == node_position->parente->left){

        node_position->right = copy_right_child;

    }else{

        node_position->left = copy_right_child;

    }

    copy_right_child->left = node_position;
    node_position->parente = copy_right_child;

}

void Red_Black_tree::rotateRight(Node *&root_adress, Node *&node_position){
    Node *copy_left_child = node_position->left;

    node_position->left = copy_left_child->right;

    if( node_position != NULL){
        node_position->parente = node_position;
    }

    copy_left_child->parente = node_position->parente;

    if(node_position->parente != NULL){

        root_adress = copy_left_child;

    } else if( node_position = node_position->parente->left ){

        node_position->left = copy_left_child;

    } else{

        node_position->right = copy_left_child;

    }

    copy_left_child->right = node_position;
    node_position = copy_left_child;

}



void Red_Black_tree::insert(const int &address_data) {
    Node *new_node_address = new Node(address_data);

    root = insert_node(root, new_node_address);

}

void Red_Black_tree::inorder(){
    inorder_view(root);
}

void Red_Black_tree::levelOrder() {
    levelOrder_view(root);
}

int main() {
    Red_Black_tree tree;

    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.inorder();
    tree.levelOrder();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

//https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
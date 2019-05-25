//
// Created by ts on 25/05/19.
//
#include <iostream>
#include <bits/stdc++.h>
#include "Red_Black_tree.h"
#include <signal.h>
#define  true 1
#define false 0
using namespace std;

Node * Red_Black_tree:: insertBST(Node *&root_address, Node *&node_to_insert ){

    if(root_address == nullptr){

        return node_to_insert;

    }
    if(node_to_insert->data < root_address->data ){

        root_address->left = insertBST(root_address->left, node_to_insert);
        root_address->left->parent = root_address;

    }else if(node_to_insert->data > root_address->data){
        root_address->right = insertBST(root_address->right, node_to_insert);
        root_address->right = insertBST(root_address->right, node_to_insert);
    }

    return root_address;

}

void Red_Black_tree::inorderShow(Node *&root_address){
    if(root_address == nullptr){
        return;
    }

    inorderShow(root_address->left);
    cout << root_address->data << " ";
    inorderShow(root_address->right);
}

void Red_Black_tree::levelOrderShow(Node *&root_address){
    if(root_address == nullptr){
        return;
    }

    std::queue<Node *> queue_nodes;
    queue_nodes.push(root_address);

    while (! queue_nodes.empty()){
        Node *temp_node = queue_nodes.front();
        cout << temp_node->data << " ";
        queue_nodes.pop();

        if(temp_node->left != nullptr){
            queue_nodes.push(temp_node->left);
        }

        if(temp_node->right != nullptr){
            queue_nodes.push(temp_node->right);
        }
    }
}

void Red_Black_tree::rotateLeft(Node *&node_position){
    Node *copy_right_child = node_position->right;

    node_position->right = copy_right_child->left;

    if(node_position != nullptr){
        node_position->parent = node_position;
    }

    copy_right_child->parent = node_position->parent;

    if(node_position->parent == nullptr){

        this->root = copy_right_child;

    }else if(node_position == node_position->parent->left){

        node_position->right = copy_right_child;

    }else{

        node_position->left = copy_right_child;

    }

    copy_right_child->left = node_position;
    node_position->parent = copy_right_child;

}

void Red_Black_tree::rotateRight(Node *&node_position){
    Node *copy_left_child = node_position->left;

    node_position->left = copy_left_child->right;

    if( node_position != nullptr){
        node_position->parent = node_position;
    }

    copy_left_child->parent = node_position->parent;

    if(node_position->parent != nullptr){

        this->root = copy_left_child;

    } else if( node_position = node_position->parent->left ){

        node_position->left = copy_left_child;

    } else{

        node_position->right = copy_left_child;

    }

    copy_left_child->right = node_position;
    node_position = copy_left_child;

}

void Red_Black_tree::inorder(){
    inorderShow(root);
}

void Red_Black_tree::levelOrder() {
    levelOrderShow(root);
}

int Red_Black_tree::isEquals(Node *&firstNode, Node *&secondNode) {


    if(!firstNode){
        return 0;
    }

    if(!secondNode){
        return 0;
    }

    if( (firstNode) == (secondNode) ) {

        return 1;
    }


    return 0;


}


void Red_Black_tree::fixInsertRBTree(Node *&node_to_fix) {
    Node *parent_node_to_fix = nullptr;
    Node *grand_parent_node_to_fix = nullptr;
    if(node_to_fix->parent != nullptr)
        if(node_to_fix->parent->parent != nullptr)
    while (  node_to_fix != nullptr&&
            (getColor(node_to_fix) == RED &&
             getColor(node_to_fix->parent) == RED)  ){

        parent_node_to_fix = node_to_fix->parent;

        grand_parent_node_to_fix = parent_node_to_fix->parent->parent;

        /*  Case : A
            Parent of pt is left child of Grand-parent of pt */

        if( isEquals( parent_node_to_fix, grand_parent_node_to_fix->left) == true){

            Node *uncle_node_to_fix = grand_parent_node_to_fix->right;
            /* Case : 1
             * The uncle of node_to_fix is also red.
             * Only [recoloring] required*/

            if(uncle_node_to_fix != nullptr && getColor(uncle_node_to_fix) == RED){

                setColor(grand_parent_node_to_fix  , RED);
                setColor(parent_node_to_fix        , BLACK);
                setColor(uncle_node_to_fix         , BLACK);
                setColor(node_to_fix               , BLACK);

            }
            else{

                /*
                 * Case : 2
                 * [node_to_fix] is right child of ist parent
                 * [left-Rotation] required*/

                if(node_to_fix == parent_node_to_fix->right){

                    rotateLeft(parent_node_to_fix);
                    node_to_fix = parent_node_to_fix;
                    parent_node_to_fix = node_to_fix->parent;

                }
                /*
                 * Case : 3
                 * [node_to_fix] is left child of its parent
                 * [right-Rotation] required*/

                rotateRight(grand_parent_node_to_fix);
                swap(parent_node_to_fix->color, grand_parent_node_to_fix->color);
                node_to_fix = parent_node_to_fix;

            }

        }else{

            /*Case : B
             * Parent of node_to_fix is right child of [Grand-Parent]
             * of node_to_fix*/

            Node *uncle_node_to_fix = grand_parent_node_to_fix->left;
            /* Case : 1
             * The uncle of node_to_fix is also red.
             * Only [recoloring] required*/
            if( (uncle_node_to_fix != nullptr) && uncle_node_to_fix->color == RED ){

                setColor( grand_parent_node_to_fix , RED);
                setColor( parent_node_to_fix       , BLACK);
                setColor( uncle_node_to_fix        , BLACK);
                setColor( node_to_fix              , BLACK);

            }else{
                /*
                * Case : 2
                * [node_to_fix] is left child of ist parent
                * [right-Rotation] required*/
                if(node_to_fix ==  uncle_node_to_fix->left ){

                    rotateRight(node_to_fix);
                    node_to_fix = parent_node_to_fix;
                    parent_node_to_fix = node_to_fix->parent;

                }
                /*
                * Case : 3
                * [node_to_fix] is right child of its parent
                * [left-Rotation] required*/
                rotateRight(grand_parent_node_to_fix);
                swap(this->root->color, grand_parent_node_to_fix->color);
                node_to_fix = parent_node_to_fix;

            }


        }

        this->root->color = BLACK;

    }

}

void Red_Black_tree::insertValue(const int &address_data) {
    Node *new_node_address = new Node(address_data);

    root = insertBST(root, new_node_address);

    fixInsertRBTree(new_node_address);

}

int Red_Black_tree::getColor(Node *&thisNode) {
    if(thisNode == nullptr){
        return  BLACK;
    }

    return thisNode->color;

}

void Red_Black_tree::setColor(Node *&forThisNode, int thisColor) {

    if(forThisNode == nullptr){
        return;
    }

    forThisNode->color = thisColor;

}


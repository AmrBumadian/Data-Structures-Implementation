//
// Created by Amr Bumadian on 1/8/2021.
//

#ifndef BT_BTREE_H
#define BT_BTREE_H

#include <iostream>

using namespace std;

template<typename T, int order>
class Node {
public:
    T *keys;
    Node<T, order> **children;
    int keysNumber;

    Node() : keysNumber(0) {
        keys = new T[order - 1];
        children = new Node<T, order> *[order];
        for (int i = 0; i < order; ++i) children[i] = nullptr;
    }
};

template<typename T, int order>
class BTree {
private:
    Node<T, order> *root;
    int length;

    void insertNode(Node<T, order> *current, const T &insertItem,
                    Node<T, order> *&rightChild, int insertPosition) {
        int index;
        for (index = current->keysNumber; index > insertPosition; --index) {
            current->keys[index] = current->keys[index - 1];
            current->children[index + 1] = current->children[index];
        }
        current->keys[index] = insertItem;
        current->children[index + 1] = rightChild;
        current->keysNumber++;
    } //end insertNode

    void splitNode(Node<T, order> *current, const T &insertItem, Node<T, order> *&rightChild,
                   int insertPosition, Node<T, order> *&rightNode, T &median) {
        rightNode = new Node<T, order>;
        int mid = (order - 1) / 2;

        //new item goes in the first half of the node
        if (insertPosition <= mid) {
            int index = 0;
            int i = mid;
            while (i < order - 1) {
                rightNode->keys[index] = current->keys[i];
                rightNode->children[index + 1] = current->children[i + 1];
                index++;
                i++;
            }
            current->keysNumber = mid;
            insertNode(current, insertItem, rightChild, insertPosition);
            --current->keysNumber;
            median = current->keys[current->keysNumber];
            rightNode->keysNumber = index;
            rightNode->children[0] = current->children[current->keysNumber + 1];
        } else { //new item goes in the second half of the node
            int i = mid + 1;
            int index = 0;
            while (i < order - 1) {
                rightNode->keys[index] = current->keys[i];
                rightNode->children[index + 1] = current->children[i + 1];
                index++;
                i++;
            }
            current->keysNumber = mid;
            rightNode->keysNumber = index;
            rightNode->keys[i + 1] = median;
            median = current->keys[mid];
            insertNode(rightNode, insertItem, rightChild, insertPosition - mid - 1);
            rightNode->children[0] = current->children[current->keysNumber + 1];
        }
    } //splitNode

    void searchNode(Node<T, order> *current, const T &item, bool &found, int &location) {
        location = 0;
        while (location < current->keysNumber && item > current->keys[location])
            ++location;
        if (location < current->keysNumber && item == current->keys[location])
            found = true;
        else found = false;
    } //end searchNode

    void traverse(Node<T, order> *node, int level) { // print level by level
        for (int i = 0; i < node->keysNumber; ++i) {
            cout << " " << node->keys[i];
        }
        cout << endl;
        int i;
        for (i = 0; i < node->keysNumber; ++i) {
            if (node->children[i] != nullptr) {
                cout << "  " << string(level, ' ');
                traverse(node->children[i], level + 1);
            }
        }
        if (node->children[i] != nullptr) {
            cout << "  " << string(level, ' ');
            traverse(node->children[i], level + 1);
        }
    } // end traverse

    void insertBTree(Node<T, order> *current, T &insertItem, T &median,
                     Node<T, order> *&rightChild, bool &isTaller) {
        if (current == nullptr) {
            median = insertItem;
            rightChild = nullptr;
            isTaller = true;
        } else {

            bool found;
            int location;
            searchNode(current, insertItem, found, location);
            if (found) {
                cerr << "Node already exists\n";
            } else {
                insertBTree(current->children[location], insertItem, median, rightChild, isTaller);
                if (isTaller) {
                    if (current->keysNumber != order - 1) {
                        // insert item into current
                        int i = current->keysNumber - 1;
                        while (i >= 0 && current->keys[i] > median) {
                            current->keys[i + 1] = current->keys[i];
                            --i;
                        }
                        current->keys[i + 1] = median;
                        ++current->keysNumber;
                        isTaller = false;
                        i = 0;

                        if (rightChild != nullptr) {
                            T val = rightChild->keys[rightChild->keysNumber - 1];
                            //while (current->children[i] != nullptr) ++i;

                            for (int j = order - 1; j >= 0; --j) {
                                auto temp = current->children[j];
                                if (current->children[j] != nullptr) {
                                    if (temp->keys[0] > val) {
                                        current->children[j + 1] = temp;
                                    } else {
                                        i = j + 1;
                                        break;
                                    }
                                }
                            }
                        }
                        current->children[i] = rightChild;

                    } else {
                        //call the function splitNode to split the node
                        Node<T, order> *rightNode;
                        insertItem = median;
                        splitNode(current, insertItem, rightChild, location, rightNode, median);
                        rightChild = rightNode;
                    }
                }
            }
        }
    }


public:

    BTree() : length(0) {
        root = nullptr;
    }

    void insert(T insertItem) {
        bool isTaller = false;
        T median;
        Node<T, order> *rightChild;
        insertBTree(root, insertItem, median, rightChild, isTaller);
        if (isTaller) {
            Node<T, order> *newNode = new Node<T, order>;
            newNode->keysNumber = 1;
            newNode->keys[0] = median;
            newNode->children[0] = root;
            newNode->children[1] = rightChild;
            root = newNode;
        }
    }

    void print() {
        traverse(root, 0);
    }
};


#endif //BT_BTREE_H

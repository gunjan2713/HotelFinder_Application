#include "bst.hpp"

// constructor
template <typename T1, typename T2>
BST<T1, T2>::BST() {
//  tree is initially empty
    root = nullptr;
}

// helper function of destructor
template <typename T1, typename T2>
void BST<T1, T2>::deleteTree(Node<T1, T2>* root) {
// if tree is epmty, it simply returns
    if (root == nullptr) {
        return;
    }
// recurse and delete
    deleteTree(root->left);
// recurse and delete
    deleteTree(root->right);
// finally delte the root
    delete root;
}

// destructor
template <typename T1, typename T2>
BST<T1, T2>::~BST() {
// calls deleteTree helper function
    deleteTree(root);
}

// returns the root of the BST
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::getRoot() {
    return root;
}

// insert a node into the BST
template <typename T1, typename T2>
void BST<T1, T2>::insert(Node<T1, T2>* ptr, T1 key, T2 value) {
    //checks if the tree is empty 
    if (root == nullptr) {
    // create a new root node
        root = new Node<T1, T2>(key);
// adds the value to the node's value list
        root->value.push_back(value);
      
        return;
    }

    // if the tree is not empty, if the key is less than the current node's key, move to left subtree
    if (key < ptr->key) {
        // if the left child is null
        if (ptr->left == nullptr) {
            // create a new node and set it as the left child
            ptr->left = new Node<T1, T2>(key);
    //   its parent is set to the current node ptr
            ptr->left->parent = ptr; 
    // value is added to the value list of the newly created node
            ptr->left->value.push_back(value); 
        } else {
            // ifthe left child exists, recursively insert into the left subtree
            insert(ptr->left, key, value);
        }
    //  if the key is more than the current node's key, move to right subtree
    } else if (key > ptr->key) {
        // if the right child is null
        if (ptr->right == nullptr) {
            // create a new node and set it as the right child
            ptr->right = new Node<T1, T2>(key);
              //   its parent is set to the current node ptr
            ptr->right->parent = ptr; 
       // value is added to the value list of the newly created node         
            ptr->right->value.push_back(value); 
        } else {
            // ifthe right child exists, recursively insert into the right subtree
            insert(ptr->right, key, value);
        }
    } else {
        // if the key already exists in the tree, add the value to the existing node
        ptr->value.push_back(value);
    }
}

// calculate the height of the tree
template <typename T1, typename T2>
int BST<T1, T2>::height(Node<T1, T2>* ptr) {
// if tree is empty, return 0
    if (ptr == nullptr) {
        return 0;
    }
// recurse through the left subree to find the leftheight
    int leftHeight = height(ptr->left);
 // recurse through the right subree to find the rightheight
    int rightHeight = height(ptr->right);
// it return the final height of the tree
    return 1 + max(leftHeight, rightHeight);
}

// find a node with a speciific key
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::find(Node<T1, T2>* ptr, T1 key, string stars) {
//  if ptr is nullptr, it means we have reached a leaf node (or an empty subtree), or if key matches the target
    if (ptr == nullptr || ptr->key == key) {
// if we found a node with the target key
        if (ptr != nullptr) {
// call print method of the hotel class
            ptr->print(stars); 
        }
        return ptr; 
    }
// if the key  is less than the key of the current node ptr
    if (key < ptr->key) {
//    we recursively call the find function on the left subtree
        return find(ptr->left, key, stars); 
    }
    // if the  key is greater than the current node's key, recursively search in the right subtree
    return find(ptr->right, key, stars); 
}


// find the node with the minimum key value
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::findMin(Node<T1, T2>* ptr) {
// if tree is empty return null
    if (ptr == nullptr) {
        return nullptr;
    }
// loop is used to traverse the tree to the left until the leftmost node is reached
    while (ptr->left != nullptr) {
    // update the pointer to it's left child
        ptr = ptr->left;
    }
    return ptr;
}

// removes a node from the BST
template <typename T1, typename T2>
void BST<T1, T2>::remove(Node<T1, T2>* ptr, T1 key, T2 value) {
    // if tree is empty, simply return
    if (ptr == nullptr) {
        return;
    }
// if key is less than the current node's key
    if (key < ptr->key) {
    // remove function is called recursively on the left child of the current node
        remove(ptr->left, key, value);
    // key is greater than the current node's key
    } else if (key > ptr->key) {
    // remove function is called recursively on the right child of the current node
        remove(ptr->right, key, value);
// found the node with the desired key
    } else { 
    // iterates over values associated with current node,multiple values might have the same key in the BST
        for (auto it = ptr->value.begin(); it != ptr->value.end(); ++it) {
    // checks if any of the values matches the value we want to remove
            if (*it == value) {
        // erases that specific value from the list
                ptr->value.erase(it);
                cout << "Erased" << endl;
                break;
            }
        }
// list of values associated with the current node is empty after the removal
        if (ptr->value.empty()) {
    // if the node we want to remove  has no children
            if (ptr->left == nullptr && ptr->right == nullptr) {
                // if ptr is root node
                if (ptr == root) {
        // roots becomes nullll now
                    root = nullptr;
            // if it's a left child of its paren
                } else if (ptr == ptr->parent->left) {
                // sets the left child of its parent to nullptr
                    ptr->parent->left = nullptr;
                } else {
                // if it's a right child of its parent, it sets the right child of its parent to nullptr
                    ptr->parent->right = nullptr;
                }
                delete ptr;
        //  /Case 2: Node has only a right child
            } else if (ptr->left == nullptr) {
            //    sets a temporary pointer temp to ptr->right
                Node<T1, T2>* temp = ptr->right;
        // node being removed is the root
                if (ptr == root) {
                // updates the root to point to temp
                    root = temp;
            // node being removed is a left child of its paren
                } else if (ptr == ptr->parent->left) {
                // updates the left child of its parent to point to temp
                    ptr->parent->left = temp;
                // node being removed is a right child of its paren
                } else {
                // updates the right child of its parent to point to temp
                    ptr->parent->right = temp;
                }
                if (temp != nullptr) {
                    temp->parent = ptr->parent;
                }
                delete ptr;
        // // Case 3: Node has only a left child
            } else if (ptr->right == nullptr) {
               //    sets a temporary pointer temp to ptr->left
                Node<T1, T2>* temp = ptr->left;
                // node being removed is the root
                if (ptr == root) {
                    // updates the root to point to temp
                    root = temp;
                     // node being removed is a left child of its paren
                } else if (ptr == ptr->parent->left) {
                    // updates the left child of its parent to point to temp
                    ptr->parent->left = temp;
                      // node being removed is a right child of its paren
                } else {
                    
                       // updates the right child of its parent to point to temp
                    ptr->parent->right = temp;
                }
            // if temp is not null
                if (temp != nullptr) {
                // updsdate the parent 
                    temp->parent = ptr->parent;
                }
                delete ptr;
       // Case 4: Node has both left and right children
            } else {
            //finds the node with the minimum key in the right subtree
                Node<T1, T2>* successor = findMin(ptr->right);
            // copy its key and value to the current node
                ptr->key = successor->key;
                ptr->value = successor->value;
            // call remove
                remove(ptr->right, successor->key, successor->value[0]);
            }
        }
    }
}

// instantiations for the template classes used
template class BST<string, Hotel*>;  
template class Node<string, Hotel*>;  

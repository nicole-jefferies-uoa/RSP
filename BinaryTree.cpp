#include <iostream>

struct node
{
    int data;
    // node *parent;
    node *right_child;
    node *left_child;
};

class binary_tree
{
public:
    node *create_node(int data)
    {
        node *newNode = new node;
        newNode->data = data;
        newNode->left_child = NULL;
        newNode->right_child = NULL;

        return newNode;
    }

    node *insert_new_node(node *rootNode, int data)
    {
        if (rootNode == NULL)
            return create_node(data);

        else if (data > rootNode->data)
            rootNode->right_child = insert_new_node(rootNode->right_child, data);
        else
            rootNode->left_child = insert_new_node(rootNode->left_child, data);

        return rootNode;
    }

    node *search_tree(node *rootNode, int data)
    {
        if (rootNode == NULL || rootNode->data == data)
            return rootNode;
        else if (data > rootNode->data)
            return search_tree(rootNode->right_child, data);
        else
            return search_tree(rootNode->left_child, data);
    }

    node *find_minimum(node *rootNode)
    {
        if (rootNode == NULL)
            return NULL;

        else if (rootNode->left_child != NULL)
            return find_minimum(rootNode->left_child);

        return rootNode;
    }
};

int main(){
    binary_tree *tree = new binary_tree;

    node *root = tree->create_node(26);

    tree->insert_new_node();

    return 0;
}
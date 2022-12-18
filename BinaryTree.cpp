#include <iostream>

struct node
{
    int data;
    node *right_child;
    node *left_child;
};

class binary_tree
{
public:
    node *rootNode;

    binary_tree(){}

    binary_tree(int data){
        rootNode = create_node(data);
    }

    node *create_root_node(int data){
        rootNode = create_node(data);
    }

    node *create_node(int data)
    {
        node *newNode = new node;
        newNode->data = data;
        newNode->left_child = NULL;
        newNode->right_child = NULL;

        return newNode;
    }

    node *insert_new_node(int data)
    {
        insert(rootNode, data);
    }

    node *insert(node *rootNode, int data)
    {
        if (rootNode == NULL)
            return create_node(data);

        else if (data > rootNode->data)
            rootNode->right_child = insert(rootNode->right_child, data);
        else
            rootNode->left_child = insert(rootNode->left_child, data);

        return rootNode;
    }

    node *search_tree(int data){
        search_tree(rootNode, data);
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

    
    node *find_minimum(){
        find_minimum(rootNode);
    }
    
    node *find_minimum(node *rootNode)
    {
        if (treeEmpty(rootNode))
            return NULL;

        else if (rootNode->left_child != NULL)
            return find_minimum(rootNode->left_child);

        return rootNode;
    }

    void printInOrder(){
        std::cout << "Printing BST:" << std::endl;
        printInOrder(rootNode);
    }
    
    void printInOrder(node *rootNode)
    {
        if (rootNode != NULL)
        {
            printInOrder(rootNode->left_child);
            std::cout << rootNode->data << std::endl;
            printInOrder(rootNode->right_child);
        }
    }

    node *delete_node(int data){
        delete_node(rootNode, data);
    }

    node *delete_node(node *rootNode, int data)
    {
        if (treeEmpty(rootNode))
            return NULL;

        if (data > rootNode->data)
            rootNode->right_child = delete_node(rootNode->right_child, data);

        else if (data < rootNode->data)
            rootNode->left_child - delete_node(rootNode->left_child, data);

        else
        {
            if (rootNode->left_child == NULL && rootNode->right_child == NULL)
            {
                this->rootNode = NULL;
                return NULL;
            }

            else if (rootNode->left_child == NULL || rootNode->right_child == NULL)
            {
                node *temp;
                if (rootNode->left_child == NULL)
                    temp = rootNode->right_child;
                else
                    temp = rootNode->left_child;
                this->rootNode = temp;
                return temp;
            }

            else
            {
                node *temp = find_minimum(rootNode->right_child);
                rootNode->data = temp->data;
                rootNode->right_child = delete_node(rootNode->right_child,temp->data); 
            }
        }
    }

    bool treeEmpty(node *rootNode)
    {
        if (rootNode == NULL)
            return true;
        return false;
    }

};

int main()
{

    std::cout << "Creating new binary tree with root 12" << std::endl;

    binary_tree *tree = new binary_tree(12);

    tree->printInOrder();

    tree->insert_new_node(26);

    std::cout << "Inserted 26" << std::endl;

    tree->insert_new_node(78);

    std::cout << "Inserted 78" << std::endl;

    tree->printInOrder();

    tree->insert_new_node(34);

    std::cout << "Inserted 34" << std::endl;

    tree->printInOrder();

    //tree->delete_node(34);

    //std::cout << "Deleted 34" << std::endl;

    //tree->printInOrder();

    return 0;
}
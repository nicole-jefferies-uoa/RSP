#include <iostream>

struct node
{
    int data;
    node *next_node;
};

class linked_list
{

public:
    node *listHead, *listTail;

    linked_list()
    {
        listHead = NULL;
        listTail = NULL;
    }

    void add_node(int data)
    {
        node *newNode = new node;
        newNode->data = data;
        newNode->next_node = NULL;

        if (listHead == NULL) // if list is empty
        {
            listHead = newNode;
            listTail = newNode;
        }
        else
        {
            listTail->next_node = newNode;
            listTail = newNode;
        }
    }

    node *search_list(int data)
    {
        node *currentNode = listHead;
        while (currentNode->next_node != NULL)
        {
            if (currentNode->data == data)
            {
                std::cout << data << " found at: " << currentNode << std::endl;
                return currentNode;
            }

            currentNode = currentNode->next_node;
        }

        std::cout << data << " not found in linked list" << std::endl;
        return NULL;
    }

    void delete_node(int data){
        if(listHead == NULL)
            return;

        if(listHead->data == data)
            listHead = listHead->next_node;

        if(search_list == NULL)
            std:cout << 
    }

};

int main()
{
    linked_list list;

    list.add_node(7);
    list.add_node(22);

    list.search_list(7);
    list.search_list(17);

    return 0;
}

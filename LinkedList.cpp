#include <iostream>

struct node
{
    int data;
    node *next_node;
    node *previous_node;
};

class linked_list
{
    private:
        node *head_of_list, *tail_of_list;
    public:
        linked_list(){
            head_of_list = NULL;
            tail_of_list = NULL;
        }

        void insert_node_to_beginning_of_list(int node){
            
        }

};


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
enum status{Unexplored, PartiallyExplored, FullyExplored};


typedef struct list_node {
  int index_of_item;
  struct list_node *next;
}list_node;


typedef struct node {
  int data;
  enum status status;
  list_node *head;
}node;


typedef struct graph{
  std::queue<node*> q;
  int number_of_vertices;
  node heads_of_adjacency_lists[]; 
}graph;

node* new_node(int data) {
  node *n;
  n = new node;
  n->data = data;
  n->head = NULL;
  n->status = Unexplored;

  return n;
}

list_node* new_list_node(int item_index) {
  list_node *ln;
  ln = new list_node;
  ln->index_of_item = item_index;
  ln->next = NULL;

  return ln;
}

graph* new_graph(int number_of_vertices) {
  graph *g = new graph;
  g->number_of_vertices = number_of_vertices;

  for(int i=0; i < number_of_vertices; i++) {
    node *nodePointer = new_node(-1); 
    g->heads_of_adjacency_lists[i] = *nodePointer; 
  }

  return g;
}

void add_node_to_graph(graph *g, int data) {
  node *n = new_node(data);
  
  for(int i=0; i<g->number_of_vertices; i++) {
    if (g->heads_of_adjacency_lists[i].data == -1) {
      g->heads_of_adjacency_lists[i] = *n; 
      break; 
    }
  }
}


int check_in_graph_head_list(graph *g, int data) {
  for(int i=0; i<g->number_of_vertices; i++) {
    if(g->heads_of_adjacency_lists[i].data == data)
      return 1;
  }
  return 0;
}


void add_edge(graph *g, int source, int dest) {
  if(check_in_graph_head_list(g, source) == 0) {
    add_node_to_graph(g, source);
  }
  
  if(check_in_graph_head_list(g, dest) == 0) {
    add_node_to_graph(g, dest);
  }


  // find the source node
  for(int i=0; i<g->number_of_vertices; i++) {
    if(g->heads_of_adjacency_lists[i].data == source) { 

      int dest_index; 
      // find node containg destination element
      for(int j=0; j<g->number_of_vertices; j++) {
        if(g->heads_of_adjacency_lists[j].data == dest) { 
          dest_index = j;
          break;
        }
      }

      list_node *n = new_list_node(dest_index); 
      if (g->heads_of_adjacency_lists[i].head == NULL) { 
        g->heads_of_adjacency_lists[i].head = n;
      }
      else { 
        list_node *temp;
        temp = g->heads_of_adjacency_lists[i].head;

        while(temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = n;
      }
      break;
    }
  }
}

void print_graph(graph *g) {
  for(int i=0; i<g->number_of_vertices; i++) {
    list_node *temp;
    temp = g->heads_of_adjacency_lists[i].head;
    printf("%d\t",g->heads_of_adjacency_lists[i].data);
    while(temp != NULL) {
      printf("%d\t",g->heads_of_adjacency_lists[temp->index_of_item].data);
      temp = temp->next;
    }
    printf("\n");
  }
}

void dfs_visit(graph *g, node *i) {
  i->status = PartiallyExplored;

  list_node *temp;
  temp = i->head;
  while(temp != NULL) {
    if (g->heads_of_adjacency_lists[temp->index_of_item].status == Unexplored) {
      dfs_visit(g, &g->heads_of_adjacency_lists[temp->index_of_item]);
    }
    temp = temp->next;
  }
  i->status = FullyExplored;
  printf("%d\n",i->data);
}

void dfs(graph *g) {
  int i;
  for(i=0; i<g->number_of_vertices; i++) {
    g->heads_of_adjacency_lists[i].status = Unexplored;
  }

  for(i=0; i<g->number_of_vertices; i++) {
    if (g->heads_of_adjacency_lists[i].status == Unexplored) {
      dfs_visit(g, &g->heads_of_adjacency_lists[i]);
    }
  }
}

void bfs(graph *g) {
  node s = g->heads_of_adjacency_lists[0];
  for(int i=0; i<g->number_of_vertices; i++) {
    g->heads_of_adjacency_lists[i].status = Unexplored;
  }
  s.status = PartiallyExplored;

  g->q.emplace(&s);

  while(g->q.empty()) {
    g->q.pop();
    list_node *temp;
    temp = g->q.front()->head;
    while(temp != NULL) {
      if (g->heads_of_adjacency_lists[temp->index_of_item].status == Unexplored) {
        g->heads_of_adjacency_lists[temp->index_of_item].status = PartiallyExplored;
        g->q.emplace(&g->heads_of_adjacency_lists[temp->index_of_item]);
      }
      temp = temp->next;
    }
    g->q.front()->status = FullyExplored;
    printf("%d\n", g->q.front()->data);
  }
}

int main() {
  graph *g = new_graph(3);
  add_edge(g, 1, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 3);

  print_graph(g);
  std::cout << std::endl;
  dfs(g);
  std::cout << std::endl;
  bfs(g);
  return 0;
}
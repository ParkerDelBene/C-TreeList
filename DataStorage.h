#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <iostream>
#include <string>
using namespace std;

class TreeList{
public:
  //Constructor initializes the respective starting Nodes to NULL
  TreeList();
  //The Deconstructor calls the deleteCache function which allows for recursive deletion
  //of the TreeList
  ~TreeList();
  //displayItems either displays in date input order, alphabetical, or reverse alphabetical
  //order depending on the toggleAlph integer
  void displayItems();
  //addItem takes an input and then recursively adds it into the TreeList, while also
  //appending it to the end of the embedded LinkedList
  void addItem(int);
  //deleteItem lets you recursively search for a node through the Binary Tree Portion
  //and then also deleting it from the LinkedList.
  void deleteItem();
  // toggleSort is a function that allows you to change the display option through the
  // toggleAlph integer variable.
  void toggleSort();
  // refactorTree is a function that, when called will then call the private refactor
  // function, which optimizes the TreeList by using rotation methods, and then applies the 
  // toggleAlph integer to sort the Linked List Portion.
  void refactorTree();

private:

  struct Node{
    int num;
    Node* next;
    Node* left;
    Node* right;
  };

  //display is a recursive function called by the displayItems public function
  void display(Node*);
  //deleteCache is a recursive functionction called by the deconstructor that recursively deletes 
  //the TreeList data structure
  void deleteCache(Node*);
  //recInsert is a recusive function called by the addItem public function.
  //it has a trailing Node and a current Node which allows it to shift the tree
  //when adding nodes.
  void recInsert(Node*, Node*);
  //this function is to print the TreeList in alphabetical order using the
  //Binary tree portion of the TreeList
  void alphDisplay(Node*);
  //refactor is the tree optimization method that is used to balance the Binary Tree Portion 
  //of the Data Structure
  void refactor(Node*);
  //left is the left rotation function
  void left(Node*);
  //right is the right rotation function;
  void right(Node*);
  //these functions are essentially redundant functions for ease of coding
  //they combine the left right and right left functions for easy rotations.
  void leftright(Node*);
  void rightleft(Node*);
  //this function indicates the height of difference between two subtrees.
  void height(Node*);
  //This function is used to sort the linked list using the Binary Tree Portion
  //of the Node structure.
  void sortList(bool);
  Node* head;
  Node* tail;
  Node* root;
  //used to quickyl assess the items in the TreeList
  int numItems;
  //this int is used to toggle between alphabetical order or date input order.
  bool toggleAlph;

};

#endif

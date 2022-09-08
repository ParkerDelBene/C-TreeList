#include "DataStorage.h"
#include <iostream>
using namespace std;

/*
Initializes the head/tail pointer to NULL and numItems to 0;
*/
TreeList::TreeList(){
  this->numItems = 0;
  this->toggleAlph = 1;
  this->head = NULL;
  this->tail = NULL;
  this->root = NULL;
}

/*
Deletes the allocated memory by calling the passing the head node to the deleteCache function
*/
TreeList::~TreeList(){
  if(this->head != NULL){
    this->deleteCache(this->head);
  }

  cout << "TreeList Deleted" << endl;
}

/*
This function displays all items in the TreeList by calling the recursive display function.
*/
void TreeList::displayItems(){
  if(this->head != NULL){
    if(this->toggleAlph == 0){
      this->display(this->head);
      cout << "NULL";
      cout << endl;
    }
    else{
      this->alphDisplay(this->root);
      cout << "NULL";
      cout << endl;
    }
  }
  else{
    cout << "there are no items in your TreeList." << endl;
  }
}

/*
This Function is called by the displayItems function. It recursively displays the item names.
*/
void TreeList::display(Node* node){
  cout << node->num << "->";
  if(node->next != NULL){
    this->display(node->next);
  }
}

/*
This function allows the user to add and Item to their TreeList list
*/
void TreeList::addItem(int num){


  //Creating trailing Nodes for inserting into the Binary Tree Portion
  Node* temp;
  Node* temp2 ;
  //Creating the new Node
  Node* nodeInsert = new Node;
  //Assigning the int to the Node
  nodeInsert->num = num;
  //Initiating the Node's left,right,and next to NULL until determined 
  //if it will have a left or right node.
  nodeInsert->next = NULL;
  nodeInsert->left = NULL;
  nodeInsert->right = NULL;

  //Assigning the first item if no first item is detected and then just adding the items onto the end of the list.
  if(this->head == NULL){
    this->head = nodeInsert;
    this->numItems++;
  }
  //Assigning to the tail Node if the list has a Head but no Tail
  else if(this->head != NULL && this->tail == NULL){
    this->tail = nodeInsert;
    this->head->next = this->tail;
    this->numItems++;
  }
  //Attaching the Node to the end of the list
  else{
    this->tail->next = nodeInsert;
    this->tail = this->tail->next;
    this->numItems++;
  }

  //Assigning the Binary Tree portion of the TreeList list
  //this will allow the user to sort by alphabetical order and also allow
  //recursive Binary Sorting of the Linked List.
  
  //Assigning to root node of the TreeList is empty
  if(this->root == NULL){
    this->root = nodeInsert;
    this->root->left = NULL;
    this->root->right = NULL;
  }
  //Else, we called the recInsert Function passing the new Node and the root node
  //as a trailing node.
  else{
    this->recInsert(nodeInsert, this->root);
  }

}

/*
This function allows the user to delete an item from their TreeList
*/

void TreeList::deleteItem(){

  int selector;
  Node* temp = this->head;
  Node* temp2;

  //display the TreeList
  this->displayItems();

  //asking for which node the user will want to delete
  cout << "Which one would you like to delete?" << endl;
  cin >> selector;

  //verifying the input is within the actual number of items
  while(selector < 0 || cin.fail() || selector > this->numItems){
    cin.clear();
    cin.ignore();

    cout << "That was not a correct item, please make a correct selection: " ;
    cin >> selector;
    cout << endl;
    cin.ignore();
  }

  for(int i = 0; i < selector; i++){
    temp2 = temp;
    temp = temp->next;
  }

  temp2->next = temp->next;
  delete temp;
  cout << "The item was successfully deleted" << endl;
  this->numItems--;

}


/*
Deletes the entire TreeList recursivly, only called by the destructor
*/
void TreeList::deleteCache(Node* node){
  if(node->next != NULL){
    this->deleteCache(node->next);
  }

  delete node;
}

/*
Recursive function to insert the TreeList item into the alphabetical order in the Binary TreeNode
Portion of the TreeList
*/
void TreeList::recInsert(Node* newNode, Node* currentNode){
  if(newNode->num < currentNode->num){
    if(currentNode->left == NULL){
      currentNode->left = newNode;
    }
    else{
      this->recInsert(newNode,currentNode->left);
    }
  }
  else{
    if(currentNode->right == NULL){
      currentNode->right = newNode;
    }
    else{
      this->recInsert(newNode, currentNode->right);
    }
  }
}

/*
This function recursively prints out the TreeList in alphabetical order
using the imbedded binary tree in the Node Structure
*/
void TreeList::alphDisplay(Node* node){
  if(node->left != NULL){
    this->alphDisplay(node->left);
  }


  cout << node->num << "->";

  if(node->right != NULL){
    this->alphDisplay(node->right);
  }

}

/*
 This function lets you toggle the alph display integer.
*/

void TreeList::toggleSort(){
  if(this->toggleAlph == 1){
    this->toggleAlph = 0;
  }
  else{
    this->toggleAlph = 1;
  }
}

/*
  This function sorts the Linked List using the Binary Tree.
*/
void TreeList::sortList(bool trigger){
  this->head = NULL;
  this->tail = NULL;
  if(trigger){
    this->recSortAsc(this->root);
    this->tail->next == NULL;
  }
  else{
    this->recSortDesc(this->root);
  }
}

/*
  This functin is a subpart of the sortList function
*/
void TreeList::recSortAsc(Node* node){
  if(node->left != NULL){
    this->recSortAsc(node->left);
  }

  if(this->head == NULL){
    this->head = node;
  }
  else if(this->tail == NULL){
    this->tail = node;
    this->head->next = tail;
    this->tail->next = NULL;
  }
  else{
    this->tail->next = node;
    this->tail = node;
    this->tail->next = NULL;
  }

  if(node->right != NULL){
    this->recSortAsc(node->right);
  }

  
}

/*
  This functin is a subpart of the sortList function
*/
void TreeList::recSortDesc(Node* node){
  
}


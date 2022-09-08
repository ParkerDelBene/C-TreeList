#include "DataStorage.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

  srand(time(NULL));
  int randInt = rand() % 1000;
  srand(randInt);

  TreeList* Storage = new TreeList;

  Storage->addItem(10);
  Storage->addItem(7);
  Storage->addItem(15);
  Storage->addItem(12);
  Storage->addItem(16);
  Storage->addItem(4);
  Storage->addItem(2);
  Storage->addItem(1);
  Storage->addItem(3);
  Storage->addItem(20);
  Storage->addItem(11);
  Storage->addItem(6);

  Storage->displayItems();

  Storage->toggleSort();

  Storage->displayItems();

  Storage->sortList(true);

  Storage->displayItems();





  delete Storage;
return 0;
}

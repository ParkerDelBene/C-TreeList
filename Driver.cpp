#include "DataStorage.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(){

  srand(time(NULL));

  TreeList* Storage = new TreeList;

  for(int i = 0; i < 200000; i++){
    Storage->addItem(rand() % 1000000 + 1);
  }
  Storage->displayItems();

  Storage->toggleSort();

  Storage->displayItems();

  Storage->sortList(true);

  Storage->displayItems();





  delete Storage;
return 0;
}

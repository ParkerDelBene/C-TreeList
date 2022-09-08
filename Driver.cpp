#include "DataStorage.h"
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int main(){

  ifstream Infile;
  Infile.open("Random_Numbers.csv");
  int num;
  int count = 0;

  TreeList* Storage = new TreeList;

  Infile >> num;
  count++;
  while(!Infile.eof()){
    cout << count << endl;
    Storage->addItem(num);
    Infile >> num;
    count++;
  }

  Storage->displayItems();

  Storage->toggleSort();

  Storage->displayItems();

  Storage->sortList(true);

  Storage->displayItems();





  delete Storage;
return 0;
}

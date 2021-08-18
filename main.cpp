#include <iostream>
#include <ctime>
#include <fstream>
#include "Lists.h"


int main() {
  int numbers [count];
  //int numbers2[10] = {2, 3, 4, 2, 4, 5, 3, 6, 7, 3};
  srand(time(0));
  fillArray(numbers);
  printArray(numbers);
  printArraytoFile("output.txt", numbers);
  node * head = new node;
   for(int i = 0;i < count; i++){
    addNode(head, numbers[i]);
  }
  printList(head);
  printListToFile("output.txt", head);
  std::cout << "The list's size is: " << listSize(head) << '\n';
  std::ofstream myfile;
  myfile.open("output.txt", std::ios_base::app);
  if(myfile.is_open()){
    myfile << "The list's size is: " << listSize(head) << '\n';
    myfile.close();
  }
  node * repeats[count];
  int arraySize = fillRepeatArray(head, repeats);
  printRepeatArray(repeats, arraySize);
  printRepeatArrayToFile(repeats, arraySize, "output.txt");
}
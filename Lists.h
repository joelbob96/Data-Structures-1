#include <iostream>
#include <ctime>
#include <fstream>

#define count 30

struct node{
  int value;
  int number = 1;
  node * next = NULL;
};

void fillArray(int numbers[]){
    for(int i = 0;i < count; i++){
    numbers[i] = (rand() % 58 ) + 1;
  }
}

void printArray(int numbers[]){
  std::cout << "Array: \n";
  for(int i = 0;i < count; i++){
   std::cout << numbers[i] << " ";
  }
  std::cout << '\n';
}

void printArraytoFile(std::string fileName, int numbers[]){
  std::ofstream myfile(fileName);
  if(myfile.is_open()){
  myfile << "Array: \n";
    for(int i = 0;i < count; i++){
   myfile << numbers[i] << " ";
  }
  myfile << '\n';
  myfile.close();
  }
}

void addNode(node * currentNode, int val){
  while(currentNode->next && val >= currentNode->next->value){
    if(currentNode->value == val){
      break;
    }else currentNode = currentNode->next;
  }
   if(currentNode->value == val){
      currentNode->number++;
    }else if(!currentNode->next){
    currentNode->next = new node;
    currentNode = currentNode->next;
    currentNode->value = val;
    }else{
    node * temp = currentNode->next;
    currentNode->next = new node;
    currentNode = currentNode->next;
    currentNode->value = val;
    currentNode->next = temp;
  }
}

int listSize(node * currentNode){
  int i = 0;
  while(currentNode->next){
    currentNode = currentNode->next;
    i++;
  }
  return i;
}

int fillRepeatArray(node * currentNode, node * repeats[]){
  currentNode = currentNode->next;
  int i = 0;
  while(currentNode->next){
    if(currentNode->number > 1){
      repeats[i] = currentNode;
      i++;
    }
    currentNode = currentNode->next;
  }
  if(!currentNode->next && currentNode->number > 1)
    repeats[i] = currentNode;
  return i;
}

void printRepeatArray(node * repeats[], int arraySize){
  std::cout << "Repeats:" << '\n';
  if(arraySize == 0){
    std::cout << "No repeats" << '\n';
  }else{
  for(int i = 0; i < arraySize; i++){
    std::cout << repeats[i]->value << " Count:" << repeats[i]->number << "\n";
    }
  }
}

void printRepeatArrayToFile(node * repeats[], int arraySize, std::string fileName){
  std::ofstream myfile;
  myfile.open(fileName, std::ios_base::app);
  if(myfile.is_open()){
  myfile << "Repeats:" << '\n';
  if(arraySize == 0){
    myfile << "No repeats" << '\n';
  }else{
  for(int i = 0; i < arraySize; i++){
    myfile << repeats[i]->value << " Count:" << repeats[i]->number << "\n";
    }
  }
  myfile.close();
  }
}

void printList(node * currentNode){
  std::cout << "List: \n";
  if(currentNode->next){
    currentNode = currentNode->next;
  }else std::cout << "The list is empty \n";
  while(currentNode->next){
    std::cout << currentNode->value << ' ';
    currentNode = currentNode->next;
  }
  if(!currentNode->next){
    std::cout << currentNode->value << '\n';
  }
}

void printListToFile(std::string fileName, node * currentNode){
  std::ofstream myfile;
  myfile.open(fileName, std::ios_base::app);
  if(myfile.is_open()){
    myfile << "List: \n";
    if(currentNode->next){
    currentNode = currentNode->next;
    }else myfile << "The list is empty \n";
  while(currentNode->next){
    myfile << currentNode->value << ' ';
    currentNode = currentNode->next;
  }
  if(!currentNode->next){
    myfile << currentNode->value << '\n';
  }
  myfile.close();
  }
}


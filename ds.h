#include <iostream>
  using namespace std;
#include <math>

struct Node {
  int key = 0;
  Node* next = nullptr;
}

struct Head {
  Node* left_subtree = nullptr;
  Node* right_subtree = nullptr;
  int left_height = 0; 
}

/*
-invert the left and right node of the root node ,repeat the work untill you reach the bottom of the binary tree

time complexity :O(n)
space complexity O(h)
*/


#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
  // Write your code here.
	if(tree ==nullptr)
	   return ;
	
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
	swap(tree->left,tree->right);
}

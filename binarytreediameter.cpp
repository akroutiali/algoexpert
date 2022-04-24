/*
 *
 *
 *to calulate the diameter of binary tree we can use depth first search approach 
 *diamter of node =max((leftheight+right height),max(left diamter,right diamter))
 *
 * time complexity O(n)
 * space complexity O(h)
 *
 *
 *
 */


using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

class Treeinfo
{
	public:
	int diameter;
	int height;
	Treeinfo(int d,int h)
	{
		diameter=d;
		height=h;
	}
};

Treeinfo binaryTreeDiameterHelper(BinaryTree* tree,Treeinfo result)
{
	if(tree == nullptr)
		return result ;
	Treeinfo left=binaryTreeDiameterHelper(tree->left,result);
	Treeinfo right=binaryTreeDiameterHelper(tree->right,result);
	
	result.diameter=max(left.diameter+right.diameter,left.height+right.height);
	result.height=1+max(left.height,right.height);
	return result;
	
}
int binaryTreeDiameter(BinaryTree *tree) {
  // Write your code here.
  Treeinfo result (0,0);
  result= binaryTreeDiameterHelper(tree,result);
	return result.diameter;

}



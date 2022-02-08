
/*Algorithme 
-use recursive call to reconstruct left and right subtree , update the lowerbound and upper bound for evry call ,and check wether the condition is ok or not 



*/
using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

BST* reconstructHelper(vector<int> &preOrderTraversalValues,int lower,int upper,int &idx);

BST *reconstructBst(vector<int> preOrderTraversalValues) {
  // Write your code here.
	int idx=0;
  return reconstructHelper(preOrderTraversalValues, INT_MIN,INT_MAX,idx);
}


BST* reconstructHelper(vector<int>& preOrderTraversalValues,int lower,int upper,int &idx)
{
	
	//basic case 
	if (idx == preOrderTraversalValues.size())
		return nullptr;
int value=preOrderTraversalValues[idx];
  if(preOrderTraversalValues[idx] >=upper ||  preOrderTraversalValues[idx]<lower)
	{
		return nullptr;
	}
	idx=idx+1;
	auto leftsub=reconstructHelper(preOrderTraversalValues,lower,value,idx);
	auto rightsub=reconstructHelper(preOrderTraversalValues,value,upper,idx);
	
	cout<<"idx==="<<idx<<endl;
	cout<<"value==="<<preOrderTraversalValues[idx]<<endl;
	auto bst=new BST(value);
	bst->left=leftsub;
	bst->right=rightsub;
	return bst;
}

//time complexity O(n)
//space complexity O(h)

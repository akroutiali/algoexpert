using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

BST *reconstructBst(vector<int> preOrderTraversalValues) {
  // Write your code here.
	/*
	10  4  2  1  5  17 19  18
	
	root=4 
	right=17 
	

	
	*/
	if(preOrderTraversalValues.size() == 0 )
		return nullptr;
	
	int currentValue=preOrderTraversalValues[0];
	
	int rightSubIdx=preOrderTraversalValues.size();
	
	for(int i=1;i<preOrderTraversalValues.size();i++)
	{
		if(preOrderTraversalValues[i]>=currentValue)
		{
			rightSubIdx=i;
			break;
		}
	}
	
	auto leftSubtree=reconstructBst(vector<int>(preOrderTraversalValues.begin()+1,preOrderTraversalValues.begin()+rightSubIdx));
	auto rightSubtree=reconstructBst(vector<int>(preOrderTraversalValues.begin()+rightSubIdx,preOrderTraversalValues.end()));
	
	auto bst = new BST(currentValue);
	bst->left=leftSubtree;
	bst->right=rightSubtree;
	return bst;
	
	
	
	//time complexity O()
	//space complexity O(h)
}

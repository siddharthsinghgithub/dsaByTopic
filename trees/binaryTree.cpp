#include <bits/stdc++.h>

using namespace std;

class treeNode
{
public:
	treeNode() {}
	treeNode(int a)
	{
		data = a;
	}

	int data;
	treeNode *left = NULL;
	treeNode *right = NULL;
};

void preOrder(treeNode *bTree)
{
	if (!bTree)
	{
		return;
	}
	cout << bTree->data << "\n";
	preOrder(bTree->left);
	preOrder(bTree->right);
}

void preOrderWithoutRecursion(treeNode *bTree)
{
	treeNode *root = bTree;
	vector<treeNode *> A = {};

	while (1)
	{
		while (root != NULL)
		{
			cout << root->data << "\n";
			A.push_back(root);
			root = root->left;
		}
		if (A.empty())
			break;
		root = A.back();
		root = root->right;
		A.pop_back();
	}
}

int treeSize(treeNode *bTree)
{
	if (!bTree)
	{
		return 0;
	}

	return 1 + treeSize(bTree->left) + treeSize(bTree->right);
}

/**
 * level ordrer traversal
 * */
void levelOrderTraversal(treeNode *bTree)
{
	vector<treeNode *> A = {};
	cout << "level order traversal \n";
	A.push_back(bTree);

	while (!A.empty())
	{
		treeNode *temp = A.front();
		cout << temp->data << "\n";

		if (temp->left != NULL)
			A.push_back(temp->left);
		if (temp->right != NULL)
			A.push_back(temp->right);

		A.erase(A.begin());
	}
}

void preOrderWOR(treeNode *root)
{
	stack <treeNode *> S;

	while (1)
	{
		while (root)
		{	
			S.push(root);
			cout<<root->data<<"\n";
			root=root->left;
		}

		if (S.empty()){
			break;
		}

		root = S.top();
		// just process it here for the traversal
		// cout<<root->data<<"\n";
		root = root->right;
		S.pop();
	}
}

/***/
void postOrderWOR(treeNode * root){

	stack <treeNode *> S;
	treeNode * seen = NULL;
	do{

		while(root){
			S.push(root);
			root=root->left;
		}

		while(root == NULL){
			
			root = S.top();

			if(root->right == NULL || root->right==seen){
				cout<<root->data<<"\n";
				seen = root;
				S.pop();
			}
			else{ 
				root = root->right;
			}

		}

	}
	while (!S.empty());

}

/* max element */
int maxElement(treeNode *root){
	if(root == NULL){
		return INT_MIN;
	}

	return max(max(root->data , maxElement(root->left)),maxElement(root->right));
}

/** max element WOR */
int maxElementWOR(treeNode * root){
	queue <treeNode *> Q;
	int mx = 0;
	Q.push(root);
	while(!Q.empty()){
		mx = max(mx, Q.front()->data);
		Q.push(Q.front()->left);
		Q.push(Q.front()->right);

		Q.pop();
	}

	return mx;
}

// /* deepest element */
// int deepElement( treeNode * root){

// 	if(!root){
// 		cout<<INT_MIN<<"\n";
// 	}
	
// 	queue <treeNode *> Q;
// 	Q.push(root);
// 	treeNode * deepest = NULL;
// 	while(!Q.empty()){
// 		deepest = Q.front();
// 		if(Q.front()->left)
// 			Q.push(Q.front()->left);
// 		if(Q.front()->right)
// 			Q.push(Q.front()->right);
// 		Q.pop();
// 	}

// 	cout<<deepest->data;
	
// 	return 0;
// }

// int deleteELement(treeNode * root  , int delElement){
// 	if(!root){
// 		cout<<"Cannot delete the element";
// 	}
// 	treeNode * nodeToDelete = NULL,* deepestNode = NULL;
// 	queue <treeNode *> Q;
// 	Q.push(root);
// 	while(!Q.empty()){
// 		if(Q.front()->data == delElement){
// 			nodeToDelete = Q.front();
// 		}
		
// 		deepestNode = Q.front();
// 		if( deepestNode->left) Q.push(deepestNode->left);
// 		if( deepestNode->right) Q.push(deepestNode->right);

// 		Q.pop();
// 	}

// 	nodeToDelete->data = deepestNode->data;
// 	delete deepestNode;

// }

/* total leaf's */
int countLeaf(treeNode *root){
	if(root == NULL) return 0;
	queue <treeNode *> Q;
	Q.push(root);
	int leafCount = 0;
	while(!Q.empty()){
		
		// cout<<Q.front()->left->data<<"\n";
		if(Q.front()->left == NULL && Q.front()->right==NULL) leafCount++;
		if(Q.front()->left) Q.push(Q.front()->left);
		if(Q.front()->right) Q.push(Q.front()->right);
		Q.pop();
	}

	return leafCount;
}
int dia = 0;
/* diameter of a tree */
// int diameter(treeNode * root){
// 	if(root == NULL)
// 		return 0;
// 	dia = max ( 1 + diameter(root->left)+ diameter(root->right), dia );
// 	return 1+ max(diameter(root->left), diameter(root->right));
// }
int levelMax = 0;
int maxLevelSum(treeNode * root){
	if(root == NULL)
		return 0;

	levelMax = max( levelMax ,  maxLevelSum(root->left) + maxLevelSum(root->right) );
	return root->data;
}

// zigzag
int zigzagLevelOrder( treeNode* A) {
    stack <treeNode * > S1;
    stack <treeNode *> S2;
    S1.push(A);

    vector<vector<int>> result;
    bool leftToRight = true;

    while(!S1.empty() || !S2.empty()){
        vector<int> temp;
        
        if(leftToRight){
            
            while(!S1.empty()){
                treeNode * t1 = S1.top();
            
                if(t1->left)
                    // temp.push_back(t1->left->data);
					cout<<t1->left->data<<" ";
                    S1.push(t1->left);
                if(t1->right)
                    temp.push_back(t1->right->data);
                    S1.push(t1->right);
                
                S1.pop();
            }
            
            leftToRight = false;
        }
        else{
            
             while(!S2.empty()){
                treeNode * t1 = S2.top();
                
                if(t1->right)
                    temp.push_back(t1->right->data);
                    S2.push(t1->right);
                    
                if(t1->left)
                    temp.push_back(t1->left->data);
                    S2.push(t1->left);
                
                S2.pop();
            }
            
            leftToRight = true;
        }
        // for (auto i: temp)
        // {    cout << i << ' ';
        //     cout<<"\n"; }
        result.push_back(temp);
        
    }
    return 0;
}

int main()
{
	treeNode *bTree = new treeNode(1);
	bTree->left = new treeNode(2);
	bTree->right = new treeNode(3);
	bTree->left->left = new treeNode(4);
	bTree->left->right = new treeNode(5);
	bTree->right->left = new treeNode(6);
	bTree->right->right = new treeNode(7);
	bTree->right->right->right = new treeNode(8);


	// treeNode *bTree2 = new treeNode(10);
	// bTree2->left = new treeNode(20);
	// bTree2->right = new treeNode(30);
	// bTree2->left->left = new treeNode(40);
	// bTree2->left->right = new treeNode(50);
	// bTree2->right->left = new treeNode(60);
	// bTree2->right->right = new treeNode(70);

	// cout<<"size of this tree is"<<treeSize(bTree);
	// levelOrderTraversal(bTree);
	// cout<<maxElement(bTree);
	// deepElement(bTree);
	// deleteELement(bTree,3);
	// preOrderWithoutRecursion(bTree);
	// cout<<countLeaf(bTree);
	// diameter(bTree);
	// cout<<dia<<"\n";
	// maxLevelSum(bTree);
	// cout<<levelMax<<"\n";
	zigzagLevelOrder(bTree);
	return 0;
}
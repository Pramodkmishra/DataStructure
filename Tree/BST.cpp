#include<iostream>
#define PREORDER 1
#define INORDER 2
#define POSTORDER 3
#define LVLORDER 4



using namespace std;
class BST{
private:
    struct Node
    {
    Node *left;
    int data;
    Node *right;
    }*root;

public:
    BST();
    void buildTree(int num);
    void insertNode(Node **r,int num);
//    Node *getNode(int num);
	void travers(int num);
	void preorder(Node *r);
	void inorder(Node *r);
	void postorder(Node *r);
	void lvlorder(Node *r);

};
void BST::travers(int num)
{
	if(num==PREORDER)
		preorder(root);
	if(num==INORDER)
		inorder(root);
	if(num==POSTORDER)
		postorder(root);
	//if(num==LVLORDER)
//		lvlorder(root);
}

void BST::preorder(Node *r)
{
if(r!=NULL)
	{
		cout<<r->data<<",";
		preorder(r->left);
		preorder(r->right);
	}

}

void BST::inorder(Node *r)
{
if(r!=NULL)
	{
		inorder(r->left);
		cout<<r->data<<",";
		inorder(r->right);
	}

}

void BST::postorder(Node *r)
{
if(r!=NULL)
	{
		postorder(r->left);
		postorder(r->right);
		cout<<r->data<<",";

	}

}




 BST::BST()
{
root=NULL;
}

void BST::buildTree(int num)
{
insertNode(&root,num);
}
/*
struct Node BST::*getNode(int num)
{
Node *temp;
temp=(struct *Node)new Node;
temp->left=NULL;
temp->data=num;
temp->right=NULL;
return temp;
}
*/
void BST::insertNode(Node **r,int num)
{
if(*r==NULL)
    {
    *r=new Node;
    (*r)->left=NULL;
    (*r)->data=num;
    (*r)->right=NULL;
    return;
    }
else if(num<(*r)->data)
    insertNode(&((*r)->left),num);
else if(num>(*r)->data)
    insertNode(&((*r)->right),num);

return;
}

int main()
{
BST *obj=new BST();
obj->buildTree(4);
obj->buildTree(2);
obj->buildTree(1);
obj->buildTree(8);
obj->buildTree(5);
obj->buildTree(9);
obj->buildTree(7);
obj->buildTree(6);
obj->travers(2);




}




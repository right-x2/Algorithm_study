#include <iostream>

using namespace std;

int number = 15;

typedef struct node *treepointer;
typedef struct node {
	int data;
	treepointer leftChild, rightChild;
}node;

void preorder(treepointer ptr)
{
	if(ptr){
		cout << ptr->data<<' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
//avl trees 
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	int count;
	int balance_factor;
	struct node* left;
	struct node* right;
}* nodePtr;

class avltree
{
	private:
		nodePtr root,temp,parent,grandparent;
	public:
		
		avltree()
		{
			root = temp = parent = NULL;
		}

		void insert(int data);
		
		void left_rot_left(nodePtr n);
		void left_rot_right(nodePtr n);
		void right_rot_left(nodePtr n);
		void right_rot_right(nodePtr n);

		void print();
		void print(nodePtr n);
		nodePtr grand_node(nodePtr n);
		nodePtr parent_node(nodePtr n);
		void update_bf(nodePtr n);
		int ht(nodePtr n);
		void print2();

		int search(int data);
};

int avltree :: search(int data)
{
	temp = root;
	while(temp!=NULL)
	{
		if(temp->data > data)
		{
			temp = temp->left;
		}
		else if(temp->data < data)
		{
			temp = temp->right;
		}
		else if(temp->data == data)
		{
			return data;
		}
	}
	cout<<"404 not found";
	return -17299999;
}

void avltree :: print2()
{
	// cout<<root->data<<" "<<root->left->data<<" "<<root->right->data;
	if(root!=NULL)
	{
		cout<<"@"<<root->data<<"@";
	}

	if(root->left != NULL)
	{
		cout<<"#"<<root->left->data<<"#";
	}
	if(root->right != NULL)
	{
		cout<<"$"<<root->right->data<<"$";
		cout<<root->right->left->data<<root->right->right->data;
	}
	
}

int max(int a,int b)
{
	if(a<=b) return b;
	else return a;
}

int avltree :: ht(nodePtr n)
{
	if(n==NULL) return 0;
	else return 1+max(ht(n->left),ht(n->right));
}

void avltree :: update_bf(nodePtr n)
{
	grandparent = grand_node(n);
	parent = parent_node(n);
	int bf=ht(grandparent->left)-ht(grandparent->right);
	if(bf<0) bf = -bf;
	grandparent->balance_factor = bf;
	bf = ht(parent->left)-ht(parent->right);
	if(bf<0) bf = -bf;
	parent->balance_factor = bf;
}

void avltree :: insert(int data)
{
	nodePtr n = new node;
	n->data = data;
	n->count=1;
	n->balance_factor = 0;
	n->left = n->right = NULL;
	if(root == NULL)
	{
		root = n;
	}
	else
	{
		temp = root;
		while(temp!=NULL)
		{
			if(temp->data > data)
			{
				parent = temp;
				temp = temp->left;
			}
			else if(temp->data < data)
			{
				parent = temp;
				temp = temp->right;
			}
			else
			{
				temp->count +=1;
				return;
			}
		}
		if(parent->data > data)
		{
			parent->left = n;
			temp = parent->left;
		}
		else if(parent->data < data)
		{
			parent->right = n;
			temp = parent->right;
		}
	}
	update_bf(n);
	grandparent = grand_node(n);
	if(grandparent->balance_factor>1)
	{
		if(grandparent->left!=NULL)
		{
			if(grandparent->left->left != NULL)
			{
				left_rot_left(grandparent);
			}
			if(grandparent->left->right != NULL)
			{
				left_rot_right(grandparent);
			}
		}
		if(grandparent->right != NULL)
		{
			if(grandparent->right->left!=NULL)
			{
				right_rot_left(grandparent);
			}
			if(grandparent->right->right!=NULL)
			{
				// cout<<grandparent->data<<grandparent->right->data<<grandparent->right->right->data;
				
				right_rot_right(grandparent);
			}
		}
	}
}

void avltree :: left_rot_left(nodePtr n)
{
	nodePtr newnode = new node;
	newnode->data = n->data;
	newnode->count = n->count;
	newnode->balance_factor = n->balance_factor;
	newnode->left = newnode->right = NULL;

	n->data = n->left->data;
	n->count = n->left->count;
	n->balance_factor = n->left->balance_factor;
	
	n->left->data = n->left->left->data;
	n->left->count = n->left->left->count;
	n->left->balance_factor = n->left->left->balance_factor;

	n->left->right = n->left->left = NULL;
	n->right = newnode;
}
void avltree :: left_rot_right(nodePtr n)
{
	nodePtr newnode = new node;
	newnode->data = n->data;
	newnode->count = n->count;
	newnode->balance_factor = n->balance_factor;
	newnode->left = newnode->right = NULL;

	nodePtr newnode1 = new node;
	newnode1->data = n->left->data;
	newnode1->count = n->left->count;
	newnode1->balance_factor = n->left->balance_factor;

	nodePtr newnode2 = new node;
	newnode2->data = n->left->right->data;
	newnode2->count = n->left->right->count;
	newnode2->balance_factor = n->left->right->balance_factor;

	newnode2->left = newnode1;
	newnode2->right = newnode;

	newnode->left=newnode->right=NULL;
	newnode1->left=newnode1->right=NULL;

	n = newnode2;
}
void avltree :: right_rot_left(nodePtr n)
{
	nodePtr newnode = new node;
	newnode->data = n->data;
	newnode->count = n->count;
	newnode->balance_factor = n->balance_factor;
	newnode->left = newnode->right = NULL;

	nodePtr newnode1 = new node;
	newnode1->data = n->right->data;
	newnode1->count = n->right->count;
	newnode1->balance_factor = n->right->balance_factor;

	nodePtr newnode2 = new node;
	newnode2->data = n->right->left->data;
	newnode2->count = n->right->left->count;
	newnode2->balance_factor = n->right->left->balance_factor;

	newnode2->left = newnode;
	newnode2->right = newnode1;

	newnode->left=newnode->right=NULL;
	newnode1->left=newnode1->right=NULL;

	n = newnode2;
}
void avltree :: right_rot_right(nodePtr n)
{
	nodePtr newnode = new node;
	newnode->data = n->data;
	newnode->count = n->count;
	newnode->balance_factor = n->balance_factor;
	newnode->left = newnode->right = NULL;

	n->data = n->right->data;
	n->count = n->right->count;
	n->balance_factor = n->right->balance_factor;
	
	n->right->data = n->right->right->data;
	n->right->count = n->right->right->count;
	n->right->balance_factor = n->right->right->balance_factor;

	n->right->left = n->right->right = NULL;
	n->left = newnode;
}
nodePtr avltree :: grand_node(nodePtr n)
{
	return parent_node(parent_node(n));
}

nodePtr avltree :: parent_node(nodePtr n)
{
	temp = root;
	parent = root;
	while(temp!=NULL)
	{
		if(temp->data > n->data)
		{
			parent = temp;
			temp = temp->left;
		}
		else if(temp->data < n->data)
		{
			parent = temp;
			temp = temp->right;
		}
		else
		{
			return parent;
		}
	}
	return parent;
}

void avltree :: print(nodePtr n)
{
	if(n!=NULL)
	{
		print(n->left);
		cout << n->data;
		print(n->right);
	}
}

void avltree :: print()
{
	print(root);
	cout <<"\nht of tree : "<< ht(root)-1<<endl;
}

int main()
{
	avltree t;
	t.insert(4);
	t.insert(7);
	t.insert(6);
	t.insert(5);
	t.insert(3);
	t.insert(1);
	t.insert(2);
	cout<<"inorder print : ";
	t.print();

	cout<<t.search(2);
}
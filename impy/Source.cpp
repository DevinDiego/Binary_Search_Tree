#include <iostream>

class List
{
public:
	struct node
	{
		int data;
		node* left;
		node* right;
	};
	node* root;
	List() { root = nullptr; }
	node* createNode(const int& x);
	node* insert(node* temp, const int& x);
	void inOrder(node* temp);
	int search(node* temp, const int& x);
};
List::node* List::createNode(const int& x)
{
	node* temp = new node;
	temp->data = x;
	temp->left = temp->right = nullptr;
	return temp;
}
List::node* List::insert(node* temp, const int& x)
{
	if (temp == nullptr)
		return createNode(x);
	if (x < temp->data)
		temp->left = insert(temp->left, x);
	else if (x > temp->data)
		temp->right = insert(temp->right, x);
	return temp;
}
void List::inOrder(node* temp)
{
	if (temp != nullptr)
	{
		inOrder(temp->left);
		std::cout << temp->data << " ";
		inOrder(temp->right);
	}
}
int List::search(node* temp, const int& x)
{
	while (temp != nullptr)
	{
		if (temp->data == x)
			return temp->data;
		else if (x > temp->data)
			temp = temp->right;
		else if (x < temp->data)
			temp = temp->left;		
		else
			return temp->data;		
	}
	return 0;
}

int main()
{
	List::node* root = NULL;
	List list;

	root = list.insert(root, 50);
	list.insert(root, 30);
	list.insert(root, 20);
	list.insert(root, 44);
	list.insert(root, 60);
	list.inOrder(root);
	std::cout << "\n" << list.search(root, 50);
	
	
	std::cout << std::endl;
	system("pause");
	return 0;
}



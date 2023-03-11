#include<iostream>
#include <memory>
using namespace std;

class Node
{
public:
	char data;
	shared_ptr<Node> left;
	shared_ptr<Node> right;
	Node(char data) :data(data),left(nullptr),right(nullptr){}
};


class Tree
{
private:
	shared_ptr<Node> root;
	shared_ptr<Node> _findNode(shared_ptr<Node> curr, char data)
	{
		if(!curr)
		{
			return nullptr;
		}

		if(curr->data == data)
		{
			return curr;
		}
		else
		{
			shared_ptr<Node> searchNode = nullptr;
			if(searchNode == nullptr)
			{
				searchNode = _findNode(curr->left, data);
				if(searchNode == nullptr)
				{
					searchNode = _findNode(curr->right, data);
				}
			}
					
			return searchNode;
		}
	}

public:
	Tree(shared_ptr<Node> root) :root(root){}

	shared_ptr<Node> findNode(char data)
	{
		shared_ptr<Node> curr = this->root;
		if(!curr)
		{
			return nullptr;
		}
		return this->_findNode(curr, data);
	}

	void addLeft(shared_ptr<Node> curr, char data)
	{
		shared_ptr<Node> node = make_shared<Node>(data);
		curr->left = node;
	}

	void addRight(shared_ptr<Node> curr, char data)
	{
		shared_ptr<Node> node = make_shared<Node>(data);
		curr->right = node;
	}

	void preorder(shared_ptr<Node> curr)
	{
		if(!curr)
		{
			return;
		}

		cout << curr->data;
		preorder(curr->left);
		preorder(curr->right);
	}

	void inorder(shared_ptr<Node> curr)
	{
		if(!curr)
		{
			return;
		}

		inorder(curr->left);
		cout << curr->data;
		inorder(curr->right);
	}

	void postorder(shared_ptr<Node> curr)
	{
		if(!curr)
		{
			return;
		}

		postorder(curr->left);
		postorder(curr->right);
		cout << curr->data;
	}
};



void solution()
{
	int n;
	cin >> n;

	shared_ptr<Node> root = make_shared<Node>('A');
	Tree tree = Tree(root);

	for(int i = 0; i < n; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;

		shared_ptr<Node> node = tree.findNode(p);
		if(node)
		{
			if(l != '.')
			{
				tree.addLeft(node, l);
			}
			if(r != '.')
			{
				tree.addRight(node, r);
			}
		}
	}

	tree.preorder(root);
	cout << "\n";
	tree.inorder(root);
	cout << "\n";
	tree.postorder(root);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution();
}
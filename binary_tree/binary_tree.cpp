#include "binary_tree.hpp"

btree::btree()
{
	root = NULL;
}

btree::~btree()
{
	destroy_tree();
}

void btree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void	btree::insert(int key, node *leaf)
{
	if (key < leaf->key_value)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->left->key_value)
	{
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

node	*btree::search(int key, node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
			return (leaf);
		if (key < leaf->key_value)
			return (search(key, leaf->left));
		else
			return (search(key, leaf->right));
	}
	else
		return (NULL);
}

void	btree::insert(int key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node	*btree::search(int key)
{
	return (search(key, root));
}

void	btree::destroy_tree()
{
	destroy_tree(root);
}

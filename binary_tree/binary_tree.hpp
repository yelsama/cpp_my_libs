#ifndef	BINARY_TREE_HPP
# define BINARY_TREE_HPP

# include <iostream>

struct node
{
	int	key_value;
	node	*left;
	node	*right;
};


class btree
{
	public:
		btree();
		~btree();
		void	insert(int key);
		node	*search(int key);
		void	destroy_tree();
	private:
		node	*root;

		void	destroy_tree(node *leaf);
		void	insert(int key, node *leaf);
		node	*search(int ke, node *leaf);
};
#endif
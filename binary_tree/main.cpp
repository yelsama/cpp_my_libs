#include "binary_tree.hpp"
# include <iostream>

int	main(void)
{
	btree	my_tree;

	my_tree.insert(17);
	if (my_tree.search(17))
		std::cout << "we found the number in the tree\n";
	else
		std::cout << "this number is not part of the tree\n";
	return (0);
}

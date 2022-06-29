#include <iostream>
#include "BinaryTree.h"
#include "Bst.h"

int main()
{
	mytree::BinaryTree myTree;

	mytree::Node* pRoot = myTree.GetRoot();
	pRoot->mData = 1;

	auto pNode = myTree.InsertLeft(pRoot, 2);
	myTree.InsertLeft(pNode, 4);
	myTree.InsertRight(pNode, 5);

	pNode = myTree.InsertRight(pRoot, 3);
	myTree.InsertLeft(pNode, 6);
	myTree.InsertRight(pNode, 7);

	myTree.BreadthFirst();
	std::cout << std::endl;
	myTree.DepthFirst();
	std::cout << std::endl;
	myTree.DepthFirstRecursive(pRoot);
	std::cout << std::endl;
	myTree.InOrder(pRoot);
	std::cout << std::endl;
	myTree.PostOrder(pRoot);
	std::cout << std::endl;

	std::cout << myTree.Sum(pRoot) << std::endl;
	std::cout << myTree.Search(pRoot, 2) << std::endl;
	std::cout << myTree.Search(pRoot, 9) << std::endl;


	mytree::BinarySearchTree bst;

	mytree::SearchNode* root = bst.Insert(nullptr, 8);
	bst.Insert(root, 3);
	bst.Insert(root, 10);
	bst.Insert(root, 1);
	bst.Insert(root, 6);

	bst.PreOrder(root);
	std::cout << std::endl;
	bst.InOrder(root);
	std::cout << std::endl;
	bst.PostOrder(root);
	std::cout << std::endl;
}
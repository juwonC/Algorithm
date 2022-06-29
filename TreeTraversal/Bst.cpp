#include <iostream>
#include "Bst.h"

void mytree::BinarySearchTree::Visit(SearchNode* pNode)
{
	std::cout << pNode->mData << " ";
}

void mytree::BinarySearchTree::PreOrder(SearchNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	Visit(pNode);
	PreOrder(pNode->mpLeft);
	PreOrder(pNode->mpRight);
}

void mytree::BinarySearchTree::InOrder(SearchNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}

	InOrder(pNode->mpLeft);
	Visit(pNode);
	InOrder(pNode->mpRight);
}

void mytree::BinarySearchTree::PostOrder(SearchNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}
	
	PostOrder(pNode->mpLeft);
	PostOrder(pNode->mpRight);
	Visit(pNode);
}

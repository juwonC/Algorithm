#include <queue>
#include <stack>
#include "BinaryTree.h"

void mytree::BinaryTree::Visit(Node* node)
{
	std::cout << node->mData << " -> ";
}

void mytree::BinaryTree::BreadthFirst()
{
	std::queue<Node*> q;

	q.push(mpRoot);

	while (!q.empty())
	{
		auto pNode = q.front();
		Visit(pNode);
		q.pop();

		if (pNode->mpLeft != nullptr)
		{
			q.push(pNode->mpLeft);
		}

		if (pNode->mpRight != nullptr)
		{
			q.push(pNode->mpRight);
		}
	}
}

void mytree::BinaryTree::DepthFirst()
{
	std::stack<Node*> s;

	s.push(mpRoot);

	while (!s.empty())
	{
		auto pNode = s.top();
		Visit(pNode);
		s.pop();

		if (pNode->mpRight != nullptr)
		{
			s.push(pNode->mpRight);
		}

		if (pNode->mpLeft != nullptr)
		{
			s.push(pNode->mpLeft);
		}
	}
}

void mytree::BinaryTree::DepthFirstRecursive(Node* pNode)
{
	// base case
	if (pNode == nullptr)
	{
		return;
	}

	Visit(pNode);

	// recursive case
	DepthFirstRecursive(pNode->mpLeft);
	DepthFirstRecursive(pNode->mpRight);
}

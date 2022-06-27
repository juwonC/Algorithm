#include <queue>
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

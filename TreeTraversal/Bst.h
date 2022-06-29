#pragma once

namespace mytree
{
	struct SearchNode
	{
		int mData;
		SearchNode* mpLeft;
		SearchNode* mpRight;

		SearchNode(int data, SearchNode* pLeft, SearchNode* pRight)
		{
			mData = data;
			mpLeft = pLeft;
			mpRight = pRight;
		}
	};

	class BinarySearchTree
	{
	private:
		SearchNode* mpRoot{};

	public:
		BinarySearchTree()
		{
			mpRoot = CreateNode(0);
		}

		SearchNode* CreateNode(int data)
		{
			return new SearchNode(data, nullptr, nullptr);
		}

		SearchNode* GetRoot() const
		{
			return mpRoot;
		}

		SearchNode* Insert(SearchNode* pParent, int data)
		{
			// base case
			if (pParent == nullptr)
			{
				return CreateNode(data);
			}

			// recursive case
			if (data < pParent->mData)
			{
				pParent->mpLeft = Insert(pParent->mpLeft, data);
			}
			else if (data > pParent->mData)
			{
				pParent->mpRight = Insert(pParent->mpRight, data);
			}

			return pParent;
		}

	public:
		void Visit(SearchNode* pNode);
		void PreOrder(SearchNode* pNode);
		void InOrder(SearchNode* pNode);
		void PostOrder(SearchNode* pNode);
	};
}
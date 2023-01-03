#pragma once
#include"BaseNode.h"
#include"NodeValue.h"

namespace Algs { namespace Common {

	// --------------------------------
	class Node2 : public BaseNode<2>, public NodeValue
	{
	public:
		Node2() : BaseNode() {}
		Node2(std::wstring nodeId, std::wstring nodeLabel)
			: BaseNode(nodeId,nodeLabel) {}

		Node2* getLeft();
		Node2* createLeft (std::shared_ptr<IValue> value);
		
		Node2* getRight();		
		Node2* createRight(std::shared_ptr<IValue> value);
	};

}}
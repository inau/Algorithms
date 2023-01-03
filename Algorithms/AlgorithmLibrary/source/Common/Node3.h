#pragma once
#include"BaseNode.h"
#include"NodeValue.h"

namespace Algs { namespace Common {

	// --------------------------------
	class Node3 : public BaseNode<3>, public NodeValue
	{
	public:
		Node3* getLeft();
		Node3* createLeft(IValue* value);

		Node3* getRight();
		Node3* createRight(IValue* value);

		Node3* getMiddle();
		Node3* createMiddle(IValue* value);

		void	setValue(std::shared_ptr<IValue> valueCopy);
	};

}}
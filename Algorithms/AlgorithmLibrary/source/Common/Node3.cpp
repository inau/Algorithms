#pragma once
#include <stdexcept>
#include "Node3.h"

namespace Algs { namespace Common {

	Node3* Node3::getLeft()
	{
		return dynamic_cast<Node3*>(getNode(0));
	};

	Node3* Node3::createLeft(IValue* val)
	{
		return spawnNode<Node3, Node3>(0);
	};

	Node3* Node3::getMiddle()
	{
		return dynamic_cast<Node3*>(getNode(1));
	};

	Node3* Node3::createMiddle(IValue* node)
	{
		return spawnNode<Node3, Node3>(1);
	}
	void Node3::setValue(std::shared_ptr<IValue> valueCopy)
	{
		NodeValue::setValue(valueCopy);
		m_hasValue = valueCopy.get() != nullptr;
	};

	Node3* Node3::getRight()
	{
		return dynamic_cast<Node3*>(getNode(2));
	};

	Node3* Node3::createRight(IValue* node)
	{
		return spawnNode<Node3, Node3>(2);
	};

}
}
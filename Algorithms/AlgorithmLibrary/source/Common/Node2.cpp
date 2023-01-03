#pragma once
#include <stdexcept>
#include "Node2.h"

namespace Algs { namespace Common {

	Node2* Node2::getLeft()				
	{ 
		return dynamic_cast<Node2*>(getNode(0)); 
	};

	Node2* Node2::createLeft(std::shared_ptr<IValue> value)
	{ 
		auto node = spawnNode<Node2, Node2>(0, L"A", L"B"); // , std::forward(val)...);
		node->setValue(value);
		return node;
	};

	Node2* Node2::getRight()			
	{ 
		return dynamic_cast<Node2*>(getNode(1)); 
	};

	Node2* Node2::createRight(std::shared_ptr<IValue> value)
	{ 
		auto node = spawnNode<Node2, Node2>(1, L"A", L"B"); // , std::forward(val)...);
		node->setValue(value);
		return node;
	};

}
}
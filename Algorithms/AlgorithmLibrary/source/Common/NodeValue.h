#pragma once
#include <string>
#include <memory>

namespace Algs { namespace Common {

	class IValue
	{
	public:
		virtual ~IValue() {};
		virtual std::wstring to_string() = 0;
	};

	class NodeValue
	{
	protected:
		std::shared_ptr<IValue> m_value;

	public:
		IValue* getValue();
		virtual void setValue(std::shared_ptr<IValue> valueCopy);
	};

}}
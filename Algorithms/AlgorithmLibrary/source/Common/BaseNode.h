#pragma once
#include<memory>
#include<array>
#include<vector>
#include<string>
#include<sstream>

namespace Algs { namespace Common {

	template<unsigned int nSize>
	class BaseNode
	{
	protected:
		std::wstring m_nodeID;
		std::wstring m_nodeLabel;
		bool m_hasValue;
		std::array<std::shared_ptr<BaseNode<nSize>>, nSize> m_nodes;
		void AssignId(std::wstring id);
		void AssignLabel(std::wstring id);
	public:
		virtual ~BaseNode() {}
		BaseNode();
		BaseNode(std::wstring nodeId, std::wstring nodeLabel);
		std::wstring to_dot_notation();

	protected:
		std::wstring output_dot_notation(std::wstringstream& os);
		BaseNode<nSize>* getNode(unsigned int idx);

		template<class Base, class Derived, typename... Args>
		Base* spawnNode(unsigned int idx, Args... args);
	};


	template<unsigned int nSize>
	BaseNode<nSize>* BaseNode<nSize>::getNode(unsigned int idx)
	{
		if (idx < m_nodes.size())
		{
			return m_nodes[idx].get();
		}
		else
		{
			throw std::out_of_range("Node index is out of range");
		}
	};

	template<unsigned int nSize>
	template<class Base, class Derived, typename... Args>
	Base* BaseNode<nSize>::spawnNode(unsigned int idx, Args... args)
	{
		if (idx < m_nodes.size())
		{
			if (!m_nodes[idx])
			{
				m_nodes[idx] = std::make_shared<Derived>(std::forward<Args>(args)...);
			}
			return dynamic_cast<Base*>(m_nodes[idx].get());
		}
		else
		{
			throw std::out_of_range("Node index is out of range");
		}
	};

	template<unsigned int NodeSize>
	BaseNode<NodeSize>::BaseNode()
		: BaseNode<NodeSize>(L"",L"")
	{
	}

	template<unsigned int NodeSize>
	BaseNode<NodeSize>::BaseNode(std::wstring nodeId, std::wstring nodeLabel)
		: m_nodeID(nodeId)
		, m_nodeLabel(nodeLabel)
		, m_hasValue(false)
	{

	}

	template<unsigned int nSize>
	std::wstring BaseNode<nSize>::output_dot_notation(std::wstringstream& os)
	{
		// node id and label
		os << m_nodeID << L"[label=" << m_nodeLabel << L" style=" << (m_hasValue ? L"\"filled\"" : L"\"\"") << L"] " << std::endl;
		
		// process children
		std::vector<std::wstring> _children;
		for (unsigned i = 0u; i < m_nodes.size(); ++i)
		{
			if (m_nodes[i])
			{
				auto r = m_nodes[i]->output_dot_notation(os);
				_children.push_back(r);
			} 
			else // dummy null node
			{
		//		auto id = m_nodeID + L"x" + std::to_wstring(i);
		//		os << id << L"[color = red shape = none label = \"null\"]" << std::endl;
		//		_children.push_back(id);
			}

		}
		//os << std::endl;

		// link children
		os << m_nodeID << L" -> {";
		for (auto& nid : _children)
		{
			os << L" " << nid;
		}
		os << L" } " << std::endl;

		return m_nodeID;
	}

	template<unsigned int nSize>
	void BaseNode<nSize>::AssignId(std::wstring id)
	{
		m_nodeID = id;
	}
	template<unsigned int nSize>
	void BaseNode<nSize>::AssignLabel(std::wstring label)
	{
		m_nodeLabel = label;
	}

	template<unsigned int nSize>
	std::wstring BaseNode<nSize>::to_dot_notation()
	{
		std::wstringstream stream;
		stream << L"digraph { " << std::endl;
		output_dot_notation(stream);
		stream << L"}";

		return stream.str();
	}

}}
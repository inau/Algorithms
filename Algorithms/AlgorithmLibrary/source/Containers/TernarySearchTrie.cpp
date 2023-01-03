#pragma once
#include <stdexcept>
#include <queue>
#include "TernarySearchTrie.h"

namespace Algs { namespace Containers {

// protected:
TSTNode* TernarySearchTrie::find(TSTNode* node, std::wstring& str, unsigned idx) const
{
	if (node)
	{
		if (!str.empty() && idx < str.size())
		{
			wchar_t C = str[idx];
			wchar_t C´ = node->GetChar();

			if (C < C´) { return find(node->Less(C, false), str, idx); }
			if (C > C´) { return find(node->Greater(C, false), str, idx); }
			if (idx < (str.size()-1)) 
			{ 
				return find(node->Equal(C, false), str, idx+1); 
			}
			else { return node; }
		}
	}
	return node;
}

std::vector<const TstValue*> TernarySearchTrie::collect(std::wstring& str) const
{
	std::vector<const TstValue*> values;
	std::queue<TSTNode*> nodes;
	nodes.push(find(m_root.get(), str, 0));
	while (!nodes.empty())
	{
		auto node = nodes.front();
		nodes.pop();

		// null node
		if (!node) continue;

		auto value = dynamic_cast<TstValue*>(node->getValue());
		if (value && value->begins_with(str)) 
		{
			values.push_back(value); 
		}

		nodes.push(node->Less());
		nodes.push(node->Equal());
		nodes.push(node->Greater());
	}
	return values;
}

// public
bool TernarySearchTrie::contains(const wchar_t* key) const
{
	return false;
}

TernarySearchTrie::TernarySearchTrie()
{
	m_ids = [&]() {	return m_id++; };
}

std::vector<const TstValue*> TernarySearchTrie::search(const wchar_t* str) const
{
	std::wstring key(str);
	return collect(key);
}

void TernarySearchTrie::insertNode(std::unique_ptr<TSTNode>& node, std::wstring key, unsigned kidx)
{
	if (kidx < key.length())
	{
		wchar_t C = key[kidx];
		if (!node)
		{
			node = std::make_unique<TSTNode>(m_ids);
			node->SetChar(C);
		}
		
		wchar_t C´ = node->GetChar();
		
		if (C < C´) { insertNode(node->Less(C, true), key, kidx); }
		else if (C > C´) { insertNode(node->Greater(C, true), key, kidx); }
		else if (kidx < (key.length() - 1)) 
		{
			wchar_t C´´ = key[kidx+1];
			insertNode(node->Equal(C´´, true), key, kidx+1);
		}
	}
	else
	{
		throw std::exception("key index exceeds key");
	}
}
void TernarySearchTrie::insertNode(TSTNode* node, std::wstring key, unsigned kidx)
{
	if (kidx < key.length())
	{
		wchar_t C = key[kidx];
		//if (!node)
		//{
		//	node = std::make_unique<TSTNode>(m_ids);
		//	node->SetChar(C);
		//}

		wchar_t C´ = node->GetChar();

		if (C < C´) { insertNode(node->Less(C, true), key, kidx); }
		else if (C > C´) { insertNode(node->Greater(C, true), key, kidx); }
		else if (kidx < (key.length() - 1)) 
		{ 
			wchar_t C´´ = key[kidx + 1];
			insertNode(node->Equal(C´´, true), key, kidx + 1);
		}
		else
		{
			auto val = std::make_shared<TstValue>(key);
			node->setValue(val);
			m_items++;
		}
	}
	else
	{
		throw std::exception("key index exceeds key");
	}
}

void TernarySearchTrie::insert(const wchar_t* str)
{
	std::wstring key(str);
	insertNode(m_root, key, 0);
}

unsigned long TernarySearchTrie::size()
{
	return m_items;
}

std::wstring TernarySearchTrie::dot_str() const
{
	if (m_root)
	{
		return m_root->dot_str();
	}
	return std::wstring();
}

}}
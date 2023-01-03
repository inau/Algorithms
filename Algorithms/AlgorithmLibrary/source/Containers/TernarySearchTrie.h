#pragma once
#include "../Common/Node3.h"
#include "TernarySearchTrieTypes.h"
#include<memory>
#include<string>
#include<vector>

namespace Algs { namespace Containers {

	class TernarySearchTrie
	{
	protected:
		unsigned long m_items = 0;
		std::unique_ptr<TSTNode> m_root;
		int m_id = 1;
		IdGen m_ids;
	protected:
		TSTNode* find(TSTNode* node, std::wstring& str, unsigned idx) const;

		std::vector<const TstValue*> collect(std::wstring& str) const;

		void insertNode(std::unique_ptr<TSTNode>& node, std::wstring key, unsigned kidx);
		void insertNode(TSTNode* node, std::wstring key, unsigned kidx);

	public:
		TernarySearchTrie();
		bool contains(const wchar_t* key) const;
		std::vector<const TstValue*> search(const wchar_t* str) const;

		void insert(const wchar_t* key);

		unsigned long size();
		std::wstring dot_str() const;
	};

	

}}
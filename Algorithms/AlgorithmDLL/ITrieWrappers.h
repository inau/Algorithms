#pragma once
#include <string>
#include "ITrie.h"
#include "../AlgorithmLibrary/source/Containers/TernarySearchTrie.h"

class CTernaryTrie : public ITrie, public Algs::Containers::TernarySearchTrie
{
protected:
	std::wstring m_dot_string;

public:
	// Inherited via ITrie
	virtual void __cdecl Add(const wchar_t* str) override;

	virtual void __cdecl Remove(const wchar_t* str) override;

	virtual void __cdecl Search(const wchar_t* str, ITrieResult* resultContainer) override;

	virtual const unsigned int __cdecl getSize() override;

	virtual const wchar_t* __cdecl to_dot_str() override;

};

class CTernaryTrieResultItem : public ITrieResultItem
{
protected:
	std::wstring m_string;
public:
	CTernaryTrieResultItem(std::wstring str);
	// Inherited via ITrieResultItem
	virtual const wchar_t* __cdecl getText() const override;
};

class CTernaryTrieResult : public ITrieResult
{
protected:
	std::vector<CTernaryTrieResultItem> m_items;

public:
	// Inherited via ITrieResult
	virtual void __cdecl Clear() override;

	virtual void __cdecl Append(const ITrieResultItem* item) override;

	virtual const ITrieResultItem* __cdecl getResultElement(const unsigned int idx) override;

	virtual const unsigned int __cdecl getResultSize() override;

};


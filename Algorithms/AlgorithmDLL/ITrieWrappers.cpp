#include "ITrieWrappers.h"

void __cdecl CTernaryTrieResult::Clear()
{
    m_items.clear();
}

void __cdecl CTernaryTrieResult::Append(const ITrieResultItem* item)
{
    if (item)
    {
        m_items.push_back(CTernaryTrieResultItem(item->getText()));
    }
}

const ITrieResultItem* __cdecl CTernaryTrieResult::getResultElement(const unsigned int idx)
{
    if (idx < m_items.size())
    {
        return &m_items[idx];
    }
    return nullptr;
}

const unsigned int __cdecl CTernaryTrieResult::getResultSize()
{
    return m_items.size();
}

CTernaryTrieResultItem::CTernaryTrieResultItem(std::wstring str)
    : m_string(str)
{
}

const wchar_t* __cdecl CTernaryTrieResultItem::getText() const
{
    return m_string.c_str();
}

void __cdecl CTernaryTrie::Add(const wchar_t* str)
{
    insert(str);
}

void __cdecl CTernaryTrie::Remove(const wchar_t* str)
{
    // not implemented
}

void __cdecl CTernaryTrie::Search(const wchar_t* str, ITrieResult* resultContainer)
{
    if (resultContainer)
    {
        auto vec = search(str);
        resultContainer->Clear();
        for (auto e : vec)
        {
            CTernaryTrieResultItem item(e->key_str());
            resultContainer->Append(&item);
        }
    }
}

const unsigned int __cdecl CTernaryTrie::getSize()
{
    return size();
}

const wchar_t* __cdecl CTernaryTrie::to_dot_str()
{
    m_dot_string = dot_str();
    return m_dot_string.c_str();
}

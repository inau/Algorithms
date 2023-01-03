#include "ITrieExports.h"
#include "ITrieWrappers.h"


ITrie* TrieExports::CreateTrieObject()
{
    return new CTernaryTrie();
}

void TrieExports::DisposeTrie(ITrie* piTrie)
{
    if (piTrie)
    {
        delete piTrie;
        piTrie = nullptr;
    }
}

unsigned int TrieExports::Size(ITrie* piTrie)
{
    if (piTrie)
    {
        return piTrie->getSize();
    }
    return 0u;
}

void TrieExports::Add(ITrie* piTrie, const wchar_t* str)
{
    if (piTrie && str)
    {
        piTrie->Add(str);
    }
}

void TrieExports::Search(ITrie* piTrie, const wchar_t* str, ITrieResult* resultContainer)
{
    if (piTrie && str)
    {
        piTrie->Search(str, resultContainer);
    }
}

wchar_t* TrieExports::ToDotString(ITrie* piTrie)
{
    if (piTrie)
    {
        return (wchar_t*)(piTrie->to_dot_str());
    }
    return nullptr;
}

// ------------------------
ITrieResult* TrieExports::CreateResultObject()
{
    return new CTernaryTrieResult;
}

void TrieExports::DisposeResult(ITrieResult* piTrie)
{
    if (piTrie)
    {
        delete piTrie;
        piTrie = nullptr;
    }
}

const ITrieResultItem* TrieExports::getResultElement(ITrieResult* pi, const unsigned int idx)
{
    if (pi)
    {
        return pi->getResultElement(idx);
    }
    return nullptr;
}

const unsigned int TrieExports::getResultSize(ITrieResult* pi)
{
    if (pi)
    {
        return pi->getResultSize();
    }
    return 0u;
}

wchar_t* TrieExports::ItemGetText(ITrieResultItem* piTrie)
{
    if (piTrie)
    {
        return (wchar_t*)(piTrie->getText());
    }
    return nullptr;
}

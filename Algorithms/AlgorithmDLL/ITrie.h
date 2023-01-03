#pragma once

class ITrieResult;
class ITrieQueryCancellation;

class ITrie
{
public:
	virtual ~ITrie() {};
	
	virtual void __cdecl Add	(const wchar_t* str) = 0;
	virtual void __cdecl Remove (const wchar_t* str) = 0;
	virtual void __cdecl Search (const wchar_t* str, ITrieResult* resultContainer) = 0;
	virtual const unsigned int __cdecl getSize() = 0;
	virtual const wchar_t* __cdecl to_dot_str() = 0;	
};

class ITrieResultItem
{
public:
	virtual ~ITrieResultItem() {};

	virtual const wchar_t* __cdecl getText() const = 0;
};

class ITrieQueryCancellation
{
public:
	virtual ~ITrieQueryCancellation() {};

	virtual void Cancel() = 0;
	virtual const bool isCancelled() const = 0;
};

class ITrieResult
{
public:
	virtual ~ITrieResult() {};

	virtual void					__cdecl Clear() = 0;
	virtual void					__cdecl Append(const ITrieResultItem* item) = 0;
	virtual const ITrieResultItem*	__cdecl getResultElement(const unsigned int idx) = 0;
	virtual const unsigned int		__cdecl getResultSize() = 0;

};

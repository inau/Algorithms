#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../AlgorithmLibrary/source/Containers/TernarySearchTrie.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmTest
{
	TEST_CLASS(TSTTest)
	{
protected:


public:

	TEST_METHOD(TST_insert)
	{
		Algs::Containers::TernarySearchTrie trie;
		trie.insert(L"te");
		auto s0 = trie.dot_str();
		
		trie.insert(L"tes");

		auto s1 = trie.dot_str();

		trie.insert(L"tested");
		auto s2 = trie.dot_str();
		
		trie.insert(L"testicle");
		auto s3 = trie.dot_str();

	}

	TEST_METHOD(TST_find)
	{
		Algs::Containers::TernarySearchTrie trie;
		trie.insert(L"te");
		auto s0 = trie.dot_str();

		auto vec = trie.search(L"t");

		auto s1 = trie.dot_str();

		trie.insert(L"tested");
		auto s2 = trie.dot_str();

		trie.insert(L"testicle");
		auto s3 = trie.dot_str();
		auto vec2 = trie.search(L"tes");

	}

	};
}

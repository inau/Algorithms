#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../AlgorithmLibrary/source/Common/Node2.h"
#include "../AlgorithmLibrary/source/Common/Node3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmTest
{
	TEST_CLASS(NodeTest)
	{
protected:
	template<unsigned int Sz>
	class PubBaseNode : public Algs::Common::BaseNode<Sz>
	{
	public:
		PubBaseNode<Sz>* GetNode(unsigned int idx) { return dynamic_cast<PubBaseNode<Sz>*>(getNode(idx)); };
		PubBaseNode<Sz>* SpawnNode(unsigned int idx) { return spawnNode<PubBaseNode<Sz>, PubBaseNode<Sz>>(idx); };
	//	void	  SetNode(unsigned int idx, BaseNode* node) { setNode(idx, node); };
	};

	class TestValue : public Algs::Common::IValue
	{
	public:
	//	TestValue() : value(0) {};
		TestValue(int v) : value(v) {};
		int value = 0;

		// Inherited via IValue
		virtual std::wstring to_string() override
		{
			return std::to_wstring(value);
		}
	};

public:

	TEST_METHOD(NodeValue_ForwardValueArgs)
	{
		auto testNode = std::make_shared<Algs::Common::Node2>();
		{
			Algs::Common::Node2 *left, *right;
			{
				std::shared_ptr<TestValue> t1 = std::make_shared<TestValue>(42);
				std::shared_ptr<TestValue> t2 = std::make_shared<TestValue>(55);
				left = testNode->createLeft(t1);
				right = testNode->createRight(t2);
	
				Assert::AreEqual((void*)testNode->getLeft(), (void*)left, L"wrong pointer left");
				Assert::AreEqual((void*)testNode->getRight(), (void*)right, L"wrong pointer right");
			}
			Assert::AreNotEqual((void*)testNode.get(), (void*)left, L"parent and child should not match");
		}
	}

	TEST_METHOD(Node2_get)
	{
		auto testNode = std::make_shared<Algs::Common::Node2>();

		std::shared_ptr<TestValue> t1 = std::make_shared<TestValue>(42);
		auto left  = testNode->createLeft(t1);
		auto right = testNode->createRight(t1);

		Assert::AreEqual((void*)testNode->getLeft(), (void*)left, L"wrong pointer left");
		Assert::AreEqual((void*)testNode->getRight(), (void*)right, L"wrong pointer right");
		Assert::AreNotEqual((void*)testNode.get(), (void*)left, L"parent and child should not match");
	}

	TEST_METHOD(Node3_get)
	{
		auto testNode = std::make_shared<Algs::Common::Node3>();

		auto l = testNode->createLeft(nullptr);
		auto r = testNode->createRight(nullptr);
		auto m = testNode->createMiddle(nullptr);

		Assert::AreEqual((void*)testNode->getLeft(), (void*)l, L"wrong pointer left");
		Assert::AreEqual((void*)testNode->getRight(), (void*)r, L"wrong pointer right");
		Assert::AreEqual((void*)testNode->getMiddle(), (void*)m, L"wrong pointer mid");
		Assert::AreNotEqual((void*)testNode.get(), (void*)l, L"parent and child should not match");
	}

	TEST_METHOD(BaseNode_get_survives)
	{
		auto root = std::make_shared<PubBaseNode<1>>();
		{
			auto mid = root->GetNode(0);
			Assert::IsNull(mid);
			root->SpawnNode(0);
		}
		auto mid2 = root->GetNode(0);
		Assert::IsNotNull(mid2);
	}

	TEST_METHOD(BaseNode_get)
	{
		auto testNode = std::make_shared<PubBaseNode<5>>();
	
		Assert::IsNull(testNode->GetNode(0), L"node 0 was null");
		testNode->SpawnNode(0);
		Assert::IsNotNull(testNode->GetNode(0), L"node 0 was null");
		testNode->SpawnNode(1);
		Assert::IsNotNull(testNode->GetNode(1), L"node 1 was null");
		testNode->SpawnNode(2);
		Assert::IsNotNull(testNode->GetNode(2), L"node 2 was null");
		testNode->SpawnNode(3);
		Assert::IsNotNull(testNode->GetNode(3), L"node 3 was null");
		testNode->SpawnNode(4);
		Assert::IsNotNull(testNode->GetNode(4), L"node 4 was null");
	
		Assert::ExpectException<std::out_of_range>([&]() { testNode->SpawnNode(5); }, L"Exception was not thrown, when request to write out of bounds");
		Assert::ExpectException<std::out_of_range>([&]() { testNode->GetNode(5); }, L"Exception was not thrown, when requesting to read out of bounds");
			
	}
	};
}

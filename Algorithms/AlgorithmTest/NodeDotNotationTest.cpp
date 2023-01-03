#include "pch.h"
#include "CppUnitTest.h"
#include "../AlgorithmLibrary/source/Common/Node2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Algs::Common;

namespace AlgorithmTest
{
	TEST_CLASS(NodeTest)
	{
	protected:
		template<unsigned int NodeSize>
		class PubDotBaseNode : public BaseNode<NodeSize>
		{
		protected:

		public:
			PubDotBaseNode<NodeSize>(std::wstring id, std::wstring label)
			{
				m_nodeID = id;
				m_nodeLabel = label;
			}

			PubDotBaseNode<NodeSize>* GetNode(unsigned int idx) { return dynamic_cast<PubDotBaseNode<NodeSize>*>(getNode(idx)); };
			PubDotBaseNode<NodeSize>* SpawnNode(unsigned int idx, std::wstring id, std::wstring label)
			{ 
				PubDotBaseNode<NodeSize>* ptr
					= spawnNode<PubDotBaseNode<NodeSize>, PubDotBaseNode<NodeSize>, std::wstring, std::wstring>(idx, id, label);
				return ptr;
			};

			std::wstring ToString() { return to_dot_notation(); }
		};

	public:
		
		TEST_METHOD(GetDotNotation_Node2)
		{
			auto root = std::make_shared<PubDotBaseNode<2>>(L"R",L"root");
			root->SpawnNode(0, L"C1", L"left1");
			root->SpawnNode(1, L"C2", L"right1");
			auto child2 = dynamic_cast<PubDotBaseNode<2>*>(root->GetNode(1));
			child2->SpawnNode(1, L"C3", L"right2");


			std::wstring dotGraph = root->ToString();
			
			Logger::WriteMessage(dotGraph.c_str());
		}

	};
}

#pragma once
#include "../Common/Node3.h"
#include<memory>
#include<string>
#include<vector>
#include<functional>

namespace Algs { namespace Containers {

	class TstValue : public Common::IValue
	{
	protected:
		std::wstring m_key;

	public:
		TstValue(const std::wstring str);
		const wchar_t* key_str() const;
		bool begins_with(const std::wstring str);

		// Inherited via IValue
		virtual std::wstring to_string() override;
	};

	typedef std::function<int()> IdGen;

	class TSTNode : public Common::Node3
	{
	protected:
		IdGen m_gen;
		wchar_t m_char;
	
	protected:
		TSTNode* initNewNode(Node3* newNode, wchar_t c);
		void SetId(std::wstring str);
		void SetIdGen(IdGen str);

	public:
		TSTNode();
		TSTNode(IdGen& fn);
		const wchar_t GetChar();
		void SetChar(const wchar_t c);

		std::wstring dot_str();

		TSTNode* Less(wchar_t c = ' ', bool instantiate = false);
		TSTNode* Equal(wchar_t c = ' ', bool instantiate = false);
		TSTNode* Greater(wchar_t c = ' ', bool instantiate = false);
	};

}}
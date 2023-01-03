#include "TernarySearchTrieTypes.h"

namespace Algs { namespace Containers {

const wchar_t* TstValue::key_str() const
{
    return m_key.c_str();
}

bool TstValue::begins_with(const std::wstring str)
{
    return m_key.rfind(str, 0) == 0;    
}

std::wstring TstValue::to_string()
{
    return m_key;
}

TstValue::TstValue(const std::wstring str) : m_key(str) {}

// ------------------------------------------------

TSTNode::TSTNode()
    : m_char(' ')
{

}

TSTNode::TSTNode(IdGen& fn)
    : m_gen(fn)
{
    if (m_gen) { m_nodeID = std::to_wstring(m_gen()); }
    m_char = ' ';
}

const wchar_t TSTNode::GetChar()
{
    return m_char;
}

void TSTNode::SetChar(const wchar_t c)
{
    m_nodeLabel.resize(1, c);
    m_char = c;
}

TSTNode* TSTNode::initNewNode(Algs::Common::Node3* newNode, wchar_t c)
{
    auto node = dynamic_cast<TSTNode*>(newNode);
    if (m_gen && node) 
    { 
        node->SetIdGen(m_gen);
        node->SetChar(c);
        node->SetId(std::to_wstring(m_gen()));
    }
    return node;
}

void TSTNode::SetId(std::wstring str)
{
    AssignId(str);
}

void TSTNode::SetIdGen(IdGen str)
{
    m_gen = str;
}

std::wstring TSTNode::dot_str()
{
    return to_dot_notation();
}

TSTNode* TSTNode::Less(wchar_t c, bool instantiate)
{
    auto node = getLeft();
    if (!node && instantiate)
    {
        node = spawnNode<Node3, TSTNode>(0);
        initNewNode(node, c);
    }
    return dynamic_cast<TSTNode*>(node);
}

TSTNode* TSTNode::Equal(wchar_t c, bool instantiate)
{
    auto node = getMiddle();
    if (!node && instantiate)
    {
        node = spawnNode<Node3, TSTNode>(1);
        initNewNode(node, c);
    }
    return dynamic_cast<TSTNode*>(node);
}

TSTNode* TSTNode::Greater(wchar_t c, bool instantiate)
{
    auto node = getRight();
    if (!node && instantiate)
    {
        node = spawnNode<Node3, TSTNode>(2);
        initNewNode(node, c);
    }
    return dynamic_cast<TSTNode*>(node);
}

}}


#include "NodeValue.h"

namespace Algs { namespace Common {

    IValue* Algs::Common::NodeValue::getValue()
    {
        return m_value.get();
    }

    void Algs::Common::NodeValue::setValue(std::shared_ptr<IValue> copyValue)
    {
        m_value = copyValue;
    }

}}
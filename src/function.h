#ifndef FUNCTION_H
#define FUNCTION_H

#include "format.h"
#include "macro.h"
#include "type.h"

class Function
{
public:
    Function() = delete;
    Function(const Function &) = delete;
    Function &operator=(const Function &) = delete;
    ~Function() = default;

    Function(std::ostream &os) : m_os(os) {}
    std::ostream &stream() const { return m_os; }

    AddBiasFunctions;
    AddBiasSwpFunctions;

private:
    std::ostream &m_os;
};

#endif // FUNCTION_H

#include "RPN.hpp"

RPN::RPN(const std::string &expr) : _expr(expr)
{
    tokenize();
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _expr = other._expr;
        _tokens = other._tokens;
    }
    return *this;
}

RPN::~RPN() {}

std::string RPN::trim(const std::string &s) const
{
    std::string::size_type start = 0;
    while (start < s.size() && std::isspace(s[start]))
        ++start;
    std::string::size_type end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        --end;
    return s.substr(start, end - start);
}

bool RPN::_isOp(const std::string &tok) const
{
    return (tok == "+" || tok == "-" || tok == "*" || tok == "/");
}

bool RPN::_isNumber(const std::string &tok) const
{
    if (tok.empty())
        return false;
    for (size_t i = 0; i < tok.size(); ++i)
    {
        if (!std::isdigit(tok[i]))
            return false;
    }
    std::stringstream ss(tok);
    int value;
    ss >> value;
    if (ss.fail() || !ss.eof())
        return false;
    return (value >= 0 && value < 10);
}

void RPN::tokenize()
{
    _expr = trim(_expr);
    if (_expr.empty())
        throw std::runtime_error("Empty input!!");

    std::stringstream ss(_expr);
    std::string token;
    while (ss >> token) {
        if (!_isNumber(token) && !_isOp(token))
            throw std::runtime_error("Error");
        _tokens.push_back(token);
    }
    if (_tokens.empty())
        throw std::runtime_error("Error");
}

void RPN::doOp(char op, std::stack<double> &_stack)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    double right = _stack.top(); _stack.pop();
    double left = _stack.top(); _stack.pop();

    double res = 0;

    switch (op)
    {
        case '+':
            res = left + right;
            break;
        case '-':
            res = left - right;
            break;
        case '*':
            res = left * right;
            break;
        case '/':
            if (right == 0)
                throw std::runtime_error("Error");
            res = left / right;
            break;
        default:
            throw std::runtime_error("Error");
    }
    _stack.push(res);
}


double RPN::evaluate()
{
    std::stack<double> _stack;

    for (size_t i = 0; i < _tokens.size(); ++i)
    {
        const std::string &tok = _tokens[i];

        if (_isNumber(tok)) {
            std::stringstream ss(tok);
            int num;
            ss >> num;
            _stack.push(num);
        }
        else if (_isOp(tok))
            doOp(tok[0], _stack);
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}

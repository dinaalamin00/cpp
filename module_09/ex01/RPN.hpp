#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <stdexcept>

class RPN
{
    private:
        std::string             _expr;
        std::vector<std::string> _tokens;

        std::string trim(const std::string &s) const;
        bool        _isOp(const std::string &tok) const;
        bool        _isNumber(const std::string &tok) const;
        void        tokenize();
        void        doOp(char op, std::stack<double> &_stack);

    public:
        RPN(const std::string &expr);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        double   evaluate();
};

#endif

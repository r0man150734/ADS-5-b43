// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include <cctype>
#include <sstream>
#include "tstack.h"

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> opStack;
    std::string out;
    size_t i = 0;

    while (i < inf.length()) {
        if (isspace(inf[i])) {
            ++i;
            continue;
        }

        if (isdigit(inf[i])) {
            while (i < inf.length() && isdigit(inf[i])) {
                out += inf[i++];
            }
            out += ' ';
        } else if (inf[i] == '(') {
            opStack.push('(');
            ++i;
        } else if (inf[i] == ')') {
            while (!opStack.isEmpty() && opStack.top() != '(') {
                out += opStack.pop();
                out += ' ';
            }
            if (!opStack.isEmpty() && opStack.top() == '(') {
                opStack.pop();
            }
            ++i;
        } else {
            while (!opStack.isEmpty()
            && getPriority(opStack.top())
            >= getPriority(inf[i])) {
                out += opStack.pop();
                out += ' ';
            }
            opStack.push(inf[i]);
            ++i;
        }
    }

    while (!opStack.isEmpty()) {
        out += opStack.pop();
        out += ' ';
    }
    if (!out.empty() && out.back() == ' ') {
    out.pop_back();
    }

    return out;
}

int eval(const std::string& pstfx) {
    TStack<int, 100> stack;
    std::istringstream iss(pstfx);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else {
            int b = stack.pop();
            int a = stack.pop();
            switch (token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }

    return stack.pop();
}

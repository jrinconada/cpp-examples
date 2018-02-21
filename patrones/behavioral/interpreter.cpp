#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

// Evalúa espresiones como: 2+4, 6-3, 4+6-2, 1+1+1+1 ...
class Parser {
    struct Token {
        enum Type { number, plus, minus } type;
        string value;
        Token (Type t, const string &v) : type(t), value(v) {}
    };
    struct Operation {
        int* op1;
        Token::Type type;
        int* op2;
        Operation() {
            op1 = NULL;
            op2 = NULL;
        }
        int eval () {
            if (type == Token::plus) {
                return *op1 + *op2;
            } else {
                return *op1 - *op2;
            }
        }
    };
    std::vector<Token> tokens;
public:
    void lex (string& text) {
        tokens.clear();
        for (size_t i = 0; i < text.size(); i++) {
            switch (text[i]) {
                case '+':
                    tokens.push_back(Token {Token::plus, "+"});
                break;
                case '-':
                    tokens.push_back(Token {Token::minus, "-"});
                break;
                default:
                    string buffer;
                    buffer = text[i];
                    for (size_t j = i+1; j < text.size(); j++) {
                        if (isdigit(text[j])) {
                            buffer += text[j];
                            i++;
                        } else {
                            break;
                        }
                    }
                    tokens.push_back(Token {Token::number, buffer});
            }
        }
    }

    int parse (string& text) {
        lex (text);
        int result = 0;
        Operation op;
        for(Token& token : tokens) {
            if (token.type == Token::number) {
                if (op.op1 == NULL) {
                    op.op1 = new int(atoi(token.value.c_str()));
                } else if (op.op2 == NULL) {
                    op.op2 = new int(atoi(token.value.c_str()));
                }
            } else {
                op.type = token.type;
            }
            if (op.op1 != NULL && op.op2 != NULL) {
                result = op.eval();
                op.op1 = &result;
                op.op2 = NULL;
            }
        }
        return result;
    }

    void print () {
        for(Token& token : tokens) {
            std::cout << token.value << " ";
        }
    }
};

int main () {
    std::cout << "Introduce una expresión: ";
    string text;
    getline(cin, text);
    Parser parser;
    parser.lex(text);
    parser.print();
    std::cout << "= " << parser.parse(text) << '\n';
}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>



int main() {
  struct Soperator {
    uint8_t precedence = 0;
    uint8_t arguments = 0;
  };

  std::unordered_map<char, Soperator> operator_maps;
  operator_maps['/'] = {4, 2};
  operator_maps['*'] = {3, 2};
  operator_maps['+'] = {2, 2};
  operator_maps['-'] = {1, 2};

  std::string expression = "1+2*4-3";

  struct Token {
    std::string symbol = "";
    
    enum class Type : uint8_t {
      Unknown,
      Numeric_Literal,
      Operator
    } type = Type::Unknown;

    Soperator op;
  };

  std::deque<Token> holding_stack;
  std::deque<Token> output_stack;

  for ( const char c: expression){
    if(std::isdigit(c)) {
      // push digit to output stack
      output_stack.push_back({
        std::string(1, c),
        Token::Type::Numeric_Literal
      });
    }
    else if (operator_maps.find(c) != operator_maps.end()) {
      const Soperator new_op = operator_maps[c];
    }
  }
  

  system("pause");
  return 0;
}
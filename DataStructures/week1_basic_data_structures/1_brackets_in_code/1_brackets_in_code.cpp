#include <iostream>
#include <stack>
#include <string>
/*
In this problem you will implement a feature for a text editor to find errors in the 
usage of brackets in the code.
*/
struct Bracket {
    Bracket(char type, int position) :
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
                std::cout << position+1 << std::endl;
            }
            Bracket top = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            Bracket my_struct(top.type, top.position);
            if (!(my_struct.Matchc(next))) {
                std::cout << position + 1 << std::endl;
                // not balanced, therefore return
                return 0;
            }  
        }
    }

    if (!(opening_brackets_stack.empty())) {
        Bracket top = opening_brackets_stack.top();
        std::cout << top.position + 1 << std::endl;
    }
    else {
        std::cout << "Success" << std::endl;
    }

    return 0;
}

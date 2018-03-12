#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
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

    std::stack <Bracket * > opening_brackets_stack;
    int position;
   
    

    for (position = 0; position < text.length(); ++position) {
        char next = text[position];


        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
             struct Bracket *brac; 
               
             brac = new Bracket(next, position);

            opening_brackets_stack.push(brac);
           
        } 
             
        if (next == ')' || next == ']' || next == '}') {

            	Bracket *tmp_str; 

           if(!opening_brackets_stack.empty()){

                tmp_str = opening_brackets_stack.top();

                opening_brackets_stack.pop();

                if( tmp_str->Matchc(next) != true ){

                	std::cout << position  + 1 << std::endl; 
                	
                	exit(0);
           
                } 
            } else { // the stack is empty...spit out our 1 index position.  
                std::cout << position + 1 << std::endl; 
                exit(0);
            }
            
        } 
    }
   
   if(!opening_brackets_stack.empty()){

    Bracket *left_on_stack = opening_brackets_stack.top(); 
    std::cout << left_on_stack->position + 1 << std::endl; 
    exit(0);

   }
   
    // Printing answer, write your code here
    std::cout << "Success" << std::endl;

    return 0;
}

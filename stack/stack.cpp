#include <iostream>
#include <string>
#include <string.h>



typedef struct Node {

  const char *data;
  struct Node *next_ptr; 
  int node_id;
} node_t;



class Stack {

public: 
        void push(const char *data);
        Stack();
        void printStack();
        void Pop();
	long long getCount();
	std::string getTop();
	bool IsBalanced(std::string str);
	bool isEmpty(); 
	int findNeedle(std::string str, std::string str_data);
private:
	node_t *top;
        long long count;
 };


Stack::Stack(){

      top = NULL;
	count = 0;
}

int Stack::findNeedle(std::string str, std::string str_data){


	return str.find(str_data);

}
bool Stack::isEmpty(){

	if( count == 0){
		return true;

	}
	return false; 

}
bool Stack::IsBalanced(std::string str){

return false;

}

void Stack::push(const char *data){

	node_t *newTop = new node_t;

	if( top == NULL ){
	 newTop->data = data;
	 newTop->next_ptr = NULL;
	 top = newTop; 		

	} else {
		newTop->data = data;
		newTop->next_ptr = top;
	        top = newTop;

	}
        top->node_id = count;  
	count++;

}

std::string Stack::getTop() {

	return top->data; 


}
void Stack::Pop(){

	if( top == NULL ){
		return;
	} else {

		node_t *old = top;
		top = top->next_ptr;
		delete old; 
	
		count--;	

	}


}

long long Stack::getCount(){

	return count;
}
void Stack::printStack(){

	node_t *temp;
	temp = top;

	while(temp != NULL){
		std::cout << temp->data << std::endl;
		temp = temp->next_ptr;
	}

}
int main(int argc, char **argv){

	Stack *stack = new Stack();
        std::string str = "["; 

	std::string tmp_str;

	for(std::string::size_type i = 0; i < str.size(); i++){
		if( str[i] == '(' ) {
			stack->push("("); 

		} else if( str[i] == '['){
			stack->push("["); 
		} 


                 else if(!stack->isEmpty() ) {
			if( str[i] == ']' || str[i] == ')') {
		        tmp_str = stack->getTop();
			          stack->Pop();
			          stack->Pop();
			if( (tmp_str == "[" && str[i] != ']') ||
			    (tmp_str == "(" && str[i] != ')') )
		        {
				std::cout << i+1 << std::endl; 	
			} else {
				std::cout << "Success" << std::endl; 	
			    
			}
			}
		        	
		}
	} 



  
 return 0;
}

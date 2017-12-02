#include <iostream>
#include <cstddef>


int main(int argc, char **argv){

	int *p = NULL;
        int ival = 43; 
        
        std::cout << p << std::endl;
     
        p = &ival; 
        std::cout << *p << std::endl; 


}

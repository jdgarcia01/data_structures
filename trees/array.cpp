#include <iostream>
#include <array>

using namespace std;

#include <iomanip>

using std::setw;

int remove_index(int index, int n[], int size){


	for(int i = index; i < size - 1; i++){
		n[i] = n[i + 1];	
	}
	size = size - 1;

	for(int c = 0; c < size; c++) {
	std::cout << n[c] << std::endl;
	}
	return 0;
}




int main() {

	int n[] = {0,1,2,3,4,5,6,7,8,9,10}; 

    	int *ptr; 
	ptr = n;


	for( auto x : n ){
		std::cout << x <<std::endl;
	}


	for( int i = 0; i < 11; i++)
	{
		std::cout << n[ i ] << std::endl;
	}

	remove_index(4,n,11);
/*	cout << "Element" << setw( 13 ) << "value" << endl;

	for(int j = 0; j < 10; j++){
		cout << setw( 7 ) << j << setw( 13 ) << n[j] << endl;
		cout << setw( 7 ) << j << setw( 13 ) << (*ptr)+ j << endl;
        } */

		

	
}

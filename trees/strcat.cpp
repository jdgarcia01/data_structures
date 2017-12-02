#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char* str_cat( char str1[], char str2[]){

	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
        char newStr[str1_len + str2_len + 1]; 	
        char *ret_string;        
	int temp = 0;
	
	for(int i = 0; i < str1_len; i++){
            newStr[ temp ] = str1[ i ]; 
		temp++;
	}

	for(int j = 0; j < str2_len; j++)
	{
		newStr[ temp ] = str2[j];
		temp++;
	}

	newStr[temp] = '\n'; 
cout << newStr << endl;
	return ret_string; 

}


int main(){

	char s1[] = {"Hello "}; 
	char s2[] = {"World"}; 

	char *str; 

        str_cat(s1, s2);

	return 0;
}

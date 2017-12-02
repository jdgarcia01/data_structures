#include <iostream>


using namespace std; 

template<typename E> class Link {

public:
	E element;
	Link *next;
	Link(const E& elemval, Link* nextval = NULL)
	{
              element = elemval;
	      next    = nextval; 
	}
        Link( Link *nextval= NULL) 
	{
              next = nextval;
	}




};



template <typename E> class LList{

private:
	Link<E> *head; 
        Link<E> *tail;
	Link<E> *curr;
 	int cnt; 

	void init(){

	}
	
	void removeAll(){

	}
	
public:
	LList(int size=defaultSize ){
         this->init();	
	}
	~LList() {
          removeAll();
	}
	void print() const;
	coid clear() {
           this->removeAll();
	   this->init();
	}

	void insert(const E& it) {
 		curr->next = new Link<E>(it, curr->next);
		if( tail == curr){
			 tail = curr->next;
		         cnt++;
                }
         }
        void append(const E& it) {
         tail = tail->next = new Link<E>(it), NULL);
	}


                 
};



int main(){
 
    LList<int> *list = new LList<int>(5);

    return 0;

} 

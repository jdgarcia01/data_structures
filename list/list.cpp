#include <iostream>
#include <string>

typedef struct Node {

  int data;
  struct Node *next_ptr; 

} node_t;



class LinkedList {

public: 
	void addNode(int data);
        void addToFront(int data);
        LinkedList(int data);
        void getHead(); 
        void printList();
        void removeNode(int key);
        void removeHead();
        void removeTail(); 
private:
	void addNode(int data, node_t *root);
        void addToFront(int data, node_t *root);
        void removeNode(int key, node_t *root); 
        void removeHead(node_t *root);
        Node *root;
        Node *curr;


 };


LinkedList::LinkedList(int data){

      root = curr = new node_t;

      root->data = data;
      root->next_ptr = NULL;
      curr = root; 
}

void LinkedList::getHead(){

   std::cout << root->data << std::endl;

}
void LinkedList::addNode(int data){

        this->addNode(data, curr);

}

void LinkedList::addToFront(int data){

      this->addToFront(data, root);

}
void LinkedList::addToFront(int data, node_t *root){

 if(root == NULL){
 
   root = new node_t; 
   root->data = data;
   root->next_ptr = NULL;
   curr = root; 

 } else {

   node_t *temp           = new node_t; 
           temp->data     = data; 
           temp->next_ptr = root; 
           root = temp; 

 }

} 

void LinkedList::removeNode(int key){

 this->removeNode(key, root);

}

void LinkedList::removeNode(int key, node_t *root){

      if(root == NULL){
           return;
      } else {

         node_t *prev = new node_t;
                 prev = root; 
         node_t *moving = root->next_ptr;  
 
         if(prev->data == key){
           std::cout << "We found a match" << std::endl;
           this->removeHead();
            return;
         }

         while(moving !=  NULL){

              if(moving->data == key){
                 break;
              } else {
                 prev = moving;
                 moving = moving->next_ptr; 
              }

         } 
         if(moving == NULL) {
           std::cout << "Cant remove node/node not found" << std::endl;


         } else {
             prev->next_ptr = moving->next_ptr;
             delete moving; 

         }

      }

}

void LinkedList::removeHead(){


   node_t *tmp = root;
   delete root;
   root = tmp->next_ptr; 


}



void LinkedList::removeTail(){

  node_t *moving = new node_t;
          moving = root->next_ptr;

          while(moving != NULL ){
               if(moving->next_ptr == NULL){
           
               }

          }


}
void LinkedList::addNode(int data,  node_t *curr){

      
            if(curr == NULL){
              return;
            } else {
              
              node_t *newNode = new node_t;
              newNode->data = data;
              newNode->next_ptr = NULL; 
                 
               while(curr->next_ptr != NULL){
                  curr = curr->next_ptr;
               }

               curr->next_ptr = newNode; 

           }  

}

void LinkedList::printList(){

     curr = root;
     while(curr != NULL){
        std::cout << curr->data << std::endl;
        curr = curr->next_ptr; 

     }

}


int main(int argc, char **argv){

  LinkedList *list = new LinkedList(32);
 
  list->addNode(45);
  list->addNode(50);

  list->addNode(59);
  list->addNode(33);
  list->addToFront(55);

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  list->printList();

 list->removeNode(32);
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
 list->printList();
  
 return 0;
}

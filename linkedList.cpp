#include <cstdlib>

#include <iostream>

#include <time.h>

using namespace std;

// Making a node struct containing a data int and a pointer
// to another node
struct Node {
  int data;
  Node * next;
};

class LinkedList {
  // Head pointer
  Node * head;
  // TAIL pointer
  Node * tail;
  public:
  LinkedList();
  ~LinkedList();
  LinkedList(int size);
  LinkedList(const LinkedList & l1);
  void updateTail();
  void insertAtBeginning(int val);
  void insertAtEnd(int val);
  void operator = (const LinkedList & l);
  Node * getHead();
  Node * getTail();
  bool search(int val);
  void remove(int val);
  void removeDuplicate();
  void selectionSort();
  void reverse();
  void display();
};

  // default constructor. Initializing head pointer
  LinkedList::LinkedList() {
               head = NULL;
               tail = NULL;
  }
  
        
        //constructor that generates ransdom numbers in the list
LinkedList::LinkedList(int size) {
       // Seed srand with random numbers
             	  srand(time(0));
  			for (int i = 0; i < size; i++)
   	   // Add random numbers into our linked list
 			   insertAtBeginning(rand());
}
		// Copy constructor
 LinkedList::LinkedList(const LinkedList & l1) {
					head = l1.head;
  					tail = l1.tail;
}
		// Desctructor
	LinkedList::~LinkedList() {
  				Node * current = head;
 			 while (current != 0) {
   				 Node * next = current -> next;
   				 delete current;
    			current = next;
}
 				 head = NULL;
}
  void LinkedList::updateTail() {
        // if head is null set the tail to null also
            if (head == NULL) {
                tail = NULL;
                return;
 }
                Node * temp = head;

        //  Else traverse till the last node
           while (temp -> next != NULL) {
                temp = temp -> next;
}

       //  Assign the last node to tail
                 tail = temp;
                 return;
}
		//overload operator constructor
	void LinkedList::operator = (const LinkedList & l) {
 				 head = l.head;
 				 tail = l.tail;
}
		// Return the head of the linked list
	Node * LinkedList::getHead() {
  				return head;
}
		// Return tail of the linked list
	Node * LinkedList::getTail() {
 			 if (tail == NULL)
  				  return NULL;
 				 return tail;
}
		// inserting elements (At start of the list)
	void LinkedList::insertAtBeginning(int val) {
 		 // make a new node
 			 Node * new_node = new Node;
 				 new_node -> data = val;
 					 new_node -> next = NULL;

  		// If list is empty, make the new node, the head
  			if (head == NULL) head = new_node;

 		 // else, make the new_node the head and its next, the previous
 		 // head
  			else {
   					 new_node -> next = head;
    					head = new_node;
}
  							this -> updateTail();
}

		// inserting elements (At the end of the list)
	void LinkedList::insertAtEnd(int val) {
  		// make a new node
					  Node * new_node = new Node;
						  new_node -> data = val;
 							 new_node -> next = NULL;

 		 // If list is empty, make the new node, the head
 			 if (head == NULL) head = new_node;

 		 // else, make the new_node the head and its next, the previous
 		 // head
 			 else {
  						  tail -> next = new_node;
   							 tail = new_node;
}
  		//      this->printTail();
}
		// loop over the list. return true if element found
	bool LinkedList::search(int val) {
 							 Node * temp = head;
 			 while (temp != NULL) {
   			 if (temp -> data == val) return true;
   			 
   						 temp = temp -> next;
}
  				return false;
}

		//function to remave targeted elemnt in the element
	void LinkedList::remove(int val) {
 		 // If the head is to be deleted
 			 if (head -> data == val) {
   					 delete head;
  						 head = head -> next;
    						return;
}

  		// If there is only one element in the list
 			 if (head -> next == NULL) {
  	  // If the head is to be deleted. Assign null to the head
  			  if (head -> data == val) {
   				   delete head;
    				  head = NULL;
   					   return;
}
  		  // else print, value not found
   						 cout << "Value not found!" << endl;
   							 return;
  }

 		 // Else loop over the list and search for the node to delete
  							Node * temp = head;
				  while (temp -> next != NULL) {
 			   // When node is found, delete the node and modify the pointers
    			if (temp -> next -> data == val) {
   						   Node * temp_ptr = temp -> next -> next;
     						 delete temp -> next;
     							 temp -> next = temp_ptr;
     								 return;
}
  							  temp = temp -> next;
}
 		 // Else, the value was neve in the list
 						 cout << "Value not found" << endl;
}

	void LinkedList::display() {
 						 Node * temp = head;
 				 while (temp != NULL) {
   						 cout << temp -> data << " ";
   							 temp = temp -> next;
}
 			 cout << endl;
}

		/* Function to reverse the nodes in a linked list. */
	void LinkedList::reverse() {
				  if (head == NULL) return;

					  Node * prev = NULL, * current = NULL, * next = NULL;
						  current = head;
  				while (current != NULL) {
						   next = current -> next;
  							  current -> next = prev;
    							prev = current;
  								  current = next;
  }
 		 // now let the head point at the last node (prev)
 				 head = prev;
}
			// Function to remove duplicates if there is any
	void LinkedList::removeDuplicate() {
  		this -> selectionSort();
 			 // temp pointing to head
 			 Node * temp = head;
  				while (temp -> next != NULL && temp != NULL) {
   			 // Duplicate Found
   					 if (temp -> data == temp -> next -> data) {
   	   // DUplicate Removed
    					  temp -> next = temp -> next -> next;
    } else {
      // No Duplicate Present
      temp = temp -> next;
    }
  }
}
  //sort the list 
	void LinkedList::selectionSort() {
 		 Node * temp = head;

  	// Traverse the List
  			while (temp) {
  			  Node * min = temp;
   				 Node * r = temp -> next;

    // Traverse the unsorted sublist
    while (r) {
      if (min -> data > r -> data) min = r;
      r = r -> next;
    }

    // Swap Data
    int x = temp -> data;
    temp -> data = min -> data;
    min -> data = x;
    temp = temp -> next;
  }
}


int main() {
//  LinkedList l(4);
//  LinkedList l2 = l;
//  cout << "Displaying l2:";

//  l2.display();
   int option;
  cout<< "Hi, Welcome to our program: \n"<<endl;
  	  int opt = -2;
      LinkedList Lin;
  	 do{
  	    cout<< "Press \n 1. To view elements in the linked list \n 2. To insert items into your linked list \n 3.To remove items from your linked list \n 4: to reverse your linked list  \n 5. To remove consecutive duplicates \n 6. To Search for an element in the linked List\n 0. To exit"<<endl;
  	    cin>>opt;
  	    switch(opt){
  	    	case 2:
  	    		int n, insertOpt,el;
  	  	    	cout<<"How Many elements do want to insert into the linked list:"<<endl;
  	  	    	cin>>n;
  	  	    	cout<<"Where do you want to insert your elements:\n \t 1. At the beginning of list \n  \t 2. At the back of the linked list"<<endl;
  	  	    	cin>>insertOpt;
  	  	    	if(insertOpt ==1){
   	  	    	   for(int i = 0 ; i < n ; i++){
  	  	      	  	  cout<<"Enter the element"<<endl;
  	  	    	      cin>>el;
  	  	    	      Lin.insertAtBeginning(el);	   	
				   }
				  cout<<"Elements in your linked list are:"<<endl; Lin.display();     		
					}
                else if(insertOpt == 2){
                    for(int i = 0 ; i < n ; i++){
  	  	      	  	  cout<<"Enter the element"<<endl;
  	  	    	      cin>>el;
  	  	    	      Lin.insertAtEnd(el);	   	
				   }
				  cout<<"Elements in your linked list are:"<<endl; Lin.display();               	
				}
  	     	break;
  	     	case 3:
  	     	  int num;
  	     	  cout<<"Enter the element you want to remove:\n";
  	     	  cin>>num;
  	     	  Lin.remove(num);
  	     	break;
  	     	case 4:
  	     	   Lin.reverse();
  	     	break;
  	     	case 1:
  	     	   Lin.display();
  	     	break;
  	     	case 6:
  	     		cout<<"Enter the elements you are looking for?"<<endl;
  	     		int searchNum;
  	     		cin>>searchNum;
  	     		if(Lin.search(searchNum))
  	     			cout<<"The elements is in the linkd list:"<<searchNum<<endl;
			    else
			         cout<<"The elements was not found in the linked list \n";
  	     	  ;
  	     	break;
	    	}
   	}
   	 while (opt != 0);

  
}



#include "queue.h"

using namespace std;

queue_using_array::queue_using_array()
{
	front = rear = -1;
}

queue_using_array::~queue_using_array()
{	
	while(front != rear)
	{
		front = front + 1;
	}
}

bool queue_using_array::enqueue_input_file(string filename)
{
	ifstream in(filename);
	string text;

	while(!in.eof()) {
		// Get data from file
		getline(in, text);
		// Incase if the line is empty, skip it
		if (text == "") continue;
		// Convert string to integer and store it in unsorted linked list
		enqueue_command_line(stoi(text));
	}
	return true;
}

bool queue_using_array::enqueue_command_line(int element)
{
	//Condition to check if circular queue is empty
	//TO DO check overflow condition and increase the array size

	if (front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
		array_queue[rear] = element;
	
	}
	else
	{
		size = rear;
		if(size == capacity)                                  // Check for the overflow condition
		{
            capacity = 2 * capacity ;
			int* array_queue_new = new int[capacity];
			for (int i = 0; i < size; i++)
			{
				array_queue_new[i] = array_queue[i];
			}
			delete []array_queue;                                     //Delete old memory
			array_queue = array_queue_new;                           //Change the array name
			array_queue_new = NULL;                              //Delete the new array name
		}	

		rear = (rear + 1);              //rear is incremented to add the element
		array_queue[rear] = element;    //Add the element at the end of the queue

	}

	return true;
}

bool queue_using_array::dequeue(int& element)
{
	
	if(front == -1 && rear == -1)    //Check if queue is empty
		return false;

	else if (front == rear)         //Check if queue has only one element
	{
		element = array_queue[front]; //Assign the front element to be deleted to element
		front = -1;
		rear = -1;
		return true;
	}

	else
	{
		element = array_queue[front];  //Assign the front element to be deleted to element
		front = (front + 1)%capacity;  //Increment the front by 1 for circular queue

		return true;
	}

}
bool queue_using_array::display_queue_elements(int num_of_elements)
{
	int current = front;           //assigning front value to current variable
	if(front == -1 && rear ==-1)
	cout << "Queue is empty";      //Check if queue is empty

	else
	{
		cout << "Elements in the Queue are ";      //Display the elements
		while (current <= rear && current <= num_of_elements)
		{
			cout << array_queue[current] << endl;          
			current = (current + 1)%capacity;   //Increment the current value

		}
	}
	cout << endl;
	// TODO: Check if return value is needed here!
	return true;
}

queue_using_unsorted_linked_list::queue_using_unsorted_linked_list()
{
	front = rear = NULL;
}

queue_using_unsorted_linked_list::~queue_using_unsorted_linked_list()
{
    node* current = front;
    node* next = NULL;
 
    while (current != NULL) 
    {
        next = current->next;
        delete(current);
        current = next;
    }

    front = rear = NULL;
}

bool queue_using_unsorted_linked_list::enqueue_input_file(string filename)
{
	ifstream in(filename);
	string text;

	while(!in.eof()) {
		// Get data from file
		getline(in, text);
		// Incase if the line is empty, skip it
		if (text == "") continue;
		// Convert string to integer and store it in unsorted linked list
		enqueue_command_line(stoi(text));
	}
	return true;
}

bool queue_using_unsorted_linked_list::enqueue_command_line(int element)
{
	// Create a new node
	// TODO: Need to check if node can be created, if no space, then return false
	node* new_node = new node(element);

	// If queue is empty, then front and rear = new node
	if (rear == NULL) {
		front = rear = new_node;
		return true;
	}

	// Add the new node at the end of queue and change rear
	rear->next = new_node;
	rear = new_node;
	return true;
}

bool queue_using_unsorted_linked_list::dequeue(int& element)
{
	// Underflow check
	if (front == NULL)
		return false;

	// Store the front and move front one node ahead
	node* del_node = front;
	front = front->next;

	// Get the popped element to return and delete the node
	element = del_node->element;
	delete(del_node);

	// If front is NULL, then the queue is empty. Hence update the rear also as NULL
	if (front == NULL)
		rear = NULL;

	return true;
}

bool queue_using_unsorted_linked_list::display_queue_elements(int num_of_elements)
{
	int n = num_of_elements;
	node* temp = front;

	// Traverse the node n times and print the elements
	while (n-- && (temp != NULL)) {
		cout << temp->element << " ";
		temp = temp->next;
	}

	// Still elements are present
	if (temp != NULL) {
		cout << "...";
	}

	cout << endl;
	// TODO: Check if return value is needed here!
	return true;
}

queue_using_sorted_linked_list::queue_using_sorted_linked_list()
{
	front = rear = NULL;
}

queue_using_sorted_linked_list::~queue_using_sorted_linked_list()
{
    node* current = front;
    node* next = NULL;
 
    while (current != NULL) 
    {
        next = current->next;
        delete(current);
        current = next;
    }

    front = rear = NULL;
}

bool queue_using_sorted_linked_list::enqueue_input_file(string filename)
{
	ifstream in(filename);
	string text;

	while(!in.eof()) {
		// Get data from file
		getline(in, text);
		// Incase if the line is empty, skip it
		if (text == "") continue;
		// Convert string to integer and store it in unsorted linked list
		enqueue_command_line(stoi(text));
	}
	return true;
}

bool queue_using_sorted_linked_list::enqueue_command_line(int element)
{
	// Create a new node
	// TODO: Need to check if node can be created, if no space, then return false
	node* new_node = new node(element);

	// If linked list is empty or first element in queue is greater than given element, put new_node at front
	if (front == NULL || front->element > new_node->element) {
		new_node->next = front;
		front = new_node;
		return true;
	}
	if (front->element == new_node->element) {
		// Duplicate
		return false;
	}

	node* current = front;
	// Traverse the current node till its next nodes element is greater than given element.
	// So that we can place the new_node after current node.
	while (current->next != NULL && current->next->element < new_node->element)
		current = current->next;

	if (current->element == new_node->element) {
		// Duplicate
		return false;
	}

	// Placing new_node after current node.
	new_node->next = current->next;
	current->next = new_node;

	return true;
}

bool queue_using_sorted_linked_list::search(int element)
{
	return true;
}

bool queue_using_sorted_linked_list::dequeue(int& element)
{
	// Underflow check
	if (front == NULL)
		return false;

	// Store the front and move front one node ahead
	node* del_node = front;
	front = front->next;

	// Get the popped element to return and delete the node
	element = del_node->element;
	delete(del_node);

	// If front is NULL, then the queue is empty. Hence update the rear also as NULL
	if (front == NULL)
		rear = NULL;

	return true;
}

bool queue_using_sorted_linked_list::display_queue_elements(int num_of_elements)
{
	int n = num_of_elements;
	node* temp = front;

	// Traverse the node n times and print the elements
	while (n-- && (temp != NULL)) {
		cout << temp->element << " ";
		temp = temp->next;
	}

	// Still elements are present
	if (temp != NULL) {
		cout << "...";
	}

	cout << endl;
	// TODO: Check if return value is needed here!
	return true;
}

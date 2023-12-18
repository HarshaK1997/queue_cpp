#include "queue.h"

using namespace std;

bool queue_using_array::enqueue_input_file(string filename)
{
	return true;
}

bool queue_using_array::enqueue_command_line(int element)
{
	return true;
}

bool queue_using_array::dequeue(int& element)
{
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
        free(current);
        current = next;
    }

    front = rear = NULL;
	cout << "Unsorted List destructor called" << endl;
}

bool queue_using_unsorted_linked_list::enqueue_input_file(string filename)
{
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

	// Store previous front and move front one node ahead
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

bool queue_using_sorted_linked_list::enqueue_input_file(string filename)
{
	return true;
}

bool queue_using_sorted_linked_list::enqueue_command_line(int element)
{
	return true;
}

bool queue_using_sorted_linked_list::search(int element)
{
	return true;
}

bool queue_using_sorted_linked_list::dequeue(int& element)
{
	return true;
}

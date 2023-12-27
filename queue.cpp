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
	linked_list_queue::destroy_nodes(&front, &rear);
}

bool queue_using_unsorted_linked_list::enqueue_input_file(string filename)
{
	ifstream in(filename);

	if (!in.good()) {
        return false;
    }

	string text;
	int value;

	while(!in.eof()) {
		// Get data from file
		getline(in, text);
		// If the text can be converted to integer type, then store it in unsorted linked list
		if (is_number(text, value)) {
			queue_using_unsorted_linked_list::enqueue_command_line(value);
		}
	}
	return true;
}

bool queue_using_unsorted_linked_list::enqueue_command_line(int element)
{
	// Create a new node
	if (linked_list_queue::search(front, element)) {
		//duplicate
		return false;
	}
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
	return linked_list_queue::dequeue(&front, &rear, element);
}

void queue_using_unsorted_linked_list::display_queue_elements(int num_of_elements)
{
	linked_list_queue::print_linked_list_elements(front, num_of_elements);
	return;
}

queue_using_sorted_linked_list::queue_using_sorted_linked_list()
{
	front = rear = NULL;
}

queue_using_sorted_linked_list::~queue_using_sorted_linked_list()
{
	linked_list_queue::destroy_nodes(&front, &rear);
}

bool queue_using_sorted_linked_list::enqueue_input_file(string filename)
{
	ifstream in(filename);

	if (!in.good()) {
        return false;
    }

	string text;
	int value;

	while(!in.eof()) {
		// Get data from file
		getline(in, text);
		// If the text can be converted to integer type, then store it in unsorted linked list
		if (is_number(text, value)) {
			queue_using_sorted_linked_list::enqueue_command_line(value);
		}
	}
	return true;
}

bool queue_using_sorted_linked_list::enqueue_command_line(int element)
{
	// Create a new node
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
	node* current = front;
	while(current) {
		// If current node element is greater than the given element in sorted queue, then given element is not present.
		if (current->element > element) {
			return false;
		}
		if (current->element == element) {
			return true;
		}
		current = current->next;
	}
	return false;
}

bool queue_using_sorted_linked_list::dequeue(int& element)
{
	return linked_list_queue::dequeue(&front, &rear, element);
}

void queue_using_sorted_linked_list::display_queue_elements(int num_of_elements)
{
	linked_list_queue::print_linked_list_elements(front, num_of_elements);
	return;
}

void linked_list_queue::print_linked_list_elements(node* front, int num_of_elements)
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
	return;
}

bool linked_list_queue::search(node* front, int element)
{
	node* current = front;

	while(current) {
		if (current->element == element) {
			// duplicate element is present
			return true;
		}
		current = current->next;
	}
	return false;
}

bool linked_list_queue::dequeue(node** front, node** rear, int& element) {
	// Underflow check
	if ((*front) == NULL)
		return false;

	// Store the front and move front one node ahead
	node* del_node = (*front);
	(*front) = (*front)->next;

	// Get the popped element to return and delete the node
	element = del_node->element;
	delete(del_node);

	// If front is NULL, then the queue is empty. Hence update the rear also as NULL
	if ((*front) == NULL)
		(*rear) = NULL;

	return true;
}

void linked_list_queue::destroy_nodes(node** front, node** rear)
{
    node* current = (*front);
    node* next = NULL;
 
    while (current != NULL) 
    {
        next = current->next;
        delete(current);
        current = next;
    }

    (*front) = (*rear) = NULL;
}

bool is_number(string text, int& value)
{
    size_t pos;
    try {
        value = stoi(text, &pos);
        // Check if the entire string is converted to an integer
        if (pos == text.length()) {
            // Text is an integer
            return true;
        }
    }
    catch (...) {
        // The text is not integer
    }
    return false;
}

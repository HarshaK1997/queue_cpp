#include <iostream>
#include <fstream>

using namespace std;

struct node {
    // Data to be stored
    int element;

    // Pointer to store next link
    node* next;

    // Parameterised Constructor
    node(int element)
    {
        this->element = element;
        this->next = NULL;
    }
};

// Circular Queue implementation using Array
class queue_using_array
{
    private:
        // Front pointer
        int front;

        // Rear pointer
        int rear;

        // Number of elements in array_queue
        int size = 0;

        // Maximum elements an array_queue can store
        int capacity = 1000;

        // Array to store elements
        int* array_queue = new int[capacity];


    public:
        //Contructor
        queue_using_array();

        //Destructor
        ~queue_using_array();

        // Enqueues elements into the array Queue from the specified file and returns true if success.
        bool enqueue_input_file(string filename);

        // Enqueues element into the array Queue from the command line and returns true if success.
        bool enqueue_command_line(int element);

        // Dequeues the element from the Array Queue and returns true if success.
        bool dequeue(int& element);

        // Print given number of elements from the Queue and returns true if success.
        bool display_queue_elements(int num_of_elements);
};

// Queue implementation using Singly Linked list (Unsorted)
class queue_using_unsorted_linked_list
{
    private:
        // Front/Head pointer
        node* front;

        // Rear/Tail pointer
        node* rear;

    public:
        // Constructor
        queue_using_unsorted_linked_list();

        // Destructor
        ~queue_using_unsorted_linked_list();

        // Insert elements into the Queue from given file and returns true if success.
        bool enqueue_input_file(string filename);

        // Insert given element into the Queue from command line and returns true if success.
        bool enqueue_command_line(int element);

        // Delete given element from the Queue and returns true if success.
        bool dequeue(int& element);

        // Print given number of elements from the Queue and returns true if success.
        bool display_queue_elements(int num_of_elements);
};

// Queue implementation using Singly Linked list (Sorted: Ascending order)
class queue_using_sorted_linked_list
{
    private:
        // Front/Head pointer
        node* front;

        // Rear/Tail pointer
        node* rear;

    public:
        // Constructor
        queue_using_sorted_linked_list();

        // Destructor
        ~queue_using_sorted_linked_list();

        // Insert elements into the Queue from given file and returns true if success.
        bool enqueue_input_file(string filename);

        // Insert given element into the Queue from command line and returns true if success.
        bool enqueue_command_line(int element);

        // Traverses the Queue and returns true if given element is found.
        bool search(int element);

        // Delete given element from the Queue and returns true if success.
        bool dequeue(int& element);

        // Print given number of elements from the Queue and returns true if success.
        bool display_queue_elements(int num_of_elements);
};

#include "main.h"

bool get_input_from_user(int& input)
{
    cout << "\nQueue implementation using Array and Linked List:" << endl;
    cout << "===== ============== ===== ===== === ====== =====\n" << endl;
    cout << " 1. Enqueue elements from file(s) to Array" << endl;
    cout << " 2. Enqueue elements from file(s) to Linked List" << endl;
    cout << " 3. Enqueue elements from file(s) to Sorted List" << endl;
    cout << " 4. Enqueue element from command line to Array" << endl;
    cout << " 5. Enqueue element from command line to Linked List" << endl;
    cout << " 6. Enqueue element from command line to Sorted List" << endl;
    cout << " 7. Dequeue element from Array" << endl;
    cout << " 8. Dequeue element from Linked List" << endl;
    cout << " 9. Dequeue element from Sorted List" << endl;
    cout << "10. Search given element from Sorted List" << endl;
    cout << "11. Display Array elements" << endl;
    cout << "12. Display Linked List elements" << endl;
    cout << "13. Display Sorted List elements" << endl;
    cout << "14. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> input;

    if (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n*** Invalid input, try again ***" << endl;
        return false;
    }

    if (input < ENQUEUE_FILE_ARRAY || input > EXIT) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n*** Invalid option entered, try again ***" << endl;
        return false;
    }

    return true;
}

void command_prompt() {
    // Get the choice from user
    int input = -1;
    int element = -1;
    int num_of_elements = -1;
    queue_using_array q_arr;
    queue_using_unsorted_linked_list q_list;
    queue_using_sorted_linked_list q_sorted_list;

    while (true) {
        // Loop till the user enters valid input
        while(!get_input_from_user(input));

        switch (input) {
        case ENQUEUE_FILE_ARRAY:
            // TODO
            break;
        case ENQUEUE_FILE_LIST:
            // TODO
            break;
        case ENQUEUE_FILE_SORTED_LIST:
            // TODO
            break;
        case ENQUEUE_ELEMENT_ARRAY:
            // TODO
            break;
        case ENQUEUE_ELEMENT_LIST:
            cout << "Enter the element to Enqueue: ";
            // TODO Check if its integer, need to have common function
            cin >> element;
            if (q_list.enqueue_command_line(element))
                cout << "Element inserted successfully" << endl;
            else
                cout << "Operation failed" << endl;
            break;
        case ENQUEUE_ELEMENT_SORTED_LIST:
            // TODO
            break;
        case DEQUEUE_ELEMENT_ARRAY:
            // TODO
            break;
        case DEQUEUE_ELEMENT_LIST:
            // TODO
            if (q_list.dequeue(element))
                cout << "Element " << element << " is deleted successfully" << endl;
            else
                cout << "Operation failed" << endl;
            break;
        case DEQUEUE_ELEMENT_SORTED_LIST:
            // TODO
            break;
        case SEARCH_ELEMENT_SORTED_LIST:
            // TODO
            break;
        case DISPLAY_ARRAY:
            break;
        case DISPLAY_LIST:
            cout << "Enter number of elements to display: ";
            // TODO Check if its integer, need to have common function
            cin >> num_of_elements;
            q_list.display_queue_elements(num_of_elements);
            break;
        case DISPLAY_SORTED_LIST:
            break;
        case EXIT:
            // TODO: We need to implement destructor functions to free up memory space before exit
            return;
        default:
            cout << "Unknown error occurred" << endl;
            return;
        }
    }
}

int main()
{
    // Command Prompt GUI
    command_prompt();
    return 0;
}

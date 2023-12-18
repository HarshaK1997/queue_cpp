#include "main.h"

bool get_input_from_user(int& input)
{
    cout << "\nQueue implementation using Array and Linked List:" << endl;
    cout << "===== ============== ===== ===== === ====== =====\n" << endl;
    cout << " 1. Enqueue elements from file(s) to Array" << endl;
    cout << " 2. Enqueue elements from file(s) to Linked List" << endl;
    cout << " 3. Enqueue elements from file(s) to Sorted Linked List" << endl;
    cout << " 4. Enqueue element from command line to Array" << endl;
    cout << " 5. Enqueue element from command line to Linked List" << endl;
    cout << " 6. Enqueue element from command line to Sorted Linked List" << endl;
    cout << " 7. Dequeue element from Array" << endl;
    cout << " 8. Dequeue element from Linked List" << endl;
    cout << " 9. Dequeue element from Sorted Linked List" << endl;
    cout << "10. Search given element from Sorted Linked List" << endl;
    cout << "11. Exit" << endl;
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
            q_list.enqueue_input_file("");
            break;
        case ENQUEUE_FILE_SORTED_LIST:
            // TODO
            break;
        case ENQUEUE_ELEMENT_ARRAY:
            // TODO
            break;
        case ENQUEUE_ELEMENT_LIST:
            // TODO
            break;
        case ENQUEUE_ELEMENT_SORTED_LIST:
            // TODO
            break;
        case DEQUEUE_ELEMENT_ARRAY:
            // TODO
            break;
        case DEQUEUE_ELEMENT_LIST:
            // TODO
            break;
        case DEQUEUE_ELEMENT_SORTED_LIST:
            // TODO
            break;
        case SEARCH_ELEMENT_SORTED_LIST:
            // TODO
            break;
        case EXIT:
            // TODO: We need to call destructor and destroy and free up memory space and exit
            q_list.~queue_using_unsorted_linked_list();
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

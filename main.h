#include "queue.cpp"
#include <limits>
#include <stddef.h>

void command_prompt();
bool get_input_from_user(int &input);

enum input_type {
    ENQUEUE_FILE_ARRAY=1,
    ENQUEUE_FILE_LIST,
    ENQUEUE_FILE_SORTED_LIST,
    ENQUEUE_ELEMENT_ARRAY,
    ENQUEUE_ELEMENT_LIST,
    ENQUEUE_ELEMENT_SORTED_LIST,
    DEQUEUE_ELEMENT_ARRAY,
    DEQUEUE_ELEMENT_LIST,
    DEQUEUE_ELEMENT_SORTED_LIST,
    SEARCH_ELEMENT_SORTED_LIST,
    EXIT,
};


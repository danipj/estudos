/*
 * Pedro Tabacof - tabacof at gmail dot com
 * April 2016
 * Ordered Dicts
 */

/* Ordered dict as a binary tree */
typedef struct dict {
    int key;
    char value[10];
    struct dict *left, *right;
} Dict;

/* Insert key:value in dictionary. */
void insert_key_value(Dict **node, int key, char value[10]);

/* Remove key (and its corresponding value) from dictionary. */
void remove_key(Dict **node, int key);

/* Get the value associated with given key.
 * Copy the return value to return_value. */
void get_value(Dict *node, int key, char return_value[10]);

/* Print all values ordered by their keys.
 * There must be spaces between the values and a newline at the end.
 * To make things easier, you may print a space between the last value and the newline. */
void ordered_print(Dict *node);

/* Clear tree and free all memory. */
void clear(Dict *node);
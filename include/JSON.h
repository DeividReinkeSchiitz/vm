//
// Created by deivid on 12/8/22.
//

#pragma once

#include "d_structs.h"
#include <malloc.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define JSON_NAME_MALLOC 32
#define JSON_DATA_MALLOC 256

#define NUM_ARGS_STR(...) (sizeof((char *[]){__VA_ARGS__}) / sizeof(char *))

#define JSON_pushs(LIST, NAME, DATA)               \
    ({                                             \
        JSON_spush(LIST, NAME, DATA, JSON_STRING); \
    })

#define JSON_pushi(LIST, NAME, DATA)                       \
    ({                                                     \
        /*ide can see data as int*/                        \
        int __DATA2 = DATA;                                \
        char __CHAR_PUSHI[10];                             \
        sprintf(__CHAR_PUSHI, "%d", DATA);                 \
        JSON_spush(LIST, NAME, __CHAR_PUSHI, JSON_NUMBER); \
    })

#define JSON_pushb(LIST, NAME, DATA)                             \
    ({                                                           \
        if (DATA != "false" && DATA != "true")                   \
            printerr("JSON_pushb. Wrong Parameter: (%s)", DATA); \
                                                                 \
        JSON_spush(LIST, NAME, DATA, JSON_BOOLEAN);              \
    })

#define JSON_pushn(LIST, NAME)                     \
    ({                                             \
        JSON_spush(LIST, NAME, "null", JSON_NULL); \
    })

#define JSON_pushobj(LIST, NAME, NEW_LIST)   \
    ({                                       \
        JSON_push_lst(LIST, NAME, NEW_LIST); \
    })

#define JSON_pushars(LIST, DATA)                                \
    ({                                                          \
        if (LIST->type != JSON_ARRAY)                           \
            printerr("JSON_pushars. Type must be JSON_ARRAY."); \
                                                                \
        char __CHAR_PUSHARS[10];                                \
        sprintf(__CHAR_PUSHARS, "%d", LIST->size);              \
                                                                \
        JSON_pushs(LIST, __CHAR_PUSHARS, DATA);                 \
    })

#define JSON_pushari(LIST, DATA)                                \
    ({                                                          \
        if (LIST->type != JSON_ARRAY)                           \
            printerr("JSON_pushari. Type must be JSON_ARRAY."); \
                                                                \
        char __CHAR_PUSHARI[10];                                \
        sprintf(__CHAR_PUSHARI, "%d", LIST->size);              \
        JSON_pushi(LIST, __CHAR_PUSHARI, DATA);                 \
    })

#define JSON_pusharb(LIST, DATA)                                \
    ({                                                          \
        if (LIST->type != JSON_ARRAY)                           \
            printerr("JSON_pusharb. Type must be JSON_ARRAY."); \
                                                                \
        char __CHAR_PUSHARB[10];                                \
        sprintf(__CHAR_PUSHARB, "%d", LIST->size);              \
                                                                \
        JSON_pushb(LIST, __CHAR_PUSHARB, DATA);                 \
    })

#define JSON_pusharn(LIST)                                      \
    ({                                                          \
        if (LIST->type != JSON_ARRAY)                           \
            printerr("JSON_pusharn. Type must be JSON_ARRAY."); \
                                                                \
        char __CHAR_PUSHARN[10];                                \
        sprintf(__CHAR_PUSHARN, "%d", LIST->size);              \
                                                                \
        JSON_spush(LIST, __CHAR_PUSHARN, "null", JSON_NULL);    \
    })

#define JSON_pusharobj(LIST, DATA)                                \
    ({                                                            \
        if (LIST->type != JSON_ARRAY)                             \
            printerr("JSON_pusharobj. Type must be JSON_ARRAY."); \
                                                                  \
        if (DATA->type != JSON_OBJECT)                            \
            printerr("JSON_pusharobj. Type must be JSON_ARRAY."); \
                                                                  \
        char __CHAR_PUSHAROBJ[10];                                \
        sprintf(__CHAR_PUSHAROBJ, "%d", LIST->size);              \
                                                                  \
        JSON_pushobj(LIST, __CHAR_PUSHAROBJ, DATA);               \
    })

#define JSON_pusharar(LIST, DATA)                                \
    ({                                                           \
        if (LIST->type != JSON_ARRAY)                            \
            printerr("JSON_pusharar. Type must be JSON_ARRAY."); \
                                                                 \
        if (DATA->type != JSON_ARRAY)                            \
            printerr("JSON_pusharar. Type must be JSON_ARRAY."); \
                                                                 \
                                                                 \
        char __CHAR_PUSHARAR[10];                                \
        sprintf(__CHAR_PUSHARAR, "%d", LIST->size);              \
        JSON_pushobj(LIST, __CHAR_PUSHARAR, DATA);               \
    })

#define JSON_get(LIST, ...)                                     \
    ({                                                          \
        JSON_GET(LIST, NUM_ARGS_STR(__VA_ARGS__), __VA_ARGS__); \
    })


/**
 * JSON List structure
 */

typedef enum JSON_NODE_TYPE {
    JSON_NULL = 2,
    JSON_BOOLEAN = 3,
    JSON_NUMBER = 4,
    JSON_STRING = 5,
    JSON_ARRAY = 6,
    JSON_OBJECT = 7,
    JSON_DECODER = 8,
} JSON_NODE_TYPE;

typedef struct JSON_node {
    char *name;
    char *data_str;

    JSON_NODE_TYPE data_type;
    struct JSON_list *up;
    struct JSON_node *next;
} JSON_node;

typedef struct JSON_list {
    JSON_node *head;
    JSON_node *tail;

    JSON_NODE_TYPE type;

    size_t size;
} JSON_list;

/**
 * @brief Make a new JSON List
 * @param type JSON_OBJECT or JSON_ARRAY or JSON_DECODER
 * @return The new list
*/
JSON_list *JSON_mk(JSON_NODE_TYPE type);  // JSON List Make

/**
 * @brief Check if the JSON List is empty.
 * @param list The list to check.
 * @return 1 if the list is empty, 0 otherwise.
 */
void JSON_parse(JSON_list *list, char *rjson);

/**
 * @brief Add a new node to the JSON List
 * @param list_obj The list_obj to add the node
 * @param name The name of the node
 * @param value The value of the node
 * @param type The type of the node
 * @return The new node
 */
JSON_node *JSON_spush(JSON_list *list_obj, char *name, char *value, JSON_NODE_TYPE type);  // JSON Static Push

/**
 * @brief Check if the JSON List is empty
 * @param list The list to check
 * @return 1 if the list is empty, 0 otherwise
 */
int JSON_mpty(JSON_list *list);  // JSON List Empty

/**
 * @brief Get the value from a element name.
 * If the element is not found, it will return NULL.
 * @param list The list to search
 * @param n_args The number of arguments
 * @param name The name of the element
 * @return The value of the element
 * @note The function receives a variable number of arguments,
 * that represent internal elements of the JSON. The last argument MUST be NULL.
 */
char *JSON_GET(JSON_list *list, int n_args, char *name, ...);

/**
 * @brief Concatenate the list2 into list in the last position.
 * @param name the name of the list2 in the list.
 * @return void.
*/
void JSON_push_lst(JSON_list *list, char *name, JSON_list *list2);  // JSON Push List

/**
 * @brief Find the node with the given name.
 * @param list The list to search.
 * @param name The name of the node.
 * @return The Node founded.
 */
JSON_node *JSON_findNode(JSON_list *list, char *name);

/**
 * @brief Transform a JSON List to a string.
 * @param list The list to transform.
 * @return The string.
 */
char *JSON_2str(JSON_list *list);

/**
 * @brief Free the JSON List
 * @param list The list to free
 */
void JSON_free(JSON_list *list);

/**
 * @brief This function is used to get the value of a element.
 * @param raw_json The raw json string to handle.
 * @param i The index of the string to handle.
 * @param tmp_data The temporary data string.
 * @param data_type The type of the data.
 * @param data The data string.
 */
static void JSON_handle_el_data(const char *raw_json, int *i, char *tmp_data,
                                JSON_NODE_TYPE *data_type, SLList *data);

/**
 * @brief Make a new JSON Node
 * @return The new Node
*/
static JSON_node *JSON_mk_node();

/**
 * @brief Iterate over the JSON List removing irrelevant characters.
 * @param raw_json The raw json string to handle.
 * @return The new raw json string.
*/
static char *JSON_jmpic(char *raw_json);  // Jump irrelevant characters

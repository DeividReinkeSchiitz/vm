//
// Created by deivid on 12/8/22.
//

#include "JSON.h"

JSON_list *JSON_mk(JSON_NODE_TYPE type)
{
    if (type != JSON_OBJECT && type != JSON_ARRAY && type != JSON_DECODER)
        log_msg(LOG_ERROR, "Wrong Parameter (%d)", type);

    JSON_list *new_lst = (JSON_list *) malloc(sizeof(JSON_list) + 1);
    if (new_lst == NULL)
        log_msg(LOG_ERROR, "JSON Singly Linked List Overflow.");

    new_lst->head = NULL;
    new_lst->tail = NULL;
    new_lst->size = 0;
    new_lst->type = type;

    return new_lst;
}

void JSON_parse(JSON_list *list, char *raw_json)
{
    // TODO: Remove insignificant characters
    char *rjson              = JSON_jmpic(raw_json);

    int i                    = 0;
    int arr_len              = 0;

    JSON_NODE_TYPE data_type = 0;

    SLList *name             = sllist_mk();
    SLList *data             = sllist_mk();

    char tmp_name[JSON_NAME_MALLOC];
    char tmp_data[JSON_DATA_MALLOC];

    for (; i < strlen(rjson) - 1; i++)
    {
        // check if is an object
        if (rjson[0] == '{')
        {
            // ignore {
            i++;

            // ignore "
            if (rjson[i] == '\"')
                i++;

            // ignore ,
            if (rjson[i] == ',')
                i++;

            /**************** Get the name of the element *****************/
            sllist_clear(name);
            memset(tmp_name, 0, JSON_NAME_MALLOC);

            while (rjson[i] != ':')
            {
                // ignore "
                if (rjson[i] == '\"')
                {
                    i++;
                    continue;
                }

                if (strlen(tmp_name) == JSON_NAME_MALLOC - 1)
                {
                    sllist_push(name, tmp_name, JSON_NAME_MALLOC);
                    memset(tmp_name, 0, JSON_NAME_MALLOC);
                }

                tmp_name[strlen(tmp_name)] = rjson[i];
                i++;
            }

            if (strlen(tmp_name) != 0)
                sllist_push(name, tmp_name, strlen(tmp_name));
            /**************************************************************/

            // ignore :
            if (rjson[i] == ':')
                i++;

            /**************** Get the data of the element *****************/
            sllist_clear(data);
            memset(tmp_data, 0, JSON_DATA_MALLOC);

            JSON_handle_el_data(rjson, &i, tmp_data, &data_type, data);
            /**************************************************************/

            char *name_str = sllist_2str(name);
            char *data_str = sllist_2str(data);

            JSON_spush(list, name_str, data_str, data_type);

            free(data_str);
            free(name_str);
        }
        // check if is an array
        else if (rjson[0] == '[')
        {
            // ignore [
            i++;

            // Set the array length as the name.
            /**************** Get the name of the element *****************/
            sllist_clear(name);
            memset(tmp_name, 0, JSON_NAME_MALLOC);

            sprintf(tmp_name, "%d", arr_len);
            sllist_push(name, tmp_name, 0);
            /**************************************************************/

            /**************** Get the data of the element *****************/
            sllist_clear(data);
            memset(tmp_data, 0, JSON_DATA_MALLOC);

            JSON_handle_el_data(rjson, &i, tmp_data, &data_type, data);
            /**************************************************************/

            char *name_str = sllist_2str(name);
            char *data_str = sllist_2str(data);

            JSON_spush(list, name_str, data_str, data_type);

            free(data_str);
            free(name_str);

            arr_len++;
        }
    }


    sllist_free(name);
    sllist_free(data);
    free(rjson);
}

JSON_node *JSON_spush(JSON_list *list_obj, char *name, char *value, JSON_NODE_TYPE type)
{
    SLList *tmp              = sllist_mk();

    JSON_node *new_json_node = JSON_mk_node();
    new_json_node->up        = NULL;
    new_json_node->data_type = type;

    new_json_node->name      = strdup(name);
    if (new_json_node->name == NULL)
        log_msg(LOG_ERROR, "JSON Node Name Overflow.");

    if (type == JSON_STRING)
    {
        // add "" to data_str the string
        sllist_push(tmp, "\"", 1);
        if (value != NULL)
            sllist_push(tmp, value, 0);
        sllist_push(tmp, "\"", 1);

        new_json_node->data_str = sllist_2str(tmp);
    }
    else
    {
        new_json_node->data_str = (value == NULL ? "" : strdup(value));
        if (new_json_node->data_str == NULL)
            log_msg(LOG_ERROR, "JSON Node Data Overflow.");
    }

    if (type == JSON_OBJECT || type == JSON_ARRAY)
    {
        new_json_node->up = JSON_mk(type);

        if (value != NULL)
            JSON_parse(new_json_node->up, value);
    }

    new_json_node->next = NULL;
    if (list_obj->head == NULL)
    {
        list_obj->head = new_json_node;
        list_obj->tail = new_json_node;
    }
    else
    {
        list_obj->tail->next = new_json_node;
        list_obj->tail       = new_json_node;
    }

    sllist_free(tmp);

    list_obj->size++;
    return new_json_node;
}

int JSON_mpty(JSON_list *list)
{
    return list->size == 0;
}

char *JSON_GET(JSON_list *list, int n_args, char *name, ...)
{
    if (name == NULL || list == NULL)
        return NULL;

    JSON_node *head = JSON_findNode(list, name);

    if (n_args == 1)
    {
        if (head->data_type == JSON_STRING)
        {
            return strndup(head->data_str + 1, strlen(head->data_str) - 2);
        }
        else
            return strdup(head->data_str);
    }
    n_args--;

    va_list args;
    va_start(args, name);
    while (n_args != 0)
    {
        name = va_arg(args, char *);
        head = JSON_findNode(head->up, name);
        n_args--;
    }
    va_end(args);

    if (head->data_type == JSON_STRING)
        return strndup(head->data_str + 1, strlen(head->data_str) - 2);

    return strdup(head->data_str);
}

void JSON_push_lst(JSON_list *list, char *name, JSON_list *list2)
{
    JSON_node *new_tail = JSON_mk_node();
    new_tail->data_str  = JSON_2str(list2);
    new_tail->data_type = list2->type;
    new_tail->up        = list2;

    new_tail->name      = strdup(name);
    if (new_tail->name == NULL)
        log_msg(LOG_ERROR, "JSON Node Name Overflow.");

    if (list->head == NULL)
    {
        list->head = new_tail;
        list->tail = new_tail;
    }
    else
    {
        list->tail->next = new_tail;
        list->tail       = new_tail;
    }

    list->size++;
}

JSON_node *JSON_findNode(JSON_list *list, char *name)
{
    JSON_node *head = list->head;
    while (head != NULL && strcmp(head->name, name) != 0)
        head = head->next;

    if (head == NULL)
    {
        fprintf(stderr, "Error - No such element (%s)\n", name);
        exit(EXIT_FAILURE);
    }
    return head;
}

char *JSON_2str(JSON_list *list)
{
    SLList *str    = sllist_mk();
    JSON_node *tmp = list->head;

    if (list->type == JSON_OBJECT)
        sllist_push(str, "{", 1);

    else if (list->type == JSON_ARRAY)
        sllist_push(str, "[", 1);

    while (tmp != NULL)
    {
        if (list->type == JSON_OBJECT)
        {
            sllist_push(str, "\"", 1);
            sllist_push(str, tmp->name, strlen(tmp->name));
            sllist_push(str, "\":", 2);
        }
        sllist_push(str, tmp->data_str, 0);
        sllist_push(str, ",", 1);
        tmp = tmp->next;
    }

    // remove last ,
    //    sllist_pop(str);
    if (list->type == JSON_OBJECT)
        sllist_push(str, "}", 1);

    else if (list->type == JSON_ARRAY)
        sllist_push(str, "]", 1);

    char *str_out = sllist_2str(str);
    sllist_free(str);

    return str_out;
}

void JSON_free(JSON_list *list)
{
    JSON_node *head = list->head;
    JSON_node *tmp  = NULL;

    while (head != NULL)
    {
        tmp  = head;
        head = head->next;

        if (tmp->data_str != "")
            free(tmp->data_str);

        free(tmp->name);

        if (tmp->up != NULL)
            JSON_free(tmp->up);

        free(tmp);
    }

    free(list);
    free(head);
}

static void JSON_handle_el_data(const char *raw_json, int *i, char *tmp_data, JSON_NODE_TYPE *data_type, SLList *data)
{
    int count           = 0;
    size_t raw_json_len = strlen(raw_json);

    if (raw_json[*i] == '[')
    {
        do
        {
            if (*i == raw_json_len - 1) { break; }

            // if tmp_data is full, realloc
            if (strlen(tmp_data) == JSON_DATA_MALLOC - 1)
            {
                sllist_push(data, tmp_data, JSON_DATA_MALLOC);
                memset(tmp_data, 0, JSON_DATA_MALLOC);
            }

            if (raw_json[*i] == '[') count++;
            if (raw_json[*i] == ']') count--;

            tmp_data[strlen(tmp_data)] = raw_json[*i];
            (*i)++;
        } while (raw_json[(*i) - 1] != ']' || count != 0);

        *data_type = JSON_ARRAY;
    }
    // if the data is an object.
    else if (raw_json[*i] == '{')
    {
        do
        {
            if (*i == raw_json_len - 1) { break; }

            if (strlen(tmp_data) == JSON_DATA_MALLOC - 1)
            {
                sllist_push(data, tmp_data, JSON_DATA_MALLOC);
                memset(tmp_data, 0, JSON_DATA_MALLOC);
            }

            if (raw_json[*i] == '{')
                count++;

            if (raw_json[*i] == '}')
                count--;

            tmp_data[strlen(tmp_data)] = raw_json[*i];
            (*i)++;
        } while (raw_json[(*i) - 1] != '}' || raw_json[*i] != ',' || count != 0);

        *data_type = JSON_OBJECT;
    }
    // if the data is a string.
    else if (raw_json[*i] == '\"')
    {
        // ignore "
        (*i)++;
        while (raw_json[*i] != '"' || raw_json[*i + 1] != ',')
        {
            if (*i == raw_json_len - 1) break;

            if (strlen(tmp_data) == JSON_DATA_MALLOC)
            {
                sllist_push(data, tmp_data, JSON_DATA_MALLOC);
                memset(tmp_data, 0, JSON_DATA_MALLOC);
            }

            tmp_data[strlen(tmp_data)] = raw_json[*i];
            (*i)++;
        }

        *data_type = JSON_STRING;
    }
    // otherwise. Numbers, NULL and booleans.
    else
    {
        while (raw_json[*i] != ',' && raw_json[*i] != '}' && raw_json[*i] != ']')
        {
            if (strlen(raw_json) == *i + 1) break;

            if (strlen(tmp_data) == JSON_DATA_MALLOC - 1)
            {
                sllist_push(data, tmp_data, JSON_DATA_MALLOC);
                memset(tmp_data, 0, JSON_DATA_MALLOC);
            }

            tmp_data[strlen(tmp_data)] = raw_json[*i];
            (*i)++;
        }

        // will be treated as the same way.
        *data_type = JSON_NUMBER | JSON_NULL | JSON_BOOLEAN;
    }

    if (strlen(tmp_data) != 0)
        sllist_push(data, tmp_data, strlen(tmp_data));
}

static JSON_node *JSON_mk_node()
{
    JSON_node *new_json_node = (JSON_node *) malloc(sizeof(JSON_node) + 1);
    if (new_json_node == NULL)
        log_msg(LOG_ERROR, "JSON Singly Linked List Overflow.");

    new_json_node->name     = NULL;
    new_json_node->data_str = NULL;
    new_json_node->next     = NULL;
    new_json_node->up       = NULL;

    return new_json_node;
}

static char *JSON_jmpic(char *raw_json)
{
    int i           = 0;
    int j           = 0;

    SLList *data    = sllist_mk();
    char *last_char = &raw_json[0];

    while (raw_json[i] != '\0')
    {
        if (raw_json[i] == '\"')
            while (raw_json[i] != '\"' && raw_json[i] != '\0')
                i++;

        if (raw_json[i] == 0x20 || raw_json[i] == 0x09 ||
            raw_json[i] == 0x0A || raw_json[i] == 0x0D)
        {
            sllist_push(data, last_char, i - j);

            while (raw_json[i] == 0x20 || raw_json[i] == 0x09 ||
                   raw_json[i] == 0x0A || raw_json[i] == 0x0D)
            {
                if (raw_json[i] == '\0')
                    break;
                i++;
            }

            last_char = &raw_json[i];
            j         = i;
        }

        i++;
    }

    sllist_push(data, last_char, i - j);

    char *out = sllist_2str(data);
    sllist_free(data);

    return out;
}

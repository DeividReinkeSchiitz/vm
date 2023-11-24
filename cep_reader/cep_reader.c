/**************************************************
*
* Trabalho 1
* Author: Deivid Reinke Schutz
* Professor(a): Edson Takashi Matsubara
*/

#include "cep_avl.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

CEPAVL_Node *readCeps();

int main()
{
    CEPAVL_Node *root = readCeps();

    /******** SEARCH FOR A CEP ********/
    int cep           = 10;
    CEPAVL_Node *node = cavl_search(root, cep);
    if (node == NULL)
        printf("CEP not found.\n");

    cavl_printNode(node);

    /******** SEARCH FOR A INTERVAL ********/
    int cep1           = 20;
    int cep2           = 50;

    CEPAVL_Node *node1 = cavl_search(root, cep1);
    CEPAVL_Node *node2 = cavl_search(root, cep2);

    while (node1->key.cep <= node2->key.cep)
    {
        cavl_printNode(node1);
        node1 = cavl_sucessor(node1);
    }

    /******** FREE MEMORY ********/
    cavl_free(root);
    return 0;
}

CEPAVL_Node *readCeps()
{
    /******** READ FILE ********/
    char cwd[1024];  // Assuming a maximum path length of 1024 characters
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        perror("getcwd");

    strcpy(cwd, strcat(cwd, "/../data.csv"));
    FILE *file = fopen(cwd, "r");
    if (file == NULL)
        perror("Failed to open the file.\n");

    /******** INSERT ALL CEPS ********/
    int i = 0;
    char line[1024];  // Assuming a maximum line length of 1024 characters
    CEPAVL_key tmp_key;
    CEPAVL_Node *root = NULL;
    while (fgets(line, sizeof(line), file))
    {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        if (sscanf(line, "%d,%49[^,],%49[^,],%49[^,],%d,%49[^,]",
                   &tmp_key.index,
                   tmp_key.city,
                   tmp_key.street,
                   tmp_key.neighbor,
                   &tmp_key.cep,
                   tmp_key.complement) == 6)
        {
            root = cavl_insert(root, tmp_key);
        }
    }

    fclose(file);
    return root;
}

#include <stdio.h>
#include <stdlib.h>
#include "AllFunctions.h"


int main()
{
    printf("*************Choisissez le graphe a executer (entre 1 et 5) : ******************\n");
    char TextName;
    scanf("%s", &TextName);
    ouverture_fichier(&TextName);

    return 0;
}

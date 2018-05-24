/*developped by @TimRD (Timothée Marguier) and Sonia Amrouche and SOlenn Regne*/
#include <stdio.h>
#include <stdlib.h>
#include "AllFunctions.h"


int main()
{
    char TextName;
    while(TextName != 'q'){
        printf("\n*************Choisissez le graphe a executer (entre 1 et 5) ou bien quittez (q): ******************\n");
        scanf("%s", &TextName);
        if(TextName!='q')ouverture_fichier(&TextName);
        else;

    };

    return 0;
}

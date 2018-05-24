#include "AllFunctions.h"

int circuit(int tableau[50][50], int s) // Fonction qui determine si le graphe contient un circuit ou non
{
    int somme = 0;
    int m = 0;
    int stop = 1;
    int i, j; //deux entiers, compteurs
    int tabsortie[100] =  {0};
    int tabsortie2[100] = {0};
    int tableau2[50][50];

    for(i = 0; i < s; i++)
    {
        for(j = 0; j < s; j++)
        {
            tableau2[i][j] = tableau[i][j];
        }
    }


    do
    {
        for(i = 0; i < s; i++)
        {
            for(j = 0; j < s; j++)
            {
                tabsortie[i] += tableau2[i][j];
            }
            if(tabsortie[i] > 0)
            {
                somme++;
            }
        }
        for(i = 0; i < s; i++)
        {
            if(tabsortie[i] == 0)
            {
                for(j = 0; j < s; j++)
                {
                    tableau2[j][i] = 0;
                }
            }
        }
        m = 0;
        for(i = 0; i < s; i++)
        {
            printf("%d", tabsortie[i]);
            if(tabsortie[i] == tabsortie2[i])
            {
                m++;
            }

            tabsortie2[i] = tabsortie[i];
            tabsortie[i] = 0;
        }
        printf("\n");

        if(m == s)
        {
            printf("Il y a un circuit");
            return 0;
        }

        if(somme == s)
        {
            stop = 0;
        }
        else if(somme == 0) {
            printf("\nIl n'y pas de circuit\n");
            stop = 0;
        }
        somme = 0;


    }while(stop); //la boucle s'arrete  avec la condition d'arret
    return 0;
}

void ouverture_fichier(char TextNum[]){ // fonction qui permet l'ouverture de fichier dans le dossier

    char TextName[5] = "D1_G";
    strcat(TextName, TextNum);
    strcat(TextName, ".txt");

    FILE* fichier = NULL;
    fichier = fopen(TextName, "r");


    int s = 0;
    int a = 0;
    int i,j = 0;
    if(fichier == NULL)
    {
        //printf("Le fichier %s ne peut pas etre ouvert", TextName);
        printf("Le fichier ne peut pas etre ouvert");
    }
    else
    {
        fscanf(fichier, "%d", &s);
        fscanf(fichier, "%d", &a);
        printf("\nnombre de sommets du graphes : %d\nnombre d'arcs du graphes : %d\n\n", s, a);
        int tableau2[50][50]={0};
        int tableauValeurs[50][50]={0};
        int *q = NULL;
        int *d = NULL;
        int *p = NULL;

        q = (int*)malloc(a*sizeof(int));
        d = (int*)malloc(a*sizeof(int));
        p = (int*)malloc(a*sizeof(int));
        //Initilisation de la matrice Adjacence & matrice valeurs
        for(j = 0; j < a; j++)
        {
            fscanf(fichier, "%d %d %d", &q[j], &d[j], &p[j]);
            tableau2[q[j]][d[j]] = 1;
            tableauValeurs[q[j]][d[j]] = p[j];
        }
        printf("Matrice adjacence \n");
        printf("  ");
        for(i = 0; i < s; i++){
            if(i==0){
                for(j = 0; j < s; j++){
                    printf("%d ",j);
                }
                printf("\n");
                for(j = 0; j < s; j++){
                    printf("--",j);
                }
                printf("\n");
            }
            for(j = 0; j < s; j++){
                if(j==0){
                    printf("%d|", i);
                }
                printf("%d ", tableau2[i][j]);
            }
            printf("\n");
        }
        printf("\n");
                printf("Matrice valeurs \n");
        printf("  ");
        for(i = 0; i < s; i++){
            if(i==0){
                for(j = 0; j < s; j++){
                    printf("%d ",j);
                }
                printf("\n");
                for(j = 0; j < s; j++){
                    printf("--",j);
                }
                printf("\n");
            }
            for(j = 0; j < s; j++){
                if(j==0){
                    printf("%d|", i);
                }
                printf("%d ", tableauValeurs[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        circuit(tableau2, s);


    }


    fclose(fichier);

}


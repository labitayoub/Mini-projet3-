#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Contact {
    char nom[30];
    char phone[15];
    char email[20];
    int id;
} Contact;

Contact Contact1[100];
int c = 0;

void choix1() {
    printf("\n\tAjouter un contact\n : \n");
    Contact1[c].id = c + 1;
    printf("Entrer le nom : ");
    scanf(" %[^\n]", Contact1[c].nom);
    printf("Entrer le Numero de telephone : ");
    scanf(" %[^\n]", Contact1[c].phone);

    for (int i = 0; i < c; i++) {
        if (strcmp(Contact1[i].phone, Contact1[c].phone) == 0) {
            printf("Ce numero existe deja !!\n");
            return;
        }
    }

    printf("Entrer email : ");
    scanf(" %[^\n]", Contact1[c].email);

    for (int i = 0; i < c; i++) {
        if (strcmp(Contact1[i].email, Contact1[c].email) == 0) {
            printf("L'email que vous avez saisi existe deja !!\n");
            return;
        }
    }
    c++;
    printf("\n[ L'operation est valide ]\n");
}

void choix2() {
    char modifier[100];
    int i, x = 0;

    printf("Modifier le contact :\n");
    printf("Entrer le nom pour modifier : ");
    scanf(" %[^\n]", modifier);

    for (i = 0; i < c; i++) {
        if (strcmp(modifier, Contact1[i].nom) == 0) {
            printf("Entrer le nom : ");
            scanf(" %[^\n]", Contact1[i].nom);
            printf("Entrer le Numero de telephone : ");
            scanf(" %[^\n]", Contact1[i].phone);
            printf("Entrer email : ");
            scanf(" %[^\n]", Contact1[i].email);
            printf("\n[ Modifie avec succes ]\n");
            x = 1;
            break;
        }
    }
    if (x == 0) {
        printf("Le contact n'a pas ete trouve.\n\n");
    }
}

void choix3() {
    char supprimer[100];
    int i, j, x = 0;

    printf("\nSupprimer le contact : \n");
    printf("Entrer le nom : ");
    scanf(" %[^\n]", supprimer);

    for (i = 0; i < c; i++) {
        if (strcmp(supprimer, Contact1[i].nom) == 0) {
            for (j = i; j < c - 1; j++) 
            {    
                strcpy(Contact1[j].nom, Contact1[j+1].nom);
                strcpy(Contact1[j].email, Contact1[j+1].email);
                strcpy(Contact1[j].phone, Contact1[j+1].phone);
            }
            c--;
            printf("Contact supprime avec succes.\n");
            x = 1;
            break;
        }
    }

    if (x == 0) {
        printf("Le contact est introuvable.\n");
    }
}

void choix4() {
    printf("La Liste Des Contacts Disponible\n\n");
    printf("+-----+----------------+-------------+--------------------------+\n");
    printf("| ID  |      Nom       |  Telephone  |           Email          |\n");
    printf("+-----+----------------+-------------+--------------------------+\n");

    for (int i = 0; i < c; i++) {
        printf("| %3d | %-14s | %-11s | %-24s |\n", Contact1[i].id, Contact1[i].nom, Contact1[i].phone, Contact1[i].email);
    }

    printf("+-----+----------------+-------------+--------------------------+\n");

    if (c == 0) {
        printf("Aucun Contact.\n");
    }
}

void choix5() {
    char Recherche[50];
    int i, x = 0;

    printf("\nRechercher un contact :\n");
    printf("Entrer le nom du contact a chercher : ");
    scanf(" %[^\n]", Recherche);

    for (int i = 0; i < c; i++) {
        if (strcmp(Contact1[i].nom, Recherche) == 0) {
            printf("ID: %d, Nom: %s, Telephone: %s, Email: %s\n",
                   Contact1[i].id, Contact1[i].nom, Contact1[i].phone, Contact1[i].email);
            x = 1;
            break;
        }
    }

    if (x == 0) {
        printf("Le contact n'a pas ete trouve.\n");
    }
}

int main() {
    int operation;

    do {
        printf("  ========* Menu *========\n");
        printf("1 : Ajouter un contact.\n");
        printf("2 : Modifier un contact.\n");
        printf("3 : Supprimer un contact.\n");
        printf("4 : Afficher les contacts.\n");
        printf("5 : Rechercher un contact.\n");
        printf("6 : Quitter le programme.\n\n");
        printf("Choisissez une operation : ");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                choix1();
                break;
            case 2:
                choix2();
                break;
            case 3:
                choix3();
                break;
            case 4:
                choix4();
                break;
            case 5:
                choix5();
                break;
            case 6:
                printf("Quitter le programme.\n");
                break;
            default:
                printf("Le numero est introuvable.\n");
                break;
        }
    } while (operation != 6);

    return 0;
}

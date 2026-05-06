#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure [cite: 16-19]
typedef struct fichier {
    char nom[30];
    char type[30];
    int taille;
    struct fichier *suiv;
} Fichier;

// Q1: Créer un nouveau fichier [cite: 21]
Fichier *CreerFichier() {
    Fichier *nouveau = (Fichier*)malloc(sizeof(Fichier));
    printf("Entrer le nom de fichier: ");
    scanf("%s", nouveau->nom);
    printf("Entrer le type de fichier: ");
    scanf("%s", nouveau->type);
    printf("Entrer la taille: ");
    scanf("%d", &nouveau->taille);
    nouveau->suiv = NULL;
    return nouveau;
}

// Q2: Ajouter au début [cite: 32]
Fichier *Ajouter_Debut(Fichier *f) {
    Fichier *nouveau = CreerFichier();
    nouveau->suiv = f;
    return nouveau;
}

// Q3: Ajouter à la fin [cite: 48]
Fichier *Ajouter_Fin(Fichier *f) {
    Fichier *nouveau = CreerFichier();
    if (f == NULL) return nouveau;
    Fichier *temp = f;
    while (temp->suiv != NULL) {
        temp = temp->suiv;
    }
    temp->suiv = nouveau;
    return f;
}

// Q4: Rechercher par nom [cite: 67]
int Rechercher_Nom(Fichier *f, char nomFichier[]) {
    Fichier *temp = f;
    while (temp != NULL) {
        if (strcmp(temp->nom, nomFichier) == 0) return 1;
        temp = temp->suiv;
    }
    return 0;
}

// Q5: Supprimer au début [cite: 70]
Fichier *Supprimer_Debut(Fichier *f) {
    if (f == NULL) return NULL;
    Fichier *temp = f;
    f = f->suiv;
    free(temp);
    return f;
}

// Q6: Supprimer à la fin [cite: 82]
Fichier *Supprimer_Fin(Fichier *f) {
    if (f == NULL) return NULL;
    if (f->suiv == NULL) {
        free(f);
        return NULL;
    }
    Fichier *temp = f;
    while (temp->suiv->suiv != NULL) {
        temp = temp->suiv;
    }
    free(temp->suiv);
    temp->suiv = NULL;
    return f;
}

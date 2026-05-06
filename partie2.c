#include <stdio.h>
#include <stdlib.h>

// Définition de la structure 
typedef struct arbre_binaire_recherche {
    int racine;
    struct arbre_binaire_recherche *SAG;
    struct arbre_binaire_recherche *SAD;
} ABR;

// Q3: Fonction de création 
ABR *Creer_ABR(int valeur, ABR *ABG, ABR *ABD) {
    ABR *nouveau = (ABR*)malloc(sizeof(ABR));
    nouveau->racine = valeur;
    nouveau->SAG = ABG;
    nouveau->SAD = ABD;
    return nouveau;
}

// Q5: Affichage structuré {G, r, D} 
void Affiche_arbre(ABR *a) {
    if (a == NULL) {
        printf("_"); // Représente l'arbre vide 
        return;
    }
    printf("{");
    Affiche_arbre(a->SAG);
    printf(",%d,", a->racine);
    Affiche_arbre(a->SAD);
    printf("}");
}

// Q6: Parcours Infixe 
void parcours_infixe(ABR *a) {
    if (a != NULL) {
        parcours_infixe(a->SAG);
        printf("%d ", a->racine);
        parcours_infixe(a->SAD);
    }
}

// Q7: Recherche d'une valeur 
int recherche(ABR *a, int x) {
    if (a == NULL) return 0;
    if (a->racine == x) return 1;
    if (x < a->racine) return recherche(a->SAG, x);
    return recherche(a->SAD, x);
}

// Q8: Insertion 
ABR* inserer(ABR *a, int x) {
    if (a == NULL) return Creer_ABR(x, NULL, NULL);
    if (x <= a->racine)
        a->SAG = inserer(a->SAG, x); // Selon def Q2 
    else 
        a->SAD = inserer(a->SAD, x);
    return a;
}

int main() {
    // Q4: Construction de l'arbre C 
    ABR *C = Creer_ABR(34,
        Creer_ABR(29, Creer_ABR(24, NULL, NULL), Creer_ABR(32, Creer_ABR(31, NULL, NULL), NULL)),
        Creer_ABR(37, Creer_ABR(35, NULL, NULL), Creer_ABR(40, NULL, NULL))
    );
    
    printf("Parcours Infixe: ");
    parcours_infixe(C);
    return 0;
}

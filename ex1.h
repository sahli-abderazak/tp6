#include<stdio.h>
#include<stdlib.h>
typedef struct noeud
{
    char info;
    struct noeud* gauche;
        struct noeud* droite;

}noeud;
typedef noeud*arbre;


void init_arbre(arbre *a);
noeud*creer_feuille(char x);
void creer_noeud(arbre * a, char x, noeud *fg, noeud *fd);
void AfficheArbrePrefixe(arbre a);
void MotsFeuillesArbreBinaire(arbre a);
int HauteurArbreBinaire(arbre a);
int FacteurEquilibre(arbre a);
int nombre_noeuds(arbre a);
arbre max_noeuds(arbre a);

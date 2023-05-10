#include"ex1.h"
void init_arbre(arbre *a)
{
    *a=NULL;
}
noeud*creer_feuille(char x)
{
    noeud*nv;
    nv=malloc(sizeof(noeud));
    nv->info=x;
    nv->droite=NULL;
    nv->gauche=NULL;
    return nv;
}
void creer_noeud(arbre * a, char x, noeud *fg, noeud *fd)
{
    *a=malloc(sizeof(noeud));
    (*a)->info=x;
    (*a)->gauche=fg;
    (*a)->droite=fd;

}
void AfficheArbrePrefixe(arbre a)
{
    if(a!=NULL)
    {
        printf("%c",a->info);
        AfficheArbrePrefixe(a->gauche);
        AfficheArbrePrefixe(a->droite);
    }
}
void MotsFeuillesArbreBinaire(arbre a)
{
    if(a!=NULL)
    {
        if((a->gauche!=NULL)&&(a->droite!=NULL))
        {
            MotsFeuillesArbreBinaire (a->gauche);
            MotsFeuillesArbreBinaire (a->droite);

        }
        else
        {
            printf("%c",a->info);
        }
    }
}
int HauteurArbreBinaire(arbre a)
{
    if(a==NULL)
    {
        return 0;
    }
    else
    {
        int hg=HauteurArbreBinaire(a->gauche);
        int hd=HauteurArbreBinaire(a->droite);

        if(hd>hg)
        {
            return 1+hd;
        }
        else
        {
            return 1+hg;
        }
    }
}
int FacteurEquilibre(arbre a)
{
    return   HauteurArbreBinaire(a->gauche)-HauteurArbreBinaire(a->droite);
}
void liberer_arbre(arbre *a)
{
    if(*a!=NULL)
    {
        liberer_arbre(&(*a)->gauche);
        liberer_arbre(&(*a)->droite);
        free(*a);
        *a=NULL;
    }
}
int nombre_noeuds(arbre a)
{
    if(a!=NULL)
    {
        return 1+nombre_noeuds(a->gauche)+nombre_noeuds(a->droite);

    }else
    {
        return 0;
    }
}
arbre max_noeuds(arbre a)
{
    arbre max;
    if(a!=NULL)
    {
        arbre mg=max_noeuds(a->gauche);
        arbre md=max_noeuds(a->droite);
        if(a->info>mg->info)
        {
           max=a;
        }else
        {
            max=mg;
        }
        if(max->info>md->info)
        {
            return max;
        }else
        {
            return md;
        }

    }else
    {
        return NULL;
    }
}
int main()
{
    int h,f,nbr;
     noeud*nb;
     noeud*ng;
    noeud*nf;
    noeud*na;
    noeud*nd=creer_feuille('d');
    noeud*ne=creer_feuille('e');
    creer_noeud(&nb,'b',nd,ne);
    noeud*nh=creer_feuille('h');
  creer_noeud(&ng,'g',nh,NULL);
    creer_noeud(&nf,'f',NULL,ng);
    creer_noeud(&na,'a',nb,nf);
    AfficheArbrePrefixe(na);
    MotsFeuillesArbreBinaire(na);
    h=HauteurArbreBinaire(na);
    printf("%d",h);
    f=FacteurEquilibre(na);
    printf("%d",f);
    liberer_arbre(&na);
    nbr=nombre_noeuds(na);
    printf("%d",nbr);
    arbre nx=max_noeuds(na);
}

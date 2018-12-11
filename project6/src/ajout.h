#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
char cin[50];
char poids[10];

}date;
typedef struct
{
char objectif[20];
char type[20];
}seance;

void ajouter(seance s, date d);
void afficher_pto(GtkWidget *liste);
//void afficher_poids(GtkWidget *liste);
void modifier(seance s, date d);
void supprimer(char cin[],int n);





typedef struct
{
char jour[30];
char mois[30];
char annee[50];
}tim;
typedef struct
{
char num[30];
char coach[30];
char heure[30];
}name;
void inscription(name e,tim t);
void afficher_cjma(GtkWidget *liste);
void supprimer1(char num[],int n);







typedef struct
{
char jour2[50];
char mois2[50];
char annee2[50];
}tim2;
typedef struct
{
char heure2[20];
char staff2[20];
char num2[30];
}
name2;
void rdv(name2 n,tim2 h);
void afficher_sjma(GtkWidget *liste);
void supprimer2(char num2[],int n);

//void afficher_pto(GtkWidget *liste);

//void afficher_cjma(GtkWidget *liste);






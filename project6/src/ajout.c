#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajout.h"
#include <gtk/gtk.h>

void ajouter(seance s, date d)
{
FILE *f;
f=fopen("/home/eya/Projects/project6/src/aa.txt","a+");
fprintf(f,"%s %s %s %s\n",d.cin,d.poids,s.type,s.objectif);	
fclose(f);
}
void modifier(seance s, date d)
{
  seance v;
  date b;
  FILE*f;
  FILE *f1;
  f=fopen("aa.txt","a+");
  f1=fopen("aa1.txt","a+");
  if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s\n",b.cin,b.poids,v.type,v.objectif)!=EOF)
    {
      if(strcmp(b.cin,d.cin)==0)
      {
        fprintf(f1,"%s %s %s %s\n",d.cin,d.poids,s.type,s.objectif);
      }
      else fprintf(f1,"%s %s %s %s\n",b.cin,b.poids,v.type,v.objectif);
    }
  }
  fclose(f);
  fclose(f1);
  remove("aa.txt");
  rename("aa1.txt","aa.txt");
}
void supprimer(char cin[],int n)
{
seance s;
date d;
FILE*f;
FILE*f1;


f=fopen("aa.txt","a+");
f1=fopen("aa1.txt","a+");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s\n",d.cin,d.poids,s.type,s.objectif)!=EOF)
{
if(strcmp(cin,d.cin)!=0)
{
fprintf(f1,"%s %s %s %s\n",d.cin,d.poids,s.type,s.objectif);
}

}
}
fclose(f);
fclose(f1);
remove("aa.txt");
rename("aa1.txt","aa.txt");
}








void inscription(name e,tim t)

{
FILE *f;
f=fopen("/home/eya/Projects/project6/src/seancecoach.txt","a+");
fprintf(f,"%s %s %s %s %s %s\n",e.num,e.coach,e.heure,t.jour,t.mois,t.annee);	
fclose(f);
}





void supprimer1(char num[],int n)
{
name e;
tim t;
FILE*f;
FILE*f1;


f=fopen("seancecoach.txt","a+");
f1=fopen("seancecoach1.txt","a+");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s\n",e.num,e.coach,e.heure,t.jour,t.mois,t.annee)!=EOF)
{
if(strcmp(num,e.num)!=0)
{
fprintf(f1,"%s %s %s %s %s %s\n",e.num,e.coach,e.heure,t.jour,t.mois,t.annee);
}

}
}
fclose(f);
fclose(f1);
remove("seancecoach.txt");
rename("seancecoach1.txt","seancecoach.txt");
}



void rdv(name2 n,tim2 h)
{
FILE *f;
f=fopen("/home/eya/Projects/project6/src/rdv.txt","a+");
fprintf(f,"%s %s %s %s %s %s\n",n.num2,n.staff2,n.heure2,h.jour2,h.mois2,h.annee2);	
fclose(f);
}


void supprimer2(char num2[],int n)
{
name2 e;
tim2 t;
FILE*f;
FILE*f1;


f=fopen("rdv.txt","a+");
f1=fopen("rdv1.txt","a+");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s\n",e.num2,e.staff2,e.heure2,t.jour2,t.mois2,t.annee2)!=EOF)
{
if(strcmp(num2,e.num2)!=0)
{
fprintf(f1,"%s %s %s %s %s %s\n",e.num2,e.staff2,e.heure2,t.jour2,t.mois2,t.annee2);
}

}
}
fclose(f);
fclose(f1);
remove("rdv.txt");
rename("rdv1.txt","rdv.txt");
}






enum
{
	CIN,
	POIDS,
	TYPE,
	OBJECTIF,
	COLUMNS
};

void afficher_pto(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    
    char poids1[5];
    char type1[30];
    char objectif1[300];
    char cin[20];
    store=NULL;
    FILE *f;
    
    //store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    if(store==NULL)
    {
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",CIN,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Poids",renderer,"text",POIDS,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Objectif",renderer,"text",OBJECTIF,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

       
        
}


    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    f=fopen("/home/eya/Projects/project6/src/aa.txt","r");
    if(f==NULL)
    {return;}
    else
    { f=fopen("/home/eya/Projects/project6/src/aa.txt","a+");
        while(fscanf(f,"%s %s %s %s\n",cin,poids1,type1,objectif1)!=EOF)
       {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store,&iter, CIN, cin,POIDS, poids1, TYPE, type1, OBJECTIF, objectif1, -1);
       }
       fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    }

}







enum
{
	NUM,
	COACH,
	HEURE,
	JOUR,
	MOIS,
	ANNEE,
	COLUMNS1
};

void afficher_cjma(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    
    char num[20];
    char coach[50];
    char heure[20];
    char jour[30];
    char mois[300];
    char annee[300];
    store=NULL;
    FILE *f;
    
    //store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    if(store==NULL)
    {
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Num",renderer,"text",NUM,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Coach",renderer,"text",COACH,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Heure",renderer,"text",HEURE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Jour",renderer,"text",JOUR,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Mois",renderer,"text",MOIS,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Annee",renderer,"text",ANNEE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
}


    store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    f=fopen("/home/eya/Projects/project6/src/seancecoach.txt","r");
    if(f==NULL)
    {return;}
    else
    { f=fopen("/home/eya/Projects/project6/src/seancecoach.txt","a+");
        while(fscanf(f,"%s %s %s %s %s %s\n",num,coach,heure,jour,mois,annee)!=EOF)
       {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store,&iter, NUM, num,COACH, coach,HEURE, heure,JOUR ,jour,MOIS, mois,ANNEE, annee, -1);
       }
       fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    }

}









enum
{
	NUM2,
	STAFF2,
	HEURE2,
	JOUR2,
	MOIS2,
	ANNEE2,
	COLUMNS2
};

void afficher_sjma(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char num2[5];
    char staff2[5];
    char heure2[10];
    char jour2[30];
    char mois2[300];
    char annee2[300];
    store=NULL;
    FILE *f;
    
    //store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    if(store==NULL)
    {

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" num",renderer,"text",NUM2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Staff",renderer,"text",STAFF2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" heure",renderer,"text",HEURE2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Jour",renderer,"text",JOUR2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Mois",renderer,"text",MOIS2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Annee",renderer,"text",ANNEE2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
}


    store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
    f=fopen("/home/eya/Projects/project6/src/rdv.txt","r");
    if(f==NULL)
    {return;}
    else
    { f=fopen("/home/eya/Projects/project6/src/rdv.txt","a+");
        while(fscanf(f,"%s %s %s %s %s %s\n",num2,staff2,heure2,jour2,mois2,annee2)!=EOF)
       {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store,&iter, NUM2, num2,STAFF2, staff2, HEURE2,heure2,JOUR2 ,jour2,MOIS2, mois2,ANNEE2, annee2,-1);
       }
       fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    }
}


       

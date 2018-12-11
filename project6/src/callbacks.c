#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include <stdio.h>
#include "login.c"
#include "ajout.h"
#include "imc.h"

void
on_bt_gest_don_ad_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)


{
GtkWidget *treeview1;
GtkWidget *window2;
GtkWidget *window3;
window3=create_window3();
window2=lookup_widget(objet_graphique,"window2");
gtk_widget_hide(window2);
gtk_widget_show(window3);
treeview1=lookup_widget(window3,"treeview1");
afficher_pto(treeview1);


}



void
on_bt_inscri_seance_adh_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window2;
GtkWidget *window6;
GtkWidget *treeview2;

window6=create_window6();
window2=lookup_widget(objet_graphique,"window2");
gtk_widget_hide(window2);
gtk_widget_show(window6);
treeview2=lookup_widget(window6,"treeview2");
afficher_cjma(treeview2);



}



void
on_bt_gest_rdv_staff_adh_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window2;
GtkWidget *window8;
GtkWidget *treeview3;
window8=create_window8();
window2=lookup_widget(objet_graphique,"window2");
gtk_widget_hide(window2);
gtk_widget_show(window8);
treeview3=lookup_widget(window8,"treeview3");
afficher_sjma(treeview3);

}
/*void
on_bt_gest_event_adh_clicked           (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window2;
GtkWidget *window10;
window10=create_window10();
window2=lookup_widget(objet_graphique,"window2");
gtk_widget_hide(window2);
gtk_widget_show(window10);

}*/



void
on_bt_retour_adh_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window2;
GtkWidget *window3;
window2=create_window2();
window3=lookup_widget(objet_graphique,"window3");
gtk_widget_hide(window3);
gtk_widget_show(window2);

}




void
on_bt_ajout_donnee_adh_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window3;
GtkWidget *window5;
window5=create_window5();
window3=lookup_widget(objet_graphique,"window3");
gtk_widget_hide(window3);
gtk_widget_show(window5);

}


void
on_bt_modif_donnee_adh_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
 char cin[50];
  seance s;
  date d;
  FILE*f;
  GtkWidget *input;
  GtkWidget *window3;
  GtkWidget *window12;
  GtkWidget *output1;
  GtkWidget *output2;
  GtkWidget *output3;
  GtkWidget *output4;
  



  input=lookup_widget(objet_graphique,"entry5");
  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
  window12=create_window12();
  window3=lookup_widget(objet_graphique,"window3");
  gtk_widget_hide(window3);
  gtk_widget_show(window12);
  output4=lookup_widget(window12,"entry10");
  output1=lookup_widget(window12,"entry7");
  output2=lookup_widget(window12,"comboboxentry1");
  output3=lookup_widget(window12,"entry9");
  f=fopen("aa.txt","a+");
  if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s\n",d.cin,d.poids,s.type,s.objectif)!=EOF)
    {
      if(strcmp(cin,d.cin)==0)
      {
	gtk_entry_set_text(GTK_ENTRY(output4),d.cin);
        gtk_entry_set_text(GTK_ENTRY(output1),d.poids);
        gtk_entry_set_text(GTK_ENTRY(output2),s.type);
        gtk_entry_set_text(GTK_ENTRY(output3),s.objectif);
       
      }
    }
    fclose(f);
  }

}




void
on_bt_supp_donnee_adh_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *input;
  GtkWidget *treeview1;
  GtkWidget *window3;
  GtkWidget *output;
  char c[]="suppression";
  output=lookup_widget(objet_graphique,"label65");
  window3=lookup_widget(objet_graphique,"window3");
  int n=9;
  char cin[9];
  input=lookup_widget(objet_graphique,"entry6");
  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
  supprimer(cin,n);
  treeview1=lookup_widget(window3,"treeview1");
  afficher_pto(treeview1);
  gtk_label_set_text(GTK_LABEL(output),c);
}






void
on_bt_valid_adh_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window4;
window3=create_window3();
window4=lookup_widget(objet_graphique,"window4");
gtk_widget_hide(window4);
gtk_widget_show(window3);


char t[40], p[40];
int ta=0,po=0;
float i;
int j=0;
char k[20];
GtkWidget *calimc;
GtkWidget *inputtaille;
GtkWidget *inputpoids;
GtkWidget *outputimc;
outputimc=lookup_widget(window3,"label4");
inputtaille=lookup_widget(window4,"entry_taille_adh");
inputpoids=lookup_widget(window4,"entry_poids_adh");
strcpy(t,gtk_entry_get_text(GTK_ENTRY(inputtaille)));
strcpy(p,gtk_entry_get_text(GTK_ENTRY(inputpoids)));
ta=(float)atoi(t);
po=(float)atoi(p);
i=imc1(po,ta);
memset(k,0,sizeof(k));
sprintf(k, "%f", i);
gtk_label_set_text(GTK_LABEL(outputimc),k);
FILE *f;
f=fopen("liste_imc.txt","a+");
{
fprintf(f,"%s \n",k);
}
fclose(f);
}









void
on_bt_ajouter_donnee_adh_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
seance s;
date d;

GtkWidget *cin;
GtkWidget *poids;
GtkWidget *type;
GtkWidget *objectif;

cin=lookup_widget(objet_graphique,"entry_cin_adh");
poids=lookup_widget(objet_graphique,"entry_poids_donnee_adh");
type=lookup_widget(objet_graphique,"type");
objectif=lookup_widget(objet_graphique,"objectif");


strcpy(d.cin,gtk_entry_get_text(GTK_ENTRY(cin)));  
strcpy(d.poids,gtk_entry_get_text(GTK_ENTRY(poids)));  
strcpy(s.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type))); 
strcpy(s.objectif,gtk_entry_get_text(GTK_ENTRY(objectif)));


ajouter(s,d);


}




void
on_bt_valid1_adh_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *num;
GtkWidget *coach;
GtkWidget *heure;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;

name e;
tim t;


num=lookup_widget(objet_graphique,"entry13");
coach=lookup_widget(objet_graphique,"coach");
heure=lookup_widget(objet_graphique,"heure");
jour=lookup_widget(objet_graphique,"jour");
mois=lookup_widget(objet_graphique,"mois");
annee=lookup_widget(objet_graphique,"annee");
strcpy(e.num,gtk_entry_get_text(GTK_ENTRY(num)));
strcpy(e.coach,gtk_combo_box_get_active_text(GTK_COMBO_BOX(coach)));
strcpy(e.heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX(heure)));
strcpy(t.jour,gtk_entry_get_text(GTK_ENTRY(jour)));
strcpy(t.mois,gtk_entry_get_text(GTK_ENTRY(mois)));
strcpy(t.annee,gtk_entry_get_text(GTK_ENTRY(annee)));
/*t.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));   
t.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));  
t.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)); */

inscription(e,t);


 

}
void
on_bt_ajouter1_rdv_adh_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window8;
GtkWidget *window9;
window9=create_window9();
window8=lookup_widget(objet_graphique,"window8");
gtk_widget_hide(window8);
gtk_widget_show(window9);

}



void
on_bt_retour_staff_adh_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window2;
GtkWidget *window8;
window2=create_window2();
window8=lookup_widget(objet_graphique,"window8");
gtk_widget_hide(window8);
gtk_widget_show(window2);


}


void
on_bt_retour_rdv_adh_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview3;
GtkWidget *window9;
GtkWidget *window8;
window8=create_window8();
window9=lookup_widget(objet_graphique,"window9");
gtk_widget_hide(window9);
gtk_widget_show(window8);
treeview3=lookup_widget(window8,"treeview3");
afficher_sjma(treeview3);
}




void
on_bt_valid2_adh_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *num2;
GtkWidget *staff2;
GtkWidget *heure2;
GtkWidget *jour2;
GtkWidget *mois2;	
GtkWidget *annee2;

name2 n;
tim2 h;


num2=lookup_widget(objet_graphique,"num2");
staff2=lookup_widget(objet_graphique,"staff2");
heure2=lookup_widget(objet_graphique,"heure2");
jour2=lookup_widget(objet_graphique,"jour2");
mois2=lookup_widget(objet_graphique,"mois2");
annee2=lookup_widget(objet_graphique,"annee2");
strcpy(n.num2,gtk_entry_get_text(GTK_ENTRY(num2)));
strcpy(n.staff2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(staff2)));
strcpy(n.heure2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(heure2)));
strcpy(h.jour2,gtk_entry_get_text(GTK_ENTRY(jour2)));
strcpy(h.mois2,gtk_entry_get_text(GTK_ENTRY(mois2)));
strcpy(h.annee2,gtk_entry_get_text(GTK_ENTRY(annee2)));
/*h.jour2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour2));  
h.mois2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois2));  
h.annee2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee2));*/  
rdv(n,h);
}



void
on_bt_logout_espace_adh_clicked        (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}



void
on_bt_retour1_adh_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window4;
GtkWidget *window3;
window3=create_window3();
window4=lookup_widget(objet_graphique,"window4");
gtk_widget_hide(window4);
gtk_widget_show(window3);

}



void
on_bt_retour2_adh_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *window5;
GtkWidget *window3;
window3=create_window3();
window5=lookup_widget(objet_graphique,"window5");
gtk_widget_hide(window5);
gtk_widget_show(window3);
treeview1=lookup_widget(window3,"treeview1");
afficher_pto(treeview1);
}



void
on_bt_retour3_adh_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window6;
GtkWidget *window2;
window2=create_window2();
window6=lookup_widget(objet_graphique,"window6");
gtk_widget_hide(window6);
gtk_widget_show(window2);

}





void
on_bt_retour4_adh_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
GtkWidget *window7;
GtkWidget *window6;
window6=create_window6();
window7=lookup_widget(objet_graphique,"window7");
gtk_widget_hide(window7);
gtk_widget_show(window6);
treeview2=lookup_widget(window6,"treeview2");
afficher_cjma(treeview2);

}







void
on_bt_login_adh_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int n=150,check = -1;
     char b[70]="Bienvenue dans l'espace ";
     char c[50]="mot de passe ou login incorrect";
     GtkWidget *input1;
     GtkWidget *input2;
     GtkWidget *output1;
     GtkWidget *output2;
     GtkWidget *window2;
     GtkWidget *window1;



     window2=create_window2();
     input1=lookup_widget(objet_graphique, "entry3");
     input2=lookup_widget(objet_graphique, "entry4");
     output1=lookup_widget(objet_graphique, "label_mdp_inc");
     window1=lookup_widget(objet_graphique,"window1");
     char nom[20];
     strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
     char pass[20];
     strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input2)));
     check = check_user(nom,pass,n);
     if (check==0){
      gtk_widget_hide(window1);
     strcat(b,nom);
     gtk_widget_show(window2);
     output2=lookup_widget(window2, "label5");
     gtk_label_set_text(GTK_LABEL(output2),b);
     }else{
     gtk_label_set_text(GTK_LABEL(output1),c);
     }
}






void
on_bt_quitter_adh_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_bt_inscrip_seance_adh_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window6;
GtkWidget *window7;
window7=create_window7();
window6=lookup_widget(objet_graphique,"window6");
gtk_widget_hide(window6);
gtk_widget_show(window7);

}


void
on_calcul_IMC_adh_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *window4;
window4=create_window4();
window3=lookup_widget(objet_graphique,"window3");
gtk_widget_hide(window3);
gtk_widget_show(window4);
}


void
on_bt_retour5_adh_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *window12;
GtkWidget *window3;
window3=create_window3();
window12=lookup_widget(objet_graphique,"window12");
gtk_widget_hide(window12);
gtk_widget_show(window3);
treeview1=lookup_widget(window3,"treeview1");
afficher_pto(treeview1);
}


void
on_bt_modif1_adh_clicked               (GtkWidget       *objet_graphique,
                                      gpointer         user_data)
{
  seance s;
  date d;
  GtkWidget*input1;
  GtkWidget*input2;
  GtkWidget*input3;
  GtkWidget*input4;
  GtkWidget*output;
  FILE*f;
  char c[]="modification terminee";
  output=lookup_widget(objet_graphique,"label64");
  input4=lookup_widget(objet_graphique,"entry10");
  
  input1=lookup_widget(objet_graphique,"entry7");
  input2=lookup_widget(objet_graphique,"comboboxentry1");
  input3=lookup_widget(objet_graphique,"entry9");
  strcpy(d.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(d.poids,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(s.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
  strcpy(s.objectif,gtk_entry_get_text(GTK_ENTRY(input3)));
  
 
  modifier(s,d);
  gtk_label_set_text(GTK_LABEL(output),c);

}


void
on_bt_modif2_seance_adh_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_bt_supp2_seance_adh_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *input;
  GtkWidget *treeview2;
  GtkWidget *window6;
  GtkWidget *output;
  char c[]="suppression";
  output=lookup_widget(objet_graphique,"label70_adh");
  window6=lookup_widget(objet_graphique,"window6");
  int n=9;
  char num[9];
  input=lookup_widget(objet_graphique,"entry12_adh");
  strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
  supprimer1(num,n);
  treeview2=lookup_widget(window6,"treeview2");
  afficher_cjma(treeview2);
  gtk_label_set_text(GTK_LABEL(output),c);
}

void
on_bt_profil_adh_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
/*FILE *fi;
char nom1[20];
char prenom1[20];
char date1[20];
char email1[20];
char cin1[20];
char adresse1[20];
char nom[20];
char prenom[20];
char date[20];
char email[20];
char cin[20];
char adresse[20];
GtkWidget *a;
GtkWidget *b;
GtkWidget *c;
GtkWidget *d;
GtkWidget *e;
GtkWidget *f;
GtkWidget *window2;
GtkWidget *window13;*/

GtkWidget *window13;
GtkWidget *window2;
window13=create_window13();
window2=lookup_widget(objet_graphique,"window2");
gtk_widget_show(window13);
gtk_widget_hide(window2);

/*a=lookup_widget(window13, "entry_nom_adh");
b=lookup_widget(window13, "entry_prenom_adh");
c=lookup_widget(window13, "entry_ddn_adh");
d=lookup_widget(window13, "entry_mail_adh");
e=lookup_widget(window13, "entry_cin_adh");
f=lookup_widget(window13, "entry_adresse_adh");

fi=fopen("/home/eya/Projets/projet6/src/profil.txt","r");
if (fi==NULL) printf("erreur\n");
 else {
while (fscanf(fi,"%s %s %s %s %s %s",nom1,prenom1,date1,email1,cin1,adresse1)!=EOF)
{ 
break;
}
fclose(f);}
gtk_entry_set_text(GTK_ENTRY(a),nom1);
gtk_entry_set_text(GTK_ENTRY(b),prenom1);
gtk_entry_set_text(GTK_ENTRY(c),date1);
gtk_entry_set_text(GTK_ENTRY(d),email1);
gtk_entry_set_text(GTK_ENTRY(e),cin1);
gtk_entry_set_text(GTK_ENTRY(f),adresse1);*/
}




void
on_bt_supp_rdv_adh_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *input;
  GtkWidget *treeview3;
  GtkWidget *window8;
  GtkWidget *output;
  char c[]="suppression";
  output=lookup_widget(objet_graphique,"label75");
  window8=lookup_widget(objet_graphique,"window8");
  int n=9;
  char num2[9];
  input=lookup_widget(objet_graphique,"entry11");
  strcpy(num2,gtk_entry_get_text(GTK_ENTRY(input)));
  supprimer2(num2,n);
  treeview3=lookup_widget(window8,"treeview3");
  afficher_sjma(treeview3);
  gtk_label_set_text(GTK_LABEL(output),c);
}


void
on_bt_retour_profil_adh_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window13;
GtkWidget *window2;
window2=create_window2();
window13=lookup_widget(objet_graphique,"window13");
gtk_widget_hide(window13);
gtk_widget_show(window2);
}


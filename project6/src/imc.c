#include <string.h>
#include <stdio.h>
float imc1(float poids,float taille)
{
float i;
i=((poids*10000)/(taille*taille));
return(i);
}

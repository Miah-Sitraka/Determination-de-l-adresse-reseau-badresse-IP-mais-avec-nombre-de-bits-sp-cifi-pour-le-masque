#include <stdio.h>
#include  <math.h>
#include  "ipexo2.h"
#include  "ipexo2fonction.c"
int main(){
	printf("\tProgramme permettant d'afficher l'adresse réseau,le broadcast,le nombre d'hotes a chaque sous-réseau ainsi que le nombre de sous réseau:\n");
///Données
    int  a=0, b=0, c=0, d=0;
	unsigned char octet1 = 0, octet2 = 0, octet3 = 0, octet4 = 0;
	unsigned char res1, res2, res3, res4;
	unsigned char broa1, broa2, broa3, broa4;
	int bits;
///Fonction peremettant d'identifier si l'adresse IP saisi par l'utilisateur est validé ou pas	
    valider(&a,&b,&c,&d);
///Nombre de bits pour personnaliser le masque de sous-réseau    
    printf("\nVeuillez taper le nombre de bits pour le masque de sous-réseau: ");
    scanf("%d", &bits);
///Vérification si le nombre de bits saisi par l'utilisateur est validé ou pas   
    if (bits < 1 || bits > 32) {
        printf("Nombre de bits invalide\n");
        return 1;
    }
///Fonction permettant de déterliner le masque de sous-reseau a paratir du bits     
    masque(bits,&octet1,&octet2,&octet3,&octet4);
///Fonction peremttant d'afficher l'adresse réseau    
    areseau(a,b,c,d,octet1,octet2,octet3,octet4,&res1,&res2,&res3,&res4);
///Fonction permettant d'afficher l'adresse de diffusion    
    adiffusion(octet1,octet2,octet3,octet4,res1,res2,res3,res4,&broa1,&broa2,&broa3,&broa4);
///Fonction permettant de calculer le nombre d'hotes pour chaque sosu-réseau d'une adresse IP    
    nombremachine(bits);
///Fonction permettant de calculer le nombre de réseau possibles
    nombrereseau(a,bits);
return 0;
}

void valider(int *a, int *b, int *c,int *d){
	int valide = 0; // Variable pour contrôler la boucle
 // Boucle jusqu'à ce qu'une adresse IP valide soit saisie
    while (!valide) {
        printf("Veuillez taper votre adresse IP (format: x.x.x.x): ");
        scanf("%d.%d.%d.%d", a, b, c, d);
    if (*a > 255 || *b > 255 || *c > 255 || *d > 255) {
        printf("Adresse IP invalide\n");
    }  else {
		valide=1;
        affichage(*a,*b,*c,*d);
    }
}
}
void affichage(int a, int b, int c, int d){
	if (a < 128) {
        printf("\tClasse A: Par défaut: le masque de sous-reseau(MSQR) est: 255.0.0.0\n");
    } else if (a >= 128 && a < 192) {
        printf("\tClasse B:Par defaut: le masque de sous-reseau(MSQR) est: 255.255.0.0\n");
    } else if (a >= 192 && a < 224){
        printf("\tClasse C: Par defaut le masque de sous-reseau(MSQR) est: 255.255.255.0\n");
    } else if (a >= 224 && a < 240) {
        printf("Classe D:Utilisée pour le multicast\n");
    } else if (a >= 240 && a < 256) {
        printf("Classe E:Réserver à des fins futures ou expérimentales\n");
    }
}	
void masque(int bits, unsigned char *octet1, unsigned char *octet2, unsigned char *octet3, unsigned char *octet4) {
    *octet1 = *octet2 = *octet3 = *octet4 = 0;  // Initialisation des octets à 0

    // Calculer les octets du masque en fonction du nombre de bits
     int original_bits = bits;
    if (bits >= 24) {
        *octet1 = 255;
        *octet2 = 255;
        *octet3 = 255;
        bits -= 24;
    } else if (bits >= 16) {
        *octet1 = 255;
        *octet2 = 255;
        bits -= 16;
    } else if (bits >= 8) {
        *octet1 = 255;
        bits -= 8;
    }

    // Pour les bits restants, calculer le masque du dernier octet
    if (bits > 0) {
		 unsigned char dernier_octet = 255 << (8 - bits);
        if (*octet2 == 0) {
            *octet2 = dernier_octet;
        } else if (*octet3 == 0) {
            *octet3 = dernier_octet;
        } else {
            *octet4 = dernier_octet;
        }
    }
    printf("Masque de sous-réseau personnalisé avec %d bits :\n",  original_bits);
    printf("\n");
    printf("Masque de sous-reseau en decimale: ");
    printf("%d.%d.%d.%d\n", *octet1, *octet2, *octet3, *octet4);
}
void areseau(int a, int b, int c, int d,unsigned char octet1, unsigned char octet2, unsigned char octet3, unsigned char octet4,
unsigned char *res1, unsigned char *res2, unsigned char *res3, unsigned char *res4){
//Utilisation du AND & binaire pour la determination du l'adresse réseau 	
   *res1=a & octet1;
   *res2=b & octet2;
   *res3=c & octet3;
   *res4=d & octet4;
   printf("Adresse réseau correspondante est: %d.%d.%d.%d\n", *res1, *res2,*res3, *res4);
}  
void adiffusion(unsigned char octet1, unsigned char octet2, unsigned char octet3, unsigned char octet4, unsigned char res1, 
unsigned char res2, unsigned char res3, unsigned char res4, unsigned char *broa1, unsigned char *broa2, unsigned char *broa3,
unsigned char *broa4){
//~ inversion du masque de sous-réseau permettant de récupérer les bits qui seront utilisés pour determiner l'adresse de diffusion
//| est une opération OR binaire entre chaque octet de l'adresse IP	
	*broa1 = res1 | ~octet1;
    *broa2 = res2 | ~octet2;
    *broa3 = res3 | ~octet3;
    *broa4 = res4 | ~octet4;
    printf("L'adresse de diffusion correspondante est %d.%d.%d.%d\n", *broa1, *broa2, *broa3, *broa4);
}
void nombremachine(int bits){
	    int b=32-bits;
        int resultat=(int)pow(2,b);
        int a=resultat-2;
        printf("%d machines utilisables pour chaque sous-réseau\n", a);
}
void nombrereseau(int a,int bits){
	int n=0;
//Avec le masque personnalisé,le nombre de réseau doit etre en fonction du nombre de bits su réseau pour chaque classe	
	if (a < 128) {
		n=bits-8;
        int resultat=(int)pow(2,n);
        printf("%d nombre de réseau possibles\n", resultat);
    } else if (a >= 128 && a < 192) {
        n=bits-16;
        int resultat=(int)pow(2,n);
        printf("%d nombre de réseau possibles\n", resultat);
    } else if (a >= 192 && a < 224){
        n=bits-24;
        int resultat=(int)pow(2,n);
        printf("%d nombre de réseau possibles\n", resultat);
   }
}

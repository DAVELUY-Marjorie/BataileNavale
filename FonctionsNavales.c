#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioNavale.h"

struct coordonnees{
	char sens;
	int ligne;
	int colonne;
};
typedef struct coordonnees coordonnees;
/*
verif vérifie que le tableau tab contient bien les navires demandés
résultat : renvoie l'entier 1 si tab contient exactement 17 cases ne contenant pas un espace
		   renvoie 0 sinon.
*/
int verif(char tab[][10]){
    int nb_case = 0;
    int i, j;
    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            if (tab[i][j] != ' '){
                nb_case += 1;
            }
        }
    }
    if (nb_case != 17){
     return 1;
    }else{
     return 0;
    }
}
/*
affiche permet d'afficher sur la sortie standard le tableau t, sous forme de grille de bataille navale.
retour : vide
*/
void affiche(char t[][10]){
    int i, j;
    char lettre[10]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    printf ( "_|0|1|2|3|4|5|6|7|8|9|\n" );
    for (i=0; i<10; i++){
             printf("%c|", lettre[i]);
            for (j=0; j<10; j++){
                // Affiche chaque ligne
                printf("%c|",t[i][j]);
            }
            // Affichage fin du tableau et retour à la ligne
        printf("\n");
    }
  printf("\n");  
}
/*
afficheduo permet d'afficher côte à côte les tableaux t et p, sous forme de grilles de bataille navale.
retour : vide
*/
void afficheduo( char t[][10],char p[][10]){
    int i, j;
    char lettre[10]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    printf ( "_|0|1|2|3|4|5|6|7|8|9|          _|0|1|2|3|4|5|6|7|8|9|\n" );
    for (i=0; i<10; i++){
             printf("%c|", lettre[i]);
            for (j=0; j<10; j++){
                // Affiche chaque ligne
                if ((t[i][j]=='.') || (t[i][j]=='x') || (t[i][j]==' ')){
                	printf("%c|",t[i][j]);
                }else{
                	printf(" |");
                }
            }
            // Affichage 2ème tableau sur la même ligne
            printf("          %c|", lettre[i]);
            for (j=0; j<10; j++){
                // Affiche chaque ligne
                if ((p[i][j]=='.') || (p[i][j]=='x')){
                	printf("%c|",p[i][j]);
                }else{
                	printf(" |");
                }
            }
            // Affichage fin du tableau et retour à la ligne
        printf("\n");
    }
  printf("\n");  
}
/*navire renvoie une chaîne de caractères correspondant à Navire, selon l'entier entré :
résultat : selon l'entier i donné en argument, navire renvoie :
			Porte-Avion si i=1
			Croiseur	si i=2
			Sous-Marin	si i=3
			Mous-Sarin	si i=4*/
char* navire(int i){
char* s=" ";
 switch(i){
     case 0:
        s = "Porte-Avion";
        break;
     case 1:
        s = "Croiseur";
        break;
     case 2:
        s = "Sous-Marin";
        break;
     case 3:
        return "Mous-Sarin";
        break;
     case 4:
        s = "Torpilleur";
        break;
     default:
        break;
 }
 return s;
}

//La fonction vérifie si un bateau peut être placé ou pas (si il n'y a pas un autre bateau de présent où s'il va dépasser le plateau)
int isBateauPlacable(char plat[][10],coordonnees x,int taille_bateau, char MA){ 
    for (int i=0;i<taille_bateau;i++){
        if(x.sens=='v'){
            if(plat[x.ligne+i][x.colonne]!=' '){
            	if(MA =='M'){
                	printf("Navire empiete sur un autre.\n");
            	}
                return 1;
            }
            if((x.ligne+taille_bateau)>10){
                printf("Navire sortant des limites.\n");
                return 1;
            }
        }
		if(x.sens=='h'){
            if(plat[x.ligne][x.colonne+i]!=' '){
            	if(MA =='M'){
                	printf("Navire empiete sur un autre.\n");
            	}
                return 1;
            }
            if((x.colonne+taille_bateau)>10){
                printf("Navire sortant des limites.\n");
                return 1;
            }
        }
	}
return 0;
}
// Fonction plaçant les bateaux
void placerBateau(char plat[][10], coordonnees x, int taille, char lettre){
	int j=0;
	for(j=0; j<taille; j++){
		if (x.sens == 'h'){
			plat[x.ligne][x.colonne+j]= lettre;
		}else{
			plat[x.ligne+j][x.colonne]= lettre;
		}				
	}		
}
// Fonction d'assignation aléatoire de valeur pour les bateaux
void ajoutNavireAleatoire(char tab[][10],char b,int t){
	coordonnees x;
	// Sens aléatoire suivant si rand est paire ou non
	do{
		if(rand()%2 == 0){
			x.sens='h';
			x.ligne=(rand()%10);
			x.colonne=(rand()%(10-t));
		}else{
			x.sens='v';
			x.ligne=(rand()%(10-t));
			x.colonne=(rand()%10);
		}
	}while(isBateauPlacable(tab, x, t, 'A'));
	placerBateau(tab, x, t, b);	
}
void viderBuffer(void){
  int c;
  while((c=getchar()) != EOF && c != '\n');
}
// Fonction d'initalisation du plateau
void initPlateau(char plat[][10]){
	coordonnees x;
	char reponse=' ';
	char ligne=' ';
	char lettre [5]={'A', 'C', 'S', 'M', 'T'};
	int taille [5]={5,4,3,3,2};
	int i, j;
	int validite=0;
	// vide le plateau
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			plat[i][j]=' ';
		}
	}
	// Initialisation des valeurs du plateau de départ (toutes les cases sont un espace)
	while((reponse != 'M') && (reponse  != 'A')){
		printf("Souhaitez-vous placer vos navires à la (M)ain, ou (A)leatoirement ?\n");
		scanf("%c",&reponse);
		viderBuffer();
	}
	// Rempli le plateau jusqu'a ce que ce soit bien fait
	do{
		// Cas remplissage Manuel
		if(reponse == 'M'){
			printf("Vous devez placer vos navires.\n");
			printf("Pour chaque navire, indiquez horizontal (h) ou vertical (v), suivi de la case la plus au nord-ouest (ex : h,E4).\n");
			for (i=0; i < 5; i++){
				// Boucle de saisie jusqu'à bonne valeure
				do{
					validite=0;
                    affiche(plat);
                    printf("Placez votre %s \"%c\" (longueur %d) : \n", navire(i), lettre[i], taille[i]);
					scanf("%c,%c%d",&x.sens, &ligne,&x.colonne);
					viderBuffer();
					x.ligne = ligne-65;
					// Transformation de char ligne en int ligne (cf ASCII)
					if ((x.ligne >10) || (x.ligne <0) || (x.colonne >10) || (x.colonne < 0) ){
                        printf("Navire sortant des limites. \n");
                         validite=1;
                    }
                    if ((x.sens != 'h') && (x.sens != 'v')){
                    	printf("Navire sortant des limites. \n");
                        validite=1;
                    }
				}while (validite || (isBateauPlacable(plat, x, taille [i], 'M') != 0));
				// Place le bateau si coordonnees valides
				placerBateau(plat, x, taille[i], lettre[i]);
			    }
			    affiche(plat);
	    }// Cas remplissage auto
	    if (reponse=='A'){
			for (i=0; i < 5; i++){
				ajoutNavireAleatoire(plat,lettre[i],taille[i]);
			}
		}
	}while (verif(plat));
}
// Fonction verifiant les cases selectionnées
int jouerJoueur(char adv[][10]){
	char x;
	int y;
	scanf("%c%d",&x,&y);
	viderBuffer();
	int z=x-65;
	int s = 0;
	if(z<0 || z>9 || y<0 || y>9){
		s = -3;
	}else{
		switch (adv[z][y]){
		 case 'A':
			adv[z][y]='x';
			s = 0;
			break;
		 case 'C':
			adv[z][y]='x';
			s = 1;
			break;
		 case 'S':
			adv[z][y]='x';
			s = 2;
			break;
		 case 'M':
			adv[z][y]='x';
			s = 3;
			break;
		 case 'T':
			adv[z][y]='x';
			s = 4;
			break;
		 case ' ':
			adv[z][y]='.';
			s = -1;	 
			break;
		 case 'x':
			adv[z][y]='x';
			s = -4;	 
			break;
		 default:
			s = -2;
			break;
		}
	}
 return s;
}

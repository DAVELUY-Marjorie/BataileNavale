#include <stdio.h>
#include <stdlib.h>
#include "biblioNavale.h"

int navirecoule (int coup,int tour,int coule[2][5]){
int taillenavire[5]={4,3,2,2,1};  //Un tableau qui répertorie toutes les tailles-1 des navires dans l'ordre des valeurs renvoyées par jouerjoueur()
int Augmentation=0;				  //La variable permet de renvoyer 1 si un navire est touché et 0 dans le cas contraire
		if(coup >= 0 && coup <= 4){
			printf("Touché !\n");
			Augmentation++;
			if (coule[tour][coup]==taillenavire[coup]){
			printf("Le %s ennemi est coulé\n",navire(coup));
			}else{
				coule[tour][coup]++;
			}
		}else{
			printf("Petite erreur...\n");
		}
					return Augmentation;  //Renvoie la valeur de la variable pour incrémenter toucheJ1 ou toucheJ2
					}
int main (void){
/*Initialisation du plateau et des variables :*/
	char j1[10][10];
	char j2[10][10];
	int coule[2][5]={{0}}; //compte le nombre de coup jusqu'a ce qu'un bateau coule
	int coup=0; //décide si le coup est reussi(si oui,il dit quel type de navire est touché) ou raté
	int tour=1; //Décide de à qui est le tour (1 pour joueur 1 et 2 pour joueur 2)
	int toucheJ1=0; //compte le nombre de coups touchés depuis le début pour le joueur 1
	int toucheJ2=0; //compte le nombre de coups touchés depuis le début pour le joueur 2
	printf("Joueur 1 : \n");
	initPlateau(j1); // initialisation du plateau de jeu du joueur 1
	printf("Joueur 2 : \n");
	initPlateau(j2);  // initialisation du plateau de jeu du joueur 2
	afficheduo(j1,j2);
	while(toucheJ1<17&&toucheJ2<17){      /*Boucle de jeu jusqu'à ce qu'il y est un gagnant*/ 
		while(tour == 1){                 /*Boucle de jeu du Joueur1*/
			if (toucheJ1==17){            /*Test de la condition pour que le joueur1 gagne(Il faut qu'il ait touché 17 fois un navire)*/
				printf("Bravo !!! \nLe joueur 1 a gagné !!!\n");
				tour=0;                   /*Mise a 0 de tour pour sortir des boucles de jeu des joueurs*/
			}else{
			printf("Le Joueur 1 joue. \n");
			coup=jouerJoueur(j2);
			if(coup == -1){              /*Si le coup est a l'eau(coup==-1) , la main passe au Joueur2 (donc tour=2)*/
				printf("A l'eau !\n");
				afficheduo(j1,j2);
				tour = 2;
			}else{
				if((coup >= 0 && coup <= 4 && toucheJ1 < 17) || coup == -2||coup == -3){   /*On regarde si l'on est dans un cas permettant de rejouer.Sinon,la main passe au joueur 2*/
				toucheJ1=toucheJ1+navirecoule(coup,tour-1,coule);        /*On incremente toucheJ1 avec la valeur renvoyée de navirecoule (Augmentation), on met tour-1 pour que le tour soit 0 ou 1 et corresponde aux indices du tableau coule*/
				afficheduo(j1,j2);
				}else{
						tour = 2;
					}
				}
			}
		}/*Fin du while du joueur 2*/
		while(tour == 2){                 /*Boucle de jeu du Joueur2*/
			if (toucheJ2==17){            /*Test de la condition pour que le joueur2 gagne(Il faut qu'il ait touché 17 fois un navire)*/
				printf("Bravo !!! \nLe joueur 2 a gagné !!!\n");
				tour=0;                   /*Mise a 0 de tour pour sortir des boucles de jeu des joueurs*/
			}else{
			printf("Le Joueur 2 joue. \n");
			coup=jouerJoueur(j1);
			if(coup == -1){              /*Si le coup est a l'eau(coup==-1) , la main passe au Joueur1 (donc tour=1)*/
				printf("A l'eau !\n");
				afficheduo(j1,j2);
				tour = 1;
			}else{
					if((coup >= 0 && coup <= 4 && toucheJ2 < 17) || (coup == -2||coup == -3)){   /*On regarde si l'on est dans un cas permettant de rejouer.Sinon,la main passe au joueur 1*/
						toucheJ2=toucheJ2+navirecoule(coup,tour-1,coule);     /*On incremente toucheJ2 avec la valeur renvoyée de navirecoule (Augmentation), on met tour-1 pour que le tour soit 0 ou 1 et corresponde aux indices du tableau coule*/               
						afficheduo(j1,j2);
					}else{
						tour = 1;
					}
				}
			}
		}/*Fin du while du joueur 2*/
    } /*Fin du while de tout le jeu*/
return 0;
}	

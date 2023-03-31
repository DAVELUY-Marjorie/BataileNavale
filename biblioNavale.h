

/*
ajoutNavireAleatoire permet d'ajouter au tableau tab un Navire de taille t, et représenté par le caractère b.

résultat : t cases consécutives de tab reçoivent le caractère b.

fonctionnement : 
La fonction choisit aléatoirement si le navire sera horizontal ou vertical,
puis en fonction de cela choisit aléatoirement la position de façon à ce que le navire ne dépasse pas du tableau.
retour : vide
*/
void ajoutNavireAleatoire(char tab[][10],char b,int t);



/*
verif vérifie que le tableau tab contient bien les navires demandés

résultat : renvoie l'entier 1 si tab contient exactement 17 cases ne contenant pas un espace
		   renvoie 0 sinon.
*/
int verif(char tab[][10]);


/*
affiche permet d'afficher sur la sortie standard le tableau t, sous forme de grille de bataille navale.
retour : vide
*/
void affiche(char t[][10]);


/*
afficheduo permet d'afficher côte à côte les tableaux t et p, sous forme de grilles de bataille navale.
retour : vide
*/
void afficheduo(char t[][10],char p[][10]);


/*
initPlateau permet à un joueur d'initialiser le tableau plat, en y plaçant ses navires.

résultat : A la fin de la fonction, le tableau plat contient les 5 navires de la bataille navale, placés selon les règles.  

retour : vide

fonctionnement :
Le joueur peut placer ses navires de deux façons : 
	- Aléatoirement, auquel cas la fonction appelle ajoutNavireAléatoire de façon adaptée afin d'obtenir le résultat.
	- A la main, auquel cas le joueur doit dire si son navire est horizontal ou vertical, 
	  et donner la coordonnée la plus nord-ouest. Si l'utilisateur place mal son Navire, il lui est demandé de le replacer.
*/
void initPlateau(char plat[][10]);


/*
joueurJoueur permet à un joueur de jouer sur le tableau adv.

résultat : L'utilisateur entre des coordonnées, le tableau est modifié pour indiquer s'il le coup est "à l'eau" ou "touche"
			retourne un entier, correspondant au Navire touché :
					-1 si le coup est à l'eau
					 0 si le coup touche le Porte-Avion
					 1 si le coup touche le Croiseur
					 2 si le coup touche le Sous-Marin
					 3 si le coup touche le Mous-Sarin
					 4 si le coup touche le Torpilleur
					-2 si la case contient un caractère non reconnu (ne devrait pas arriver)
					-3 si le coup est hors plateau
*/
int jouerJoueur(char adv[][10]);

/*
navire renvoie une chaîne de caractères correspondant à Navire, selon l'entier entré :
résultat : selon l'entier i donnée en argument, navire renvoie :
			Porte-Avion si i=1
			Croiseur	si i=2
			Sous-Marin	si i=3
			Mous-Sarin	si i=4
*/
char* navire(int i);
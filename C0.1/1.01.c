#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996 6031)

enum { MAX_ETUDIANTS = 100, NOM_MAX = 31, MAX_CARACTERES_ABSENCES = 50, INPUTMAX = 100 };

typedef struct {
	int id, jour;
	char dj[2];
} Absence;

typedef struct {
	char nom[NOM_MAX];
	int groupe;
	Absence absences[];
} Etudiant;


Etudiant etudiants[MAX_ETUDIANTS];
Absence absences[];
int compteur_etudiants = 1;

void inscription(char nom[NOM_MAX], int groupe) {
	//Vérification de l'unicité
	for (int i = 0; i < compteur_etudiants; ++i) 
	{
		if (strcmp(etudiants[i].nom, nom) == 0 && etudiants[i].groupe == groupe) 
		{
			printf("Nom incorrect\n");
			return;
		}
	}

	//Inscription de l'étudiant
	if (compteur_etudiants < MAX_ETUDIANTS) {
		strcpy(etudiants[compteur_etudiants].nom, nom);
		etudiants[compteur_etudiants].groupe = groupe;
		printf("Inscription enregistree (%d)\n", compteur_etudiants);
		/*printf("%s %d \n", etudiants[compteur_etudiants].nom, etudiants[compteur_etudiants].groupe);*/
		compteur_etudiants++;
	}
	else {
		printf("Nombre maximum d'étudiants atteint...\n");
	}
}

void absence(int id, int jour, char dj[2])
{
	//Vérifications
	if (id>compteur_etudiants)
	{
		printf("Identifiant incorrect");
	}
	else if (jour < 0 || jour>40)
	{
		printf("Date incorrecte");
	}
	else if (strcmp(dj[], "am")!=0 || strcmp(dj[], "pm")!=0)
	{
		printf("Demi-journee incorrecte");
	}
	for (int i = 0; i<compteur_etudiants; ++i)
	{
		if (strcmp())
	}
}

int main() {
	char commande[INPUTMAX];
	char nom[NOM_MAX];
	int groupe;
	int id, jour;
	char dj[2];
	do
	{
		scanf("%s", commande);

		//Inscription - C1
		if (strcmp(commande, "inscription") == 0)
		{
			scanf("%s %d", nom, &groupe);
			inscription(nom, groupe);
		}

		//Absence - C2
		if (strcmp(commande, "absence") == 0)
		{
			scanf("%d %s", &id, &jour, dj);
			absence(id, jour, dj);
		}

	} while (strcmp(commande, "exit") != 0);

	printf("\n");
	printf("+---------- Arret du programme ----------+");
	printf("\n");
}
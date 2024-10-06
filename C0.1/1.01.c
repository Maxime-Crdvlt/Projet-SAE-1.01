#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996 6031)

enum { MAX_ETUDIANTS = 100, NOM_MAX = 31, INPUTMAX = 100 };
enum { MAX_CARACTERES_ABSENCES = 50, MAX_ABSENCES = 100, MAX_CARACTERES_DMJ = 3, MAX_JOURS = 40 };

typedef struct {
	char nom[NOM_MAX];
	int groupe;
	int id;
} Etudiant;

typedef struct {
	int id;
	int jour;
	char dj[MAX_CARACTERES_DMJ];
	char etat[100];
} Absence;

// Enregistrement des étudiants
Etudiant etudiants[MAX_ETUDIANTS];
int compteur_etudiants = 1;

//Enregistrement des absences
Absence absences[MAX_ABSENCES];
int compteur_absences = 1;

void inscription(char nom[NOM_MAX], int groupe) {
	//Vérifications
	int verifnom = strlen(nom);
	if  (verifnom> NOM_MAX-1)
	{
		printf("Nom incorrect \n");
		return;
	}
	//Vérification de l'unicité
	for (int i = 0; i < compteur_etudiants; ++i) 
	{
		if (strcmp(etudiants[i].nom, nom) == 0 && etudiants[i].groupe == groupe) 
		{
			printf("Nom incorrect\n");
			return;
		}
	}

	//Enregistrement de l'étudiant
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

void absence(int id, int jour, char dj[MAX_CARACTERES_DMJ])
{
	//Vérifications
	if (id>compteur_etudiants)
	{
		printf("Identifiant incorrect\n");
		return;
	}
	if (jour <= 0 || jour > 40)
	{
		printf("Date incorrecte\n");
		return;
	}
	if (strcmp(dj, "am")!=0 && strcmp(dj, "pm")!=0)
	{
		printf("Demi-journee incorrecte\n");
		return;
	}
	//Vérification de l'unicité
	for (int i = 0; i < compteur_absences; i++) 
	{
		if (strcmp(absences[i].dj, dj) == 0 && absences[i].jour == jour)
		{
			printf("Absence deja connue\n");
			return;
		}
	}

	//Enregistrement de l'absence
	if (compteur_etudiants < MAX_ETUDIANTS) {
		absences[compteur_absences].id = id;
		absences[compteur_absences].jour = jour;
		strcpy(absences[compteur_absences].dj, dj);
		printf("Absence enregistree (%d)\n", compteur_absences);
		printf("%d %d %s \n", absences[compteur_absences].id, absences[compteur_absences].jour, absences[compteur_absences].dj);
		compteur_absences++;
	}
	else {
		printf("Nombre maximum d'absences atteint...\n");
	}
}

int main() {
	char commande[INPUTMAX];
	char nom[NOM_MAX];
	int groupe;
	int id, jour;
	char dj[MAX_CARACTERES_DMJ];
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
			scanf("%d %d %s", &id, &jour, dj);
			absence(id, jour, dj);
		}

		else
		{
			printf("Commande invalide...\n");
		}
	} while (strcmp(commande, "exit") != 0);

	printf("\n");
	printf("+---------- Arret du programme ----------+");
	printf("\n");
}
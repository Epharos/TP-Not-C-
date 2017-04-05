#include <string.h>
#include <iostream>
#include "Strings.h"

using namespace std;

// AURÉLIEN REY
// CERI - UAPV
// GROUPE 3
// L1 INFORMATIQUE

int main()
{
	cout << "DÉBUT DU PROGRAMME DU TP NOTÉ" << endl << "AURÉLIEN REY" << endl << "GROUPE 3" << endl;
	cout << endl << "-------" << endl << endl;

	cout << "Question 1 : destructeur (message qui s'affiche au long du programme si nécessaire, en fin sinon)" << endl;

	cout << endl << "-------" << endl << endl;

	cout << "Question 2 : constructeur à 1 argument (exemple avec 100 caractères)" << endl;
	Strings s(100);

	cout << endl << "-------" << endl << endl;

	cout << "Question 3 : fonction qui vérifie si une chaîne est présente au moins n fois" << endl;
	Strings t(1000, 30);
	char w1[10] = "Java";
	char w2[10] = "Fortran";
	char w3[10] = "Python";

	t.add(w1);
	t.add(w2);
	t.add(w2);
	t.add(w1);
	t.add(w1);

	cout << endl;
	t.print();
	cout << endl;

	if(t.atLeastNTimes(w1, 1))
	{
		cout << "Le mot " << w1 << " est présent au moins une fois dans la collection" << endl;
	}
	else
	{
		cout << "Le mot " << w1 << " n'est pas présent dans la collection" << endl; 
	}

	if(t.atLeastNTimes(w2, 2))
	{
		cout << "Le mot " << w2 << " est présent au moins deux fois dans la collection" << endl;
	}
	else
	{
		cout << "Le mot " << w2 << " n'est pas présent ou n'est présent qu'une fois dans la collection" << endl; 
	}

	if(t.atLeastNTimes(w3, 1))
	{
		cout << "Le mot " << w3 << " est présent au moins une fois dans la collection" << endl;
	}
	else
	{
		cout << "Le mot " << w3 << " n'est pas présent dans la collection" << endl; 
	}

	cout << endl << "-------" << endl << endl;

	cout << "Si le programme n'a pas été modifié, " << w1 << " est dans la collection tandis que " << w3 << " n'y est pas" << endl;
	cout << "Question 4 : fonction qui ajoute un mot dans une collection s'il n'y est pas déjà" << endl;

	if(t.addRestricted(w1))
	{
		cout << "Le mot " << w1 << " a été ajouté avec succès" << endl;
	}
	else
	{
		cout << "Le mot " << w1 << " n'a pas pu être ajouté" << endl;
	}

	if(t.addRestricted(w3))
	{
		cout << "Le mot " << w3 << " a été ajouté avec succès" << endl;
	}
	else
	{
		cout << "Le mot " << w3 << " n'a pas pu être ajouté" << endl;
	}

	cout << endl;
	t.print();

	cout << endl << "-------" << endl << endl;

	cout << "Question 5 : ajout de l'opérateur \"=\" entre une ou plusieurs collection(s)" << endl;
	Strings u;
	cout << endl << "Affichage du nouvel objet avant opération" << endl << endl;
	u.print();
	u = t;
	cout << endl << "Affichage du nouvel objet après opération" << endl << endl;
	u.print();

	cout << endl << "-------" << endl << endl;

	cout << "Question 6 : ajout de l'opérateur \"<<\" qui ajoute un ou des chaîne(s) à une collection" << endl;
	cout << "Ajout de " << w2 << ", " << w3 << " et encore " << w2 << endl;

	t << w2 << w3 << w2;

	cout << endl;
	t.print();

	cout << endl << "-------" << endl << endl;

	cout << "Question 7 : intersection entre deux collections sans doublons" << endl;
	Strings v(1000, 30);
	char w4[15] = "Assembleur";

	v << w1 << w1 << w4 << w3 << w1;

	cout << "V : " << endl << endl;
	v.print();

	cout << endl << "Intersection entre T et V" << endl << endl;

	Strings w = t.intersect(v);

	w.print();

	cout << endl << "-------" << endl << endl;

	cout << "Question 8 : ajout de l'opérateur \"+=\" qui permet d'ajouter une collection à une autre (sauf si un élément est déjà présent)" << endl;
	cout << "T += V" << endl;
	t += v;
	t.print();

	cout << endl << "-------" << endl << endl;

	cout << "Questions 9 et 10 : fonction qui supprime les instances d'une chaîne au sein d'une collection et ajout des opérateurs \"-\" et \"-=\" correspondants" << endl;
	cout << "On peut ainsi écrire de trois manières : " << endl << "t.deleteString(s);" << endl << "t = t - s;" << endl << "t -= s;" << endl;
	cout << "On enlève " << w1 << " à T : " << endl;
	t -= w1;
	t.print();

	cout << endl << "-------" << endl << endl;

	cout << "Fin du programme et destructions des objets :" << endl;
}
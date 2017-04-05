#include "Strings.h"
#include <string.h>
#include <iostream>

// AURÉLIEN REY
// CERI - UAPV
// GROUPE 3
// L1 INFORMATIQUE

using namespace std;

// DONNÉ MAIS REFAIT
Strings::Strings() : tChar(new char[1]), tIndex(new char*[1]), maxChar(1), maxIndex(1), currentChar(0), currentIndex(0)
{
	cout << "Création d'un objet [" << this << "] par le constructeur par défaut (" << maxChar << " caractère dans " << maxIndex << " mot)" << endl;
}

// DONNÉ MAIS REFAIT
Strings::Strings(int mc, int mi) : maxChar(mc), maxIndex(mi), tChar(new char[mc]), tIndex(new char*[mi]), currentChar(0), currentIndex(0)
{
	cout << "Création d'un objet [" << this << "] par le constructeur avec paramètres (" << maxChar << " caractère(s) dans " << maxIndex << " mot(s))" << endl;
}

// QUESTION 2
Strings::Strings(int mc) : maxChar(mc), maxIndex(mc / 8 + 1), tChar(new char[mc]), tIndex(new char*[maxIndex]), currentChar(0), currentIndex(0)
{
	cout << "Création d'un objet [" << this << "] par le constructeur avec paramètre (" << maxChar << " caractère(s) dans " << maxIndex << " mot(s))" << endl;
}

// QUESTION 1
Strings::~Strings()
{
	cout << "Destruction d'un objet [" << this << "]" << endl;
	delete [] tChar;
	delete [] tIndex;
}

// DONNÉ MAIS REFAIT
bool Strings::add(char* s)
{
	if(strlen(s) > (maxChar - currentChar) || currentIndex >= maxIndex)
	{
		return false;
	}

	tIndex[currentIndex] = &(tChar[currentChar]);
	currentIndex++;

	for(int i = 0 ; i < strlen(s) ; i++)
	{
		tChar[currentChar] = s[i];
		currentChar++;
	}

	tChar[currentChar] = '\0';
	currentChar++;

	return true;
}

// NON DEMANDÉ
void Strings::print()
{
	for(int i = 0 ; i < currentIndex ; i++)
	{
		cout << tIndex[i] << endl;
	}
}

// QUESTION 3
bool Strings::atLeastNTimes(char* s, int n)
{
	int count = 0;

	for(int i = 0 ; i < currentIndex ; i++)
	{
		if(strcmp(tIndex[i], s) == 0)
		{
			count++;

			if(count >= n)
				return true;
		}
	}

	return false;
}

// QUESTION 4
bool Strings::addRestricted(char* s)
{
	if(atLeastNTimes(s, 1))
	{
		return false;
	}
	else
	{
		return add(s);
	}
}

// NON DEMANDÉ MAIS CONSEILLÉ PAR CONVENTION
int Strings::getMaxIndex()
{
	return maxIndex;
}

// NON DEMANDÉ MAIS CONSEILLÉ PAR CONVENTION
int Strings::getMaxChar()
{
	return maxChar;
}

// NON DEMANDÉ MAIS CONSEILLÉ PAR CONVENTION
int Strings::getCurrentChar()
{
	return currentChar;
}

// NON DEMANDÉ MAIS CONSEILLÉ PAR CONVENTION
int Strings::getCurrentIndex()
{
	return currentIndex;
}

// NON DEMANDÉ MAIS CONSEILLÉ PAR CONVENTION
char* Strings::getChars()
{
	return tChar;
}

// NON DEMANDÉ MAIS CONSEILLÉ PAR CONVENTION
char** Strings::getIndex()
{
	return tIndex;
}

// QUESTION 5
Strings & Strings::operator = (Strings & tc) // Censé être en const mais affichage d'une erreur "discards qualifiers" sur les fonctions getXXX() qui ne sont pas en const
{
	delete [] tIndex;
	delete [] tChar;

	currentChar = 0;
	currentIndex = 0;

	maxIndex = tc.getMaxIndex();
	maxChar = tc.getMaxChar();

	tIndex = new char*[maxIndex];
	tChar = new char[maxChar];

	for(int i = 0 ; i < tc.getCurrentIndex() ; i++)
	{
		add(tc.getIndex()[i]);
	}

	return (*this);
}

// QUESTION 6
Strings & Strings::operator << (char* s)
{
	add(s);
	return (*this);
}


// NON DEMANDÉ MAIS ELLE M'A ÉTÉ UTILE POUR UN DEBUG
void Strings::printAdresses()
{
	cout << tChar << endl;
	cout << tIndex << endl;
}

// QUESTION 7
Strings & Strings::intersect(Strings & ts)
{
	Strings* tmp = new Strings(currentChar + ts.getCurrentChar(), currentIndex + ts.getCurrentIndex());

	for(int i = 0 ; i < currentIndex ; i++)
	{
		if(ts.atLeastNTimes(tIndex[i], 1))
		{
			(*tmp).addRestricted(tIndex[i]);
		}
	}

	return (*tmp);
}

// QUESTION 8
Strings & Strings::operator += (Strings & ta)
{
	for(int i = 0 ; i < ta.getCurrentIndex() ; i++)
	{
		addRestricted(ta.getIndex()[i]);
	}

	return (*this);
}

// QUESTION 9
void Strings::deleteString(char* s)
{
	Strings tmp(maxChar, maxIndex);

	for(int i = 0 ; i < currentIndex ; i++)
	{
		if(strcmp(tIndex[i], s) != 0)
		{
			tmp.add(tIndex[i]);
		}
	}

	(*this) = tmp;
}

// QUESTION 10
Strings & Strings::operator - (char* s)
{
	Strings* tmp = new Strings(maxChar, maxIndex);

	for(int i = 0 ; i < currentIndex ; i++)
	{
		(*tmp).add(tIndex[i]);
	}

	(*tmp).deleteString(s);
	return (*tmp);
}

// QUESTION 10.1
Strings & Strings::operator -= (char* s)
{
	deleteString(s);
	return (*this);
}
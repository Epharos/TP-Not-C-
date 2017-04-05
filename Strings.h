// AURÉLIEN REY
// CERI - UAPV
// GROUPE 3
// L1 INFORMATIQUE

class Strings
{
	char* tChar;
	char** tIndex;

	int maxChar;
	int maxIndex;

	int currentChar;
	int currentIndex;

	public :
		// CONSTRUCTEURS ET DESTRUCTEUR
		Strings();
		Strings(int, int);
		Strings(int);
		~Strings();

		// FONCTIONS MEMBRES 
		bool add(char*);
		void print();
		bool atLeastNTimes(char*, int);
		bool addRestricted(char*);
		void printAdresses();
		Strings& intersect(Strings&);
		void deleteString(char*);

		// OPÉRATEURS
		Strings& operator = (Strings&);
		Strings& operator << (char*);
		Strings& operator += (Strings&);
		Strings& operator - (char*);
		Strings& operator -= (char*);

		// GETTER ET SETTER
		int getMaxChar();
		int getMaxIndex();
		int getCurrentIndex();
		int getCurrentChar();
		char* getChars();
		char** getIndex();
	private :
};
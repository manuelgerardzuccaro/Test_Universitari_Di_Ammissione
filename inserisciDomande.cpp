#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file("domande.txt", ios::app); // Apre il file in modalità append

    if (!file.is_open()) {
        cout << "Impossibile aprire il file domande.txt." << endl;
        return 1;
    }

    string testo_domanda="";
    string risposte[5];
    string risposta_corretta;

	while(testo_domanda.length()<1){
	    cout << "Inserisci il testo della domanda: ";
	    getline(cin, testo_domanda);
    }

    cout << "Inserisci le risposte (A, B, C, D, E):\n";
    for (int i = 0; i < 5; i++) {
        while(risposte[i].length()<1){
			cout << static_cast<char>('A' + i) << ") ";
        	getline(cin, risposte[i]);
        }
    }
    cout << "Inserisci la lettera della risposta corretta (in maiuscolo): ";
    cin >> risposta_corretta;
    while (risposta_corretta.length() > 1 || risposta_corretta[0] < 'A' || risposta_corretta[0] > 'E'){
    	cout << "Inserisci la lettera della risposta corretta (in MAIUSCOLO): ";
    	cin >> risposta_corretta;
	}

    // Scrive i dati nel file con la formattazione specificata
    file << endl << testo_domanda << endl;
    for (int i = 0; i < 5; i++) {
        file << static_cast<char>('A' + i) << ") " << risposte[i] << endl;
    }
    file << endl;
    file << risposta_corretta << endl;

    file.close();

    cout << "Domanda e risposte sono state aggiunte al file con successo." << endl;

    return 0;
}


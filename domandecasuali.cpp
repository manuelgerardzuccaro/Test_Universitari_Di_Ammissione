/*
Il file "domande.txt" deve avere questa formattazione:

Testo_domanda
A)Risposta_1
B)Risposta_2
C)Risposta_3
D)Risposta_4
E)Risposta_5

LETTERA_RISPOSTA_CORRETTA_MAIUSCOLA

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Struttura per memorizzare una domanda
struct Domanda {
    string testo;
    vector<string> risposte;
    char soluzione;
};

vector<Domanda> domande; // Vettore per memorizzare tutte le domande


string seleziona_test(){
	string test;
    cout<< "In quale test ti vuoi esercitare?" << endl;
    cout<< "	1) Biologia" << endl;
    cout<< "	2) Chimica" << endl;
    cout<< "	3) Matematica e fisica" << endl;
    cout<< "	4) Tutti insieme" << endl;
    cin>>test;
    while(test.length()>1 || test[0]<'1' && test[0]>'4' ){
    	cout<< "Inserisci il numero CORRETTO del test che vuoi selezionare " <<endl;
    	cin>>test;
	}
	int case_test = atoi(test.c_str());
    switch(case_test){
    	case 1:
    		return "biologia.txt";
    	case 2:
    		return "chimica.txt";
    	case 3:
    		return "matematica_e_fisica.txt";
	}
	return "domande.txt";
}

// Funzione per leggere le domande da un file
void leggi_file(string filestringa) {
    ifstream file(filestringa.c_str());
    if (!file.is_open()) {
        cout << "Impossibile aprire il file " << filestringa << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            Domanda domanda;
            domanda.testo = line;
            for (int i = 0; i < 5; i++) {
                getline(file, line);
                domanda.risposte.push_back(line);
            }
            getline(file, line); // Per lo spazio presente tra le domande e la risposta
            getline(file, line);
            domanda.soluzione = line[0];
            domande.push_back(domanda);
        }
    }
    file.close();
}

// Funzione per gestire il menu principale
void menu_principale() {
    char scelta;
    vector<int> domandeMostrate;

    while (domandeMostrate.size() < domande.size()) {
        system("cls");
        cout << "Menu:\n";
        cout << "1. Visualizza domanda\n";
        cout << "2. Esci\n";
        cout << "Scegli un'opzione (1/2): ";
        cin >> scelta;

        if (scelta == '1') {
            system("cls");
            int indiceCasuale;
            do {
                indiceCasuale = rand() % domande.size();
            } while (find(domandeMostrate.begin(), domandeMostrate.end(), indiceCasuale) != domandeMostrate.end());

            domandeMostrate.push_back(indiceCasuale);
            cout << "Domanda: " << domande[indiceCasuale].testo << endl;
            cout << "Risposte:\n";
            for (int i = 0; i < 5; i++) {
                cout << "   " << domande[indiceCasuale].risposte[i] << endl;
            }
            cout << endl;
            string rispSol;
            cout << "Risposta (in MAIUSCOLO): ";
            cin >> rispSol;
            while (rispSol.length() > 1 || rispSol[0] < 'A' || rispSol[0] > 'E') {
                cout << "Inserisci una risposta valida (in MAIUSCOLO!!): ";
                cin >> rispSol;
            }
            if (rispSol[0] == domande[indiceCasuale].soluzione)
                cout << "Risposta CORRETTA !!" << endl;
            else
                cout << "Risposta SBAGLIATA.\nLa soluzione e': " << domande[indiceCasuale].soluzione << endl;
            system("pause");
        } else if (scelta == '2') {
            system("cls");
            cout << "Grazie per aver usato il programma. I lov u!" << endl;
            system("pause");
            break;
        } else {
            system("cls");
            cout << "Scelta non valida. Per favore, inserisci 1 o 2." << endl;
            system("pause");
        }
    }
}

int main() {
    srand(time(NULL)); // Inizializza il generatore di numeri casuali
    leggi_file(seleziona_test()); // Leggi le domande dal file
    menu_principale(); // Esegui il menu principale
    return 0;
}


#include <iostream>
#include <fstream> // Libreria per i file
#include <string>  // Libreria per fare operazioni sulle stringhe

const std::string NomeSave = "prova.txt";

struct giocatore
{
    std::string nome;
    int livello = 1;
};

void saveHandler(const giocatore &g); // Funzione principale per gestire i salvataggi
void pulisciSchermo();
void saveLoader();
bool isFileEmpty(const std::string& NomeSave); // Controlla se il salvataggio è vuoto

int main()
{
    giocatore giocatore;

    std::cout << "Inserisci il tuo nome, ma scegli bene, non potrai cambiarlo." << std::endl;
    getline(std::cin, giocatore.nome); // Permette nome con spazi

    saveHandler(giocatore); // Passo alla funzione la struttura giocatore
    saveLoader();

    return 0;
}

void saveHandler(const giocatore &g)
{
    // Spiegazione I/O con file qui: https://cplusplus.com/doc/tutorial/files/

    std::ofstream Salvataggio(NomeSave); // Crea e basta il file

    if (!Salvataggio)
    {
        std::cerr << "Errore durante l'apertura del file!" << std::endl;
        return;
    }
    Salvataggio << "Nome: " << g.nome << "\n"
                << "lvl: " << g.livello << "\n"; // Salva i dati dello struct, g = giocatore
    Salvataggio.close();
}

void saveLoader()
{
    std::ifstream Salvataggio(NomeSave);

    if (!Salvataggio) // Controlla se può aprire il salvataggio
    {
        std::cerr << "Errore durante l'apertura del file!" << std::endl;

        return;
    }

    giocatore g;

    std::string line;

    while (getline(Salvataggio, line))
    {
        // Funzione substr per cercare cosa c'è dopo il testo specificato
        // Ottima spiegazione qui: https://cplusplus.com/reference/string/string/substr/
        if (line.find("Nome: ") == 0)
        {
            g.nome = line.substr(6); // Estrae il nome, 6 è la posizione dall'inizio della stringa
        }
        else if (line.find("lvl: ") == 0)
        {
            g.livello = std::stoi(line.substr(5)); // Estrae il livello, stessa cosa per nome
        }
    }

    Salvataggio.close();
}

bool isFileEmpty(const std::string& NomeSave) {
    std::ifstream file(NomeSave);
    return file.peek() == std::ifstream::traits_type::eof();
}

void pulisciSchermo()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

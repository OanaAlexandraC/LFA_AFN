#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class AFN {
    int n; //numarul de stari ale automatului
    char *Q; //multimea de stari ale automatului
    int s; //numarul simbolurilor din alfabetul de intrare
    char *A; //alfabetul de intrare
    char stare; //starea initiala a automatului
    int nrt; //numar de tranzitii
    struct delta {
        char s1, s2, c;
    } *T; //tranzitii (din starea s1 in starea s2 prin simbolul c)
    int nf; //numarul de stari finale ale automatului
    char *F; //multimea starilor finale
public:
    explicit AFN(const char *fisier); //constructor AFN
    ~AFN(); //destructor AFN
    //void afisare();
    bool verificare(const char *cuvant);
};

/**
 * constructor
 * @param fisier (numele fisierului)
 */
AFN::AFN(const char *fisier)
{
    n = s = nrt = nf = 0;
    stare = 0;
    ifstream f(fisier); //deschidere fisier
    int i;
    f >> n; //citire numar de stari ale automatului
    Q = new char[n];
    for (i = 0; i < n; i++)
        f >> Q[i]; //citire multime de stari ale automatului
    f >> s; //citire numar de simboluri ale alfabetului de intrare
    A = new char[s];
    for (i = 0; i < s; i++)
        f >> A[i]; //citire alfabet de intrare
    f >> stare; //citire stare initiala
    f >> nrt; //citire numar de tranzitii
    T = new delta[nrt];
    for (i = 0; i < nrt; i++)
        f >> T[i].s1 >> T[i].c >> T[i].s2; //citire tranzitii
    f >> nf; //citire numar de stari finale ale automatului
    F = new char[nf];
    for (i = 0; i < nf; i++)
        f >> F[i]; //citire multime de stari finale ale automatului
    f.close();
}

/**
 * destructor
 */
AFN::~AFN() {
    delete[] Q;
    delete[] A;
    delete[] T;
    delete[] F;
}

/**
 * afisarea informatiilor citite despre un AFN
 */
/*void AFN::afisare()
{
    int i;
    cout << n << '\n';
    for (i = 0; i < n; i++)
        cout << Q[i] << ' '; //afisare multime de stari ale automatului
    cout << '\n' << s << '\n';
    for (i = 0; i < s; i++)
        cout << A[i] << ' '; //afisare alfabet de intrare
    cout << '\n' << stare << '\n' << nrt << '\n';
    for (i = 0; i < nrt; i++)
        cout << T[i].s1 << ' ' << T[i].c << ' ' << T[i].s2 << '\n'; //afisare tranzitii
    cout << nf << '\n';
    for (i = 0; i < nf; i++)
        cout << F[i] << ' '; //afisare multime de stari finale
}*/

/**
 * @param cuvant
 * @return true in cazul in care cuvant apartine limbajului recunoscut de automat si false in caz contrar
 */
bool AFN::verificare(const char *cuvant) {
    int i;
    char stareaux = stare;
    if (!cuvant[0]) //am ajuns la sfarsitul cuvantului
    {
        for (i = 0; i < nf; i++)
            if (stare == F[i]) //daca starea in care am ajuns este una dintre cele finale
                return true;
        return false; //daca starea in care am ajuns nu este finala
    }
    for (i = 0; i < nrt; i++)
        if ((T[i].s1 == stareaux) && (T[i].c == cuvant[0]))
            //caut tranzitiile in care starea s1 este starea in care ma aflu,
            //iar caracterul c este simbolul din cuvant la care am ajuns
        {
            stare = T[i].s2; //starea curenta este acum s2
            if (verificare(cuvant + 1)) return true; //si trec la caracterul urmator
        }
    return false;
}

/**
 * afiseaza pe ecran daca un cuvant apartine sau nu limbajului recunoscut de un automat
 */
void cuvant() {
    AFN x("date.txt");
    char cuvant[101];
    cin >> cuvant; //citire cuvant
    if (strcmp(cuvant, "_") == 0)
        //daca avem cuvantul vid
        cuvant[0] = NULL;
    if (x.verificare(cuvant))
        //daca metoda verify returneaza true
        cout << "Cuvantul apartine limbajului recunoscut de automat.";
    else cout << "Cuvantul nu apartine limbajului recunoscut de automat.";
    cout << '\n';
}

int main() {
    cuvant();
    return 0;
}
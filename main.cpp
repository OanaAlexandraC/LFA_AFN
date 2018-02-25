#include <iostream>
#include <fstream>

using namespace std;

class AFN {
    int n; //numarul de stari ale automatului
    char *Q; //multimea de stari ale automatului
    int s; //numarul simbolurilor din alfabetul de intrare
    char *A; //alfabetul de intrare
    char stare; //starea initiala a alfabetului
    int nrt; //numar de tranzitii
    struct delta {
        char s1, s2, c;
    } *T; //tranzitii (din starea s1 in starea s2 prin simbolul c)
    int nf; //numarul de stari finale ale automatului
    char *F; //multimea starilor finale
public:
    explicit AFN(const char *fisier); //constructor AFN
};

AFN::AFN(const char *fisier) {
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

int main() {
    AFN x("date.txt"); //declarare automat
    return 0;
}
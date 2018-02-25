#include <iostream>

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
};

int main() {
    cout << "Hello, World!";
    return 0;
}
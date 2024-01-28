#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

#include "rat.h"

using namespace std;

int main()
{
    cout << "----- Tests automatiques -----------------------------------------------" << endl;
    if (testConstructeurVideEtGetters()) cout << "Constructeur vide et getters ok" << endl;
    if (testsConstructeurParamEtGetters()) cout << "Constructeur avec parametres et getters ok" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    cout << "----- Programme principal ----------------------------------------------" << endl;

    // Tests des opérateurs
    Rationnel r1(1, 2);
    Rationnel r2(2, 3);
    Rationnel r3;

    r3 = r1 * r2;
    cout << "Multiplication : " << r3 << endl;

    if (r1 == r2)
    {
        cout << "Les rationnels sont égaux." << endl;
    }
    else
    {
        cout << "Les rationnels ne sont pas égaux." << endl;
    }

    cout << "Affichage avec << : " << r1 << endl;

    Rationnel r4 = -r2;
    cout << "Négation : " << r4 << endl;

    Rationnel r5 = r1 + r2;
    cout << "Addition : " << r5 << endl;

    if (r1 < r2)
    {
        cout << "Le premier rationnel est plus petit que le deuxième." << endl;
    }
    else
    {
        cout << "Le premier rationnel n'est pas plus petit que le deuxième." << endl;
    }

    // Saisie d'un rationnel
    cout << "Veuillez saisir un rationnel : ";
    cin >> r3;
    cout << "Vous avez saisi : " << r3 << endl;

    cout << "------------------------------------------------------------------------" << endl;
    return 0;
}

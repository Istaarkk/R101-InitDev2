// main.cpp
#include "appartement.h"
#include <iostream>

int main()
{
    // Test du tri d'appartement
    Piece p1(5, 6, "Chambre1");
    Piece p2(3, 4, "Chambre2");
    Piece p3(6, 8, "Chambre3");

    Appartement appartement;
    appartement.ajoutPiece(p1);
    appartement.ajoutPiece(p2);
    appartement.ajoutPiece(p3);

    cout << "Avant le tri : " << endl;
    appartement.afficher();

    appartement.trier();

    cout << "\nAprès le tri : " << endl;
    appartement.afficher();

    return 0;
}

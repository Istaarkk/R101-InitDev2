// main.cpp
#include "Appartement.h"

int main() {
    // Exemple d'utilisation de la classe Piece
    Piece piece1(5.0, 4.0, "chambre");
    Piece piece2(6.0, 3.0, "cuisine");

    piece1.afficher();
    piece1.saisir();
    piece1.afficher();

    std::cout << "Surface de piece1: " << piece1.surface() << "m²\n";

    if (piece1.plusGrande(piece2)) {
        std::cout << "piece1 est plus grande que piece2.\n";
    } else {
        std::cout << "piece2 est plus grande que piece1.\n";
    }

    std::cout << "Surface externe de piece1: " << surface(piece1) << "m²\n";

    // Exemple d'utilisation de la classe Appartement
    Appartement appart1;  // Utilisation du constructeur vide
    appart1.ajoutPiece(piece1);
    appart1.ajoutPiece(piece2);

    Appartement appart2(piece1, "2 rue Example 12345 Ville");  // Utilisation du constructeur avec une pièce et adresse
    appart2.afficher();

    std::cout << "Nombre de pièces dans appart2: " << appart2.nbPieces() << "\n";
    std::cout << "Surface totale de appart2: " << appart2.surface() << "m²\n";

    int resultatComparaison = appart1.compare(appart2);
    if (resultatComparaison == -1) {
        std::cout << "appart1 a une surface plus petite que appart2.\n";
    } else if (resultatComparaison == 1) {
        std::cout << "appart1 a une surface plus grande que appart2.\n";
    } else {
        std::cout << "appart1 a une surface égale à appart2.\n";
    }

    int indicePlusGrandePiece = appart2.plusGrandePiece();
    if (indicePlusGrandePiece != -1) {
        std::cout << "L'indice de la pièce de plus grande surface dans appart2 est : " << indicePlusGrandePiece << "\n";
    } else {
        std::cout << "Aucune pièce dans appart2.\n";
    }

    return 0;
}

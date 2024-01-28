// Piece.cpp
#include "Piece.h"

Piece::Piece() : longueur(3.0), largeur(4.0), nom("piecevide") {
    if (longueur < largeur) std::swap(longueur, largeur);
    if (longueur <= 0 || largeur <= 0) throw std::invalid_argument("Les dimensions doivent être strictement positives");
    for (char &c : nom) c = tolower(c);
}

Piece::Piece(double l, double w, const std::string &n) : longueur(l), largeur(w), nom(n) {
    if (longueur < largeur) std::swap(longueur, largeur);
    if (longueur <= 0 || largeur <= 0) throw std::invalid_argument("Les dimensions doivent être strictement positives");
    for (char &c : nom) c = tolower(c);
}

void Piece::afficher() const {
    std::cout << "Nom: " << nom << ", Longueur: " << longueur << "m, Largeur: " << largeur << "m\n";
}

void Piece::saisir() {
    std::cout << "Saisir les dimensions de la pièce (longueur largeur nom): ";
    std::cin >> longueur >> largeur >> nom;
    if (longueur < largeur) std::swap(longueur, largeur);
    if (longueur <= 0 || largeur <= 0) throw std::invalid_argument("Les dimensions doivent être strictement positives");
    for (char &c : nom) c = tolower(c);
}

double Piece::surface() const {
    return longueur * largeur;
}

bool Piece::plusGrande(const Piece &autrePiece) const {
    return surface() > autrePiece.surface();
}

double surface(const Piece &p) {
    return p.surface();
}

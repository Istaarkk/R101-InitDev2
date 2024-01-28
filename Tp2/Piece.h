// Piece.h
#pragma once  // Protection contre l'inclusion multiple

#include <iostream>
#include <stdexcept>

class Piece {
private:
    double longueur;
    double largeur;
    std::string nom;

public:
    Piece();
    Piece(double l, double w, const std::string &n);

    void afficher() const;
    void saisir();
    double surface() const;
    bool plusGrande(const Piece &autrePiece) const;
};

double surface(const Piece &p);

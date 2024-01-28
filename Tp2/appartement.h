// Appartement.h
#pragma once

#include <iostream>
#include <vector>
#include "Piece.h"

class Appartement {
private:
    std::string adresse;
    std::vector<Piece> pieces;

public:
    Appartement();
    Appartement(const Piece &piece, const std::string &adr);

    void afficher() const;
    void ajoutPiece(const Piece &piece);
    Piece retraitPiece(int indice);
    int nbPieces() const;
    double surface() const;
    int compare(const Appartement &autreAppartement) const;
    int plusGrandePiece() const;
};

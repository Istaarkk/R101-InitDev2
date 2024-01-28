// Appartement.cpp
#include "Appartement.h"
#include <algorithm>

Appartement::Appartement() : adresse("1 rue Joliot-Curie 91400 Orsay") {}

Appartement::Appartement(const Piece &piece, const std::string &adr) : adresse(adr) {
    pieces.push_back(piece);
}

void Appartement::afficher() const {
    std::cout << "Adresse de l'appartement: " << adresse << "\n";
    std::cout << "Pièces de l'appartement:\n";
    for (const Piece &p : pieces) {
        p.afficher();
    }
}

void Appartement::ajoutPiece(const Piece &piece) {
    pieces.push_back(piece);
}

Piece Appartement::retraitPiece(int indice) {
    if (indice >= 0 && indice < pieces.size()) {
        Piece pieceSupprimee = pieces[indice];
        pieces[indice] = pieces.back();
        pieces.pop_back();
        return pieceSupprimee;
    } else {
        throw std::out_of_range("Indice invalide");
    }
}

int Appartement::nbPieces() const {
    return pieces.size();
}

double Appartement::surface() const {
    double totalSurface = 0.0;
    for (const Piece &p : pieces) {
        totalSurface += p.surface();
    }
    return totalSurface;
}

int Appartement::compare(const Appartement &autreAppartement) const {
    double surfaceActuelle = surface();
    double surfaceAutre = autreAppartement.surface();

    if (surfaceActuelle < surfaceAutre) {
        return -1;
    } else if (surfaceActuelle > surfaceAutre) {
        return 1;
    } else {
        return 0;
    }
}

int Appartement::plusGrandePiece() const {
    if (pieces.empty()) {
        return -1;
    }

    auto it = std::max_element(pieces.begin(), pieces.end(),
        [](const Piece &p1, const Piece &p2) {
            return p1.surface() < p2.surface();
        });

    return std::distance(pieces.begin(), it);
}

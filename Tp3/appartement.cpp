// HB 2022
/// classes Appartement et Piece
/// Fichier appartement.cpp

#include <vector>
#include <iostream>
#include "piece.h"
#include "appartement.h"
#include <string>

/// Constructeur vide : permet de construire un objet Appartement sans aucune pièce avec une adresse par défaut
Appartement::Appartement(){
    _adresse = ADRESSE;
}

/// Constructeur : permet de construire un appartement avec une première pièce passée en paramètre
Appartement::Appartement(const Piece &p, const std::string &ad){
    _lesPieces.push_back(p);
    _adresse = ad;
}

/// affichage : affiche les différentes pièces d'un appartement
void Appartement::afficher() const{
    if(_lesPieces.size() == 0)
        std::cout << "L'appartement est encore en construction... " << std::endl;
    else{
        std::cout << "Un appartement de " << _lesPieces.size() << " pièces" << std::endl;
        for(int i = 0; i < _lesPieces.size(); i++)
            _lesPieces[i].afficher();
    }
}

/// ajoutPiece : ajouter une pièce à un appartement
void Appartement::ajoutPiece(const Piece &p){
    _lesPieces.push_back(p);  // _lesPieces est un vector, ajout en dernière position
}

/// retraitPiece : supprime une pièce à un indice donné
Piece Appartement::retraitPiece(int i){
    // Pour déclencher l'exception (protéger les bornes) il faut utiliser at et pas []
    Piece resul(_lesPieces.at(i));
    // On remplace la pièce i par la dernière pièce, puis on retire la dernière pièce
    _lesPieces[i] = _lesPieces.back();
    _lesPieces.pop_back();
    // On pourrait utiliser les iterateurs (pas étudiés lors du 1er module)
    // begin : fonction qui retourne un itérateur sur le début du Vector
    // _lesPieces.erase(_lesPieces.begin()+i)
    return resul;
}

/// surface : retourne la superficie de l'appartement
float Appartement::surface() const{
    float s = 0;
    for(int i = 0; i < _lesPieces.size(); i++){
        s += _lesPieces[i].surface();
    }
    return s;
}

/// plusGrandePiece : retourne l'indice de la plus grande pièce,
/// -1 si appartement vide
int Appartement::plusGrandePiece() const{
    int pgp = -1;
    if (_lesPieces.size() > 0){
        pgp = 0;
        for (int i = 1; i < _lesPieces.size(); i++)
            if (_lesPieces[i].surface() > _lesPieces.at(pgp).surface())
                pgp = i;
    }
    return pgp;
}

/// ------- compare 2 appartements sur leur surface ---
int Appartement::compare(const Appartement &a) const{
    int resul;
    float surf1, surf2;
    surf1 = surface();
    surf2 = a.surface();
    if (surf1 < surf2)
        resul = -1;
    else if (surf1 > surf2)
        resul = 1;
    else
        resul = 0;
    return resul;
}

// retourne le nombre de pièces d'un appartement
int Appartement::nbPieces() const{
    return _lesPieces.size();
}

/// recherche : retourne un indice de la pièce dont le nom est passé en paramètre si cette pièce est présente dans l'appartement cible, et -1 sinon.
int Appartement::recherche(const std::string &nomPiece) const{
    int debut = 0;
    int fin = _lesPieces.size() - 1;

    while (debut <= fin){
        int milieu = (debut + fin) / 2;
        int comparaison = _lesPieces[milieu].nom().compare(nomPiece);

        if (comparaison == 0)
            return milieu; // Pièce trouvée
        else if (comparaison < 0)
            debut = milieu + 1;
        else
            fin = milieu - 1;
    }

    return -1; // Pièce non trouvée
}

/// recherchePremier : retourne le premier indice de la pièce dont le nom est passé en paramètre si cette pièce est présente dans l'appartement cible, et -1 sinon.
int Appartement::recherchePremier(const std::string &nomPiece) const{
    int debut = 0;
    int fin = _lesPieces.size() - 1;
    int resultat = -1;

    while (debut <= fin){
        int milieu = (debut + fin) / 2;
        int comparaison = _lesPieces[milieu].nom().compare(nomPiece);

        if (comparaison == 0){
            resultat = milieu;
            fin = milieu - 1; // Recherche de la première occurrence
        }
        else if (comparaison < 0)
            debut = milieu + 1;
        else
            fin = milieu - 1;
    }

    return resultat; // Retourne l'indice de la première occurrence ou -1 si non trouvée
}

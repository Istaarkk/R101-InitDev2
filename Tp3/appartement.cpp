// HB 2022
/// classes Appartement et Piece
/// Fichier appartement.cpp

#include <vector>
#include <iostream>
#include "piece.h"
#include "appartement.h"
#include <string>

/// Constructeur vide : permet de construire un objet Appartement sans aucune pi�ce avec une adresse par d�faut
Appartement::Appartement(){
    _adresse = ADRESSE;
}

/// Constructeur : permet de construire un appartement avec une premi�re pi�ce pass�e en param�tre
Appartement::Appartement(const Piece &p, const std::string &ad){
    _lesPieces.push_back(p);
    _adresse = ad;
}

/// affichage : affiche les diff�rentes pi�ces d'un appartement
void Appartement::afficher() const{
    if(_lesPieces.size() == 0)
        std::cout << "L'appartement est encore en construction... " << std::endl;
    else{
        std::cout << "Un appartement de " << _lesPieces.size() << " pi�ces" << std::endl;
        for(int i = 0; i < _lesPieces.size(); i++)
            _lesPieces[i].afficher();
    }
}

/// ajoutPiece : ajouter une pi�ce � un appartement
void Appartement::ajoutPiece(const Piece &p){
    _lesPieces.push_back(p);  // _lesPieces est un vector, ajout en derni�re position
}

/// retraitPiece : supprime une pi�ce � un indice donn�
Piece Appartement::retraitPiece(int i){
    // Pour d�clencher l'exception (prot�ger les bornes) il faut utiliser at et pas []
    Piece resul(_lesPieces.at(i));
    // On remplace la pi�ce i par la derni�re pi�ce, puis on retire la derni�re pi�ce
    _lesPieces[i] = _lesPieces.back();
    _lesPieces.pop_back();
    // On pourrait utiliser les iterateurs (pas �tudi�s lors du 1er module)
    // begin : fonction qui retourne un it�rateur sur le d�but du Vector
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

/// plusGrandePiece : retourne l'indice de la plus grande pi�ce,
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

// retourne le nombre de pi�ces d'un appartement
int Appartement::nbPieces() const{
    return _lesPieces.size();
}

/// recherche : retourne un indice de la pi�ce dont le nom est pass� en param�tre si cette pi�ce est pr�sente dans l'appartement cible, et -1 sinon.
int Appartement::recherche(const std::string &nomPiece) const{
    int debut = 0;
    int fin = _lesPieces.size() - 1;

    while (debut <= fin){
        int milieu = (debut + fin) / 2;
        int comparaison = _lesPieces[milieu].nom().compare(nomPiece);

        if (comparaison == 0)
            return milieu; // Pi�ce trouv�e
        else if (comparaison < 0)
            debut = milieu + 1;
        else
            fin = milieu - 1;
    }

    return -1; // Pi�ce non trouv�e
}

/// recherchePremier : retourne le premier indice de la pi�ce dont le nom est pass� en param�tre si cette pi�ce est pr�sente dans l'appartement cible, et -1 sinon.
int Appartement::recherchePremier(const std::string &nomPiece) const{
    int debut = 0;
    int fin = _lesPieces.size() - 1;
    int resultat = -1;

    while (debut <= fin){
        int milieu = (debut + fin) / 2;
        int comparaison = _lesPieces[milieu].nom().compare(nomPiece);

        if (comparaison == 0){
            resultat = milieu;
            fin = milieu - 1; // Recherche de la premi�re occurrence
        }
        else if (comparaison < 0)
            debut = milieu + 1;
        else
            fin = milieu - 1;
    }

    return resultat; // Retourne l'indice de la premi�re occurrence ou -1 si non trouv�e
}

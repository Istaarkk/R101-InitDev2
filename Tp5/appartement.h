// appartement.h
#ifndef _APPART_
#define _APPART_

#include <string>
#include <vector>
#include "piece.h"

#include <stdexcept> /// pour l'exception out_of_range

const string ADRESSE = "1 rue Joliot-Curie 91400 Orsay";
const vector<int> ZONES = {2500, 3100, 3500, 4150, 4500};
using namespace std;

//----------------------------------

class Appartement
{
    vector<Piece> _lesPieces;
    string _adresse;

public:
    //---------------  constructeurs
    Appartement(); /// appartement vide au départ
    Appartement(const Piece &arg, const string &); // un appartement avec une piece et une adresse

    //---------------  methodes de consultation  : objet cible non modifie => fonction const
    void afficher() const;                                              // affiche l'adresse et les pièces de l'appartement
    int plusGrandePiece() const;                                        // retourne l'indice de la plus grande piece de l'appartement, -1 si appartement vide
    float surface() const;                                              // retourne surface totale de l'appartement
    int nbPieces() const;                                               // retourne nombre de Pieces de l'appartement
    int compare(const Appartement &a) const;                           // compare 2 appartements sur leur surface
    void ajoutPiece(const Piece &);                                     // ajoute une piece dans l'appartement
    Piece retraitPiece(int i);                                           // retire la piece dont l'indice est fourni en parametre. Si incorrect : déclenche exception out_of_range
    void trier();                                                       // trier les pièces de l'appartement par ordre croissant de leur surface
};

#endif

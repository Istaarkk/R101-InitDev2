// piece.cpp
#include "piece.h"
#include <iostream>

using namespace std;

void Piece::normalise()
{
    if (_larg > _long)
    {
        float tmp;
        tmp = _long;
        _long = _larg;
        _larg = tmp;
    }
    for (int i = 0; i < _nom.length(); i++)
        _nom[i] = tolower(_nom[i]);
}

void Piece::verifEtNormalise()
{
    if (_long < 0)
        throw(string("La longueur est incorrecte " + to_string(_long)));
    if (_larg < 0)
        throw(string("La largeur est incorrecte " + to_string(_larg)));
    normalise();
}

Piece::Piece(float lo, float la, const string &nom)
{
    _long = lo;
    _larg = la;
    _nom = nom;
    verifEtNormalise();
}

void Piece::afficher() const
{
    cout << "Piece  \"" << _nom << "\" : surface : "
         << surface() << endl;
}

void Piece::saisir()
{
    float tmp;
    cout << "Entrez le nom de la piece : ";
    cin >> _nom;
    cout << "puis la longueur et la largeur : ";
    cin >> _long >> _larg;
    while (_long <= 0 || _larg <= 0)
    {
        cout << "les 2 valeurs doivent etre >0, recommencer ";
        cin >> _long >> _larg;
    }
    normalise();
}

float Piece::surface() const
{
    return _long * _larg;
}

bool Piece::plusGrande(const Piece &arg) const
{
    return (surface() >= arg.surface());
}

int Piece::compare(const Piece &p) const
{
    int resul;
    float surf1, surf2;
    surf1 = surface();
    surf2 = p.surface();
    if (surf1 < surf2)
        resul = -1;
    else if (surf1 > surf2)
        resul = 1;
    else
        resul = 0;
    return resul;
}

float surface(const Piece &p)
{
    return p.surface();
}

// appartement.cpp
#include <vector>
#include <iostream>
#include "piece.h"
#include "appartement.h"
#include <string>
#include <algorithm>

Appartement::Appartement()
{
    _adresse = ADRESSE;
}

Appartement::Appartement(const Piece &arg, const string &ad)
{
    _lesPieces.push_back(arg);
    _adresse = ad;
}

void Appartement::afficher() const
{
    if (_lesPieces.size() == 0)
        cout << "L'appartement est encore en construction... " << endl;
    else
    {
        cout << "un appartement de " << _lesPieces.size() << " pieces" << endl;
        for (int i = 0; i < _lesPieces.size(); i++)
            _lesPieces[i].afficher();
    }
}

void Appartement::ajoutPiece(const Piece &p)
{
    _lesPieces.push_back(p);
}

Piece Appartement::retraitPiece(int i)
{
    Piece resul(_lesPieces.at(i));
    _lesPieces[i] = _lesPieces.back();
    _lesPieces.pop_back();
    return resul;
}

float Appartement::surface() const
{
    float s = 0;
    for (int i = 0; i < _lesPieces.size(); i++)
    {
        s += _lesPieces[i].surface();
    }
    return s;
}

int Appartement::plusGrandePiece() const
{
    int pgp = -1;
    if (_lesPieces.size() > 0)
    {
        pgp = 0;
        for (int i = 1; i < _lesPieces.size(); i++)
            if (_lesPieces[i].surface() > _lesPieces.at(pgp).surface())
                pgp = i;
    }
    return pgp;
}

int Appartement::compare(const Appartement &a) const
{
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

int Appartement::nbPieces() const
{
    return _lesPieces.size();
}

void Appartement::trier()
{
    int j;
    Piece x;
    int n = _lesPieces.size();
    for (int i = 1; i < n; i++)
    {
         x = _lesPieces[i];
         j = i;
        while (j > 0 && _lesPieces[j - 1].surface() > x.surface())
        {
            _lesPieces[j] = _lesPieces[j - 1];
            j--;
        }
        _lesPieces[j] = x;
    }
}

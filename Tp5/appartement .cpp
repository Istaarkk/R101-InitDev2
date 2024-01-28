// appartement.cpp

#include <iostream>
#include "appartement.h"
#include "piece.h"

using namespace std;

Appartement::Appartement()
{
    _adresse = ADRESSE;
}

Appartement::Appartement(const Piece &p, const string &ad)
{
    _lesPieces.push_back(p);
    _adresse = ad;
}

void Appartement::afficher() const
{
    if (_lesPieces.size() == 0)
        cout << "L'appartement est encore en construction..." << endl;
    else
    {
        cout << "Un appartement de " << _lesPieces.size() << " pieces" << endl;
        for (int i = 0; i < _lesPieces.size(); i++)
            _lesPieces[i].afficher();
    }
}

int Appartement::plusGrandePiece() const
{
    int pgp = -1;
    if (_lesPieces.size() > 0)
    {
        pgp = 0;
        for (int i = 1; i < _lesPieces.size(); i++)
            if (_lesPieces[i].getSurface() > _lesPieces.at(pgp).getSurface())
                pgp = i;
    }
    return pgp;
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

int Appartement::nbPieces() const
{
    return _lesPieces.size();
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

void Appartement::trier()
{
    size_t n = _lesPieces.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (_lesPieces[j].getSurface() > _lesPieces[j + 1].getSurface())
            {
                Piece temp = _lesPieces[j];
                _lesPieces[j] = _lesPieces[j + 1];
                _lesPieces[j + 1] = temp;
            }
        }
    }
}

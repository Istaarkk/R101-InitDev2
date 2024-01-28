#include <iostream>
#include <stdexcept>
#include "rat.h"


// Définition des méthodes de la classe Rationnel

Rationnel::Rationnel(int num, int den) : _num(num), _den(den)
{
    if (_den == 0)
        throw invalid_argument("Denominateur nul");

    if (_den < 0)
    {
        _num = -_num;
        _den = -_den;
    }

    _reduire();
}

void Rationnel::_reduire()
{
    int facteur = pgcd(_num, _den);
    _num /= facteur;
    _den /= facteur;
}

void Rationnel::afficher() const
{
    cout << _num << '/' << _den;
}

int Rationnel::getNum() const
{
    return _num;
}

int Rationnel::getDen() const
{
    return _den;
}

Rationnel Rationnel::operator*(const Rationnel &r) const
{
    return Rationnel(_num * r._num, _den * r._den);
}

bool Rationnel::operator==(const Rationnel &r) const
{
    return (_num == r._num) && (_den == r._den);
}

Rationnel Rationnel::operator-() const
{
    return Rationnel(-_num, _den);
}

Rationnel Rationnel::operator+(const Rationnel &r) const
{
    return Rationnel(_num * r._den + r._num * _den, _den * r._den);
}

bool Rationnel::operator<(const Rationnel &r) const
{
    return (_num * r._den < r._num * _den);
}

istream &Rationnel::saisir(istream &in)
{
    cout << "Numerateur ? ";
    in >> _num;

    do
    {
        cout << "Denominateur ? ";
        in >> _den;
    } while (_den == 0);

    if (_den < 0)
    {
        _num = -_num;
        _den = -_den;
    }

    _reduire();
    return in;
}

istream &operator>>(istream &in, Rationnel &r)
{
    r.saisir(in);
    return in;
}

ostream &operator<<(ostream &out, Rationnel &r)
{
    out << r.getNum() << '/' << r.getDen();
    return out;
}

int pgcd(int a, int b)
{
    int a2 = (a > 0) ? a : -a;

    if (a2 < b)
    {
        int temp = a2;
        a2 = b;
        b = temp;
    }

    return pgcdRecursif(a2, b);
}

int pgcdRecursif(int a, int b)
{
    return (b == 0) ? a : pgcdRecursif(b, a % b);
}

// Ajout des opérateurs globaux utilisant les méthodes de la classe

Rationnel operator*(const Rationnel &r1, const Rationnel &r2)
{
    return r1.operator*(r2);
}

bool operator==(const Rationnel &r1, const Rationnel &r2)
{
    return r1.operator==(r2);
}

Rationnel operator-(const Rationnel &r)
{
    return r.operator-();
}

Rationnel operator+(const Rationnel &r1, const Rationnel &r2)
{
    return r1.operator+(r2);
}

bool operator<(const Rationnel &r1, const Rationnel &r2)
{
    return r1.operator<(r2);
}


// Fonctions de test
bool testConstructeurVideEtGetters() {
  bool ok = true;
  Rationnel r;
  if (!(r.getNum() == 0)) {
    ok = false;
    cout << "Erreur dans le constructeur vide ou getNum : le numerateur vaut " << r.getNum() << " (attendu : 0)" << endl;
  }
  if (!(r.getDen() == 1)) {
    ok = false;
    cout << "Erreur dans le constructeur vide ou getDen : le denominateur vaut " << r.getDen() << " (attendu : 1)" << endl;
  }
  return ok;
}

bool testConstructeurParamEtGetters(int n, int d, int nres, int dres, bool exc) {
  bool ok = true;
  if (exc) {
    try {
      Rationnel r(n, d);
      ok = false;
      cout << "Erreur dans le constructeur avec parametres : une exception aurait du etre lancee" << endl;
    } catch (const invalid_argument &) { }
  } else {
    try {
      Rationnel r(n,d);
      if (!(r.getNum() == nres)) {
        ok = false;
        cout << "Erreur dans le constructeur avec parametres ou getNum : le numerateur vaut " << r.getNum() << " (attendu : " << nres << ")" << endl;
      }
      if (!(r.getDen() == dres)) {
        ok = false;
        cout << "Erreur dans le constructeur avec parametres ou getDen : le denominateur vaut " << r.getDen() << " (attendu : " << dres << ")" << endl;
      }
    } catch (const invalid_argument &e) {
      ok = false;
      cout << "Erreur dans le constructeur avec parametres : l'exception " << e.what() << " a ete lancee" << endl;
    }
  }
  return ok;
}

bool testsConstructeurParamEtGetters() {
  bool ok = true;
  ok = ok && testConstructeurParamEtGetters(0, 1, 0, 1, false);
  ok = ok && testConstructeurParamEtGetters(1, 2, 1, 2, false);
  ok = ok && testConstructeurParamEtGetters(-1, 2, -1, 2, false);
  ok = ok && testConstructeurParamEtGetters(1, -2, -1, 2, false);
  ok = ok && testConstructeurParamEtGetters(-1, -2, 1, 2, false);
  ok = ok && testConstructeurParamEtGetters(2, 4, 1, 2, false);
  ok = ok && testConstructeurParamEtGetters(1, 0, 1, 0, true);
  return ok;
}

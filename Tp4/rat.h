#ifndef _RAT_H_
#define _RAT_H_

#include <iostream>
#include <cstdlib>

using namespace std;

class Rationnel
{
private:
    int _num;
    int _den;
    void _reduire();

public:
    Rationnel(int=0, int=1);
    void afficher() const;
    int getNum() const;
    int getDen() const;

    Rationnel operator*(const Rationnel &r) const;
    bool operator==(const Rationnel &r) const;
    Rationnel operator-() const;
    Rationnel operator+(const Rationnel &r) const;
    bool operator<(const Rationnel &r) const;
    istream &saisir(istream &in);

};

istream &operator>>(istream &in, Rationnel &r);

ostream &operator<<(ostream &out, Rationnel &r);
int pgcd(int a, int b);
int pgcdRecursif(int a, int b);

bool testConstructeurVideEtGetters();
bool testConstructeurParamEtGetters(int n, int d, int nres, int dres, bool exc);
bool testsConstructeurParamEtGetters();

#endif

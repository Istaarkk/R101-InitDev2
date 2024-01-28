#include <iostream>
#include <vector>
#include "appartement.h"

int rechercheDicho(const std::vector<int>& vec, int valeur) {
    int debut = 0;
    int fin = vec.size() - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;

        if (vec[milieu] == valeur)
            return milieu;
        else if (vec[milieu] < valeur)
            debut = milieu + 1;
        else
            fin = milieu - 1;
    }

    return -1; // La valeur n'est pas présente dans le vecteur
}
//recherche sequentielle
int recherchePetit(const std::vector<int>& vec, int valeur) {
    int index = rechercheDicho(vec, valeur);

    if (index == -1)
        return -1;

    while (index > 0 && vec[index - 1] == valeur)
        index--;

    return index;
}
/*autre méthode
vec[milieu]==val
if(milieu>0&&tab[milieu-1]==val)
        fin=milieu-1
else{
    trouve = true
    indice = milieu
}
*/

int recherche() {
    std::vector<int> vecteur = {1, 2, 2, 3, 4, 4, 4, 5, 6};
    int valeurRecherchee = 4;

    int resultatDicho = rechercheDicho(vecteur, valeurRecherchee);
    int resultatPetit = recherchePetit(vecteur, valeurRecherchee);

    std::cout << "Recherche Dichotomique : " << resultatDicho << std::endl;
    std::cout << "Première occurrence : " << resultatPetit << std::endl;


    /*promo[milieu].getGroup()==group && promo[milieu].getnom()==nom)
    && promo[milieu].getnom()==nom   */


    return 0;
}


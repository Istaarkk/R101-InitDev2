#include <string>
#include <iostream>
#include <vector>
#include "permis.h"

using namespace std;


int main() {
  Permis pdef;
  Permis p("Duck", "Donald", "09/06/1934", "012345", 7);

  cout << endl << "----- Tests manuels de affiche -----------------------------------------" << endl;
  pdef.affiche();
  p.affiche();
  cout << endl << "----- Tests automatiques de getNbpoints --------------------------------" << endl;
  bool ok = true;
  if (!(p.getNbpoints() == 7)) {
    ok = false;
    cout << "Erreur : p.getNbpoints() = " << p.getNbpoints() << " (attendu : 7)" << endl;
  }
  if (ok) cout << "Methode getNbpoints correcte" << endl;

  cout << endl << "----- Tests automatiques de retraitPoints ------------------------------" << endl;
  ok = true;
  p.retraitPoints(3);
  if (!(p.getNbpoints() == 4)) {
    ok = false;
    cout << "Erreur : apres avoir retire 3 points a un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 4)" << endl;
  }
  p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
  p.retraitPoints(0);
  if (!(p.getNbpoints() == 7)) {
    ok = false;
    cout << "Erreur : apres avoir retire 0 points a un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 7)" << endl;
  }
  p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
  p.retraitPoints(7);
  if (!(p.getNbpoints() == 0)) {
    ok = false;
    cout << "Erreur : apres avoir retire 7 points e un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 0)" << endl;
  }
  p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
  p.retraitPoints(10);
  if (!(p.getNbpoints() == 0)) {
    ok = false;
    cout << "Erreur : après avoir retire 10 points a un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 0)" << endl;
  }
  p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
  if (ok) cout << "Methode retraitPoints correcte" << endl;
P1=Permis ("Gates", "Bill", "10/28/1955", "987654", 10);
P2=Permis ("Musk", "Elon", "06/28/1971", "123456", 8);

p1.affiche();
p2.affiche();

  return 0;
}

/*Le fichier permis.h contient la déclaration de la classe Permis avec ses membres, ses méthodes et les constantes MAXP et MINP. Le fichier permis.cpp contient les définitions des méthodes de la classe Permis.

Le fichier main.cpp contient le programme principal avec des tests pour les différentes fonctionnalités de la classe Permis.

Pour répondre aux différentes questions :

1. Retirez Permis:: de la définition de la fonction membre affiche. Que se passe-t-il?
Si vous retirez Permis:: de la définition de la fonction affiche, cela signifie que la fonction affiche n'appartient plus explicitement à la classe Permis. Cela provoquerait une erreur de compilation car le compilateur ne saurait pas à quelle classe appartient cette fonction.

2. Que contient le fichier main.cpp ?
Le fichier main.cpp contient le programme principal avec des instances de la classe Permis et des tests pour les méthodes de cette classe. Il initialise des permis, affiche leurs informations, teste la méthode getNbpoints et la méthode retraitPoints.

3. Compilez et exécutez le projet. Quels affichages sont produits ? Expliquez.
Le programme crée deux instances de la classe Permis (une avec le constructeur par défaut et une avec le constructeur paramétré), affiche leurs informations, teste la méthode getNbpoints et retraitPoints. Les affichages seront :

Construction d'un permis
Construction d'un permis

----- Tests manuels de affiche -----------------------------------------
Informations sur le permis de inconnu inconnu :
00000
non renseigne
Nombre de points : 12
Informations sur le permis de Donald Duck :
012345
09/06/1934
Nombre de points : 7

----- Tests automatiques de getNbpoints --------------------------------
Methode getNbpoints correcte

----- Tests automatiques de retraitPoints ------------------------------
Methode retraitPoints correcte
4. Complétez le fichier main.cpp en déclarant deux autres instances p1 et p2 de la classe Permis. Vérifiez en appelant la fonction membre affiche.
cpp
Permis p1("Gates", "Bill", "10/28/1955", "987654", 10);
Permis p2("Musk", "Elon", "06/28/1971", "123456", 8);



5. Testez l'instruction cout << p1 << endl dans main.cpp. Que se passe-t-il? Pourquoi?
Cette instruction provoquera une erreur de compilation car l'opérateur << n'est pas défini pour la classe Permis. Vous devez surcharger l'opérateur << pour la classe Permis si vous souhaitez utiliser cet opérateur pour afficher les informations de l'objet.

6. Testez l'instruction cout << p1._nom << endl dans main.cpp. Que se passe-t-il? Pourquoi?
Cela provoquera une erreur de compilation car _nom est un membre privé de la classe Permis, et il n'est pas accessible directement depuis l'extérieur de la classe.

7. Pourquoi le prototype de la fonction affiche se termine-t-il par le mot-clé const et pas celui de la fonction retraitPoints?
Le mot-clé const à la fin d'une fonction membre indique que cette fonction ne modifie pas les données membres de l'objet sur lequel elle est appelée. Dans le cas de la fonction affiche, elle ne modifie pas les attributs de l'objet Permis, elle se contente de les afficher. En revanche, la fonction retraitPoints modifie l'attribut _nbpoints, donc elle ne peut pas être constante.*/
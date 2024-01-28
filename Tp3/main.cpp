#include <iostream>
#include "appartement.h"
#include "piece.h"

int main()
{
    // Create apartment r1 with 10 rooms named "chambre0" to "chambre9"
    Appartement r1;
    for (int i = 0; i < 10; ++i)
    {
        Piece chambre(10.0, 12.0, "chambre" + to_string(i));
        r1.ajoutPiece(chambre);
    }

    // Test recherche method
    int indiceChambre = r1.recherche("chambre5");
    if (indiceChambre != -1)
    {
        cout << "Chambre trouvee a l'indice : " << indiceChambre << endl;
    }
    else
    {
        cout << "Chambre non trouvee." << endl;
    }

    // Create apartment r2 with 10 rooms, including 5 "chambre5"
    Appartement r2;
    for (int i = 0; i < 5; ++i)
    {
        Piece chambre(10.0, 12.0, "chambre5");
        r2.ajoutPiece(chambre);
    }
    for (int i = 0; i < 5; ++i)
    {
        Piece chambre(10.0, 12.0, "chambre" + to_string(i));
        r2.ajoutPiece(chambre);
    }

    // Test recherchePremier method
    int premierIndiceChambre5 = r2.recherchePremier("chambre5");
    if (premierIndiceChambre5 != -1)
    {
        cout << "Premier indice de chambre5 : " << premierIndiceChambre5 << endl;
    }
    else
    {
        cout << "Chambre5 non trouvee." << endl;
    }

    return 0;
}

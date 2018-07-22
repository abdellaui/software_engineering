#include "Ernaehrung.h"

int main()
{
    std::cout << "-1 - exit" << std::endl;
    std::cout << " 0 - keine" << std::endl;
    std::cout << " 1 - vegetarisch" << std::endl;
    std::cout << " 2 - vegan" << std::endl;
    std::cout << " 3 - laktosefrei" << std::endl;
    std::cout << " 4 - glutenfrei" << std::endl;
    std::cout << " 5 - helal" << std::endl;
    std::cout << " 6 - koscher" << std::endl;

    Ernaehrung ernaehrung;
    std::string input;
    while (std::cout << "Eingabe:")
    {
        try
        {
            // teste erfolgreiche Eingabe
            if (!(std::cin >> input) || std::cin.fail())
            {
                throw "Fehler bei der Eingabe! Versuche es erneut!";
            }
            else
            {
                // String zur Ganzzahl
                int inputToInt = std::stoi(input);
                // beende bei -1 das Programm
                if (inputToInt == -1)
                    break;

                List l = ernaehrung.erstelleProfil(inputToInt);
                Menue::printList(l);
            }
        }
        // fange alle Fehler ab
        catch (const char *error)
        {
            std::cout << error << std::endl;
            std::cin.clear();
        }
        catch (...)
        {
            std::cout << "Leider lief etwas mit der Eingabe schief, versuche es erneut!" << std::endl;
            std::cin.clear();
        }
    }
    std::getchar();
    return 0;
}

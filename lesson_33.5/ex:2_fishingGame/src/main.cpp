#include <ctime>
#include <iostream>

#include "field.h"
#include "m_input.h"


int main()
{

    std::srand(std::time(nullptr));

    Field* field = new Field();

    int attempts = 0;

    std::cout << "Fishing Game!" << std::endl;
    std::cout << "There are nine sectors: from 1 to 9" << std::endl;
    std::cout << "Try to catch a fish without getting caught on a boot." << std::endl;


    while (true)
    {
        int sectorNumber;
        std::cout << "Input the sector number -> ";
        sectorNumber = inputInt();

        try
        {
            ++attempts;
            field->castFishingRod(sectorNumber);
        }
        catch (const Fish&)
        {
            std::cout << "You catch the fish!" << std::endl;
            std::cout << "Successful fishing completed" << std::endl;
            std::cout << "Number of attempts: " << attempts << std::endl;
            break;
        }
        catch (const Boot&)
        {
            std::cout << "You catch the boot!" << std::endl;
            std::cout << "The fishing trip ended in failure." << std::endl;
            std::cout << "Number of attempts: " << attempts << std::endl;
            break;
        }
        catch (const std::invalid_argument& error)
        {
            // некорректный номер не является ошибкой
            std::cout << "Error: " << error.what() << std::endl;
            --attempts;
        }
    }

    delete field;


    return 0;
}

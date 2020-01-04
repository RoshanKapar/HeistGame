#include<iostream>
#include<string>
#include<ctime>

void PrintIntroduction(int Difficulty) {
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue....\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    const int CodeA = (rand() % Difficulty) + Difficulty;
    const int CodeB = (rand() % Difficulty) + Difficulty;
    const int CodeC = (rand() % Difficulty) + Difficulty;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are three numbers in the code";
    std::cout << "\n+ The code adds-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou win !";
        return true;
    }
    else
    {
        std::cout << "\nYou messed up !";
        return false;
    }

}

int main()
{
    int counter = 3;
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)// Loop game until game is completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
        else 
        {   
            std::cout << " you have " << counter - 1 << " turns remaining" << std::endl;
            counter = counter - 1;
            if (counter == 0) {
                std::cout << "The police is behind you and you have lost" << std::endl;
                break;

        }
        }
    

    }
    if (counter != 0) {

        std::cout << "Congrulations You have completed the game";
        return 0;
    }
}

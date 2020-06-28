#include <iostream>
#include <ctime>



void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room ...\nEnter the correct access code to continue...\n\n";
}



bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal 
    std::cout << "+ There are 3 numbers in the code"; 
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;
    std::cout << std::endl;
   
    // Store player guess
    int GuessA, GuessB, GuessC; 
    std::cout << "Please write 3 values and press enter: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Great job, your showing real promise agent! You have successfully extracted a file, keep going! ***\n";
        return true;
    }
    else    
    {
        std::cout << "\n*** You entered the wrong code! Careful agent, try again! ***\n";
        return false;
    }
}



int main()
{
    srand(time(NULL)); // create new random sequence based on time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    
    while(LevelDifficulty <= MaxDifficulty) // loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there ***\n";
    
    return 0;
}
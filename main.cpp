#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <limits>
#undef max

class Hangman
{
private:
    std:: string wordName{""} , wordHint{""}, answer{""}, wordType{""}, hanged[4]{"HARSHIT", "PRAKHAR", "ARYAN", "APOORVA"};
    std:: string keyboard = "\t\t  ___________________________________  \n"
                            "\t\t |              KEYBOARD             | \n"
                            "\t\t |- - - - - - - - - - - - - - - - - -| \n"
                            "\t\t | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | \n"
                            "\t\t | a | b | c | d | e | f | g | h | i | \n"
                            "\t\t | j | k | l | m | n | o | p | q | r | \n"
                            "\t\t | s | t | u | v | w | x | y | z | 0 | \n"
                            "\t\t |___________________________________| \n";

    int countHang{0};
    char ch{0};
    bool active{1}, flag{1}, tag{1};

public:
    // Hangman() - Main menu to link all functions
    // HintWord() - Word inputs
    // Rules () - pretty simple
    // HangBoard - the main display board
    // HangCheck - Draws main body of the Hangman and checks the numbers left
    // AgainMenu () - Final display menu

    bool exit {0};

    Hangman(){

        active = 1;
        while (active) {

            std::cout << "\t\t  ___________________________  \n"
                         "\t\t |        MAIN MENU          | \n"
                         "\t\t |       - - - - - -         | \n"
                         "\t\t |                           | \n"
                         "\t\t |   - -XX - -      - - XX- -| \n"
                         "\t\t |      :    HANGMAN     :   | \n"
                         "\t\t |      :                :   | \n"
                         "\t\t |      O    1.PLAY      O   | \n"
                         "\t\t |     /|\              /|\  | \n"
                         "\t\t |      |    2.RULES     |   | \n"
                         "\t\t |     / \              / \  | \n"
                         "\t\t |           3.EXIT          | \n"
                         "\t\t |___________________________| \n\n\n"
                         "\t\t     -->";

            std::cin >> ch;
            if (ch=='1'){
                //active = 0;
                system ("CLS");
                HintWord();
            }
            else if (ch=='2'){
                //active = 0;
                system ("CLS");
                Rules();
            }
            else if (ch=='3'){
                //active = 0;
                system ("CLS");
                exit = 1;
            }
            else{
                system ("CLS");
            }
        }

    };

    inline void Rules(){

        std::cout << "\n\n\t\t                                        ~WELCOME~                                          \n"
            "\n\n\t\t  ------------------------------------------------------------------------------------------ \n"
            "\n\n\t\t  (1)Choose one person to be the 'host.' This is the person that invents the puzzle          \n"
            "\t\t  for the other person to solve. They will be tasked with choosing a word that 'the players'     \n"
            "\t\t  will have to solve.                                                                            \n\n"
            "\t\t  The host should be able to spell confidently or the game will be impossible to win.            \n\n"
            "\t\t  (2)If you are the host, choose a secret word. The other players will need to guess your        \n"
            "\t\t  word letter by letter, so choose a word you think will be difficult to guess. Difficult        \n"
            "\t\t  words usually have uncommon letters, like 'z,' or 'j,' and only a few vowels.                  \n\n"
            "\t\t  (3)Start guessing letters if you are the player. Once the word has been chosen and the         \n"
            "\t\t  players know how many letters in the secret word, begin playing by entering which letters      \n"
            "\t\t  are in the word.                                                                               \n\n"
            "\t\t  (4)Whenever the players guess a letter that is not in the secret word they get a strike        \n"
            "\t\t  that brings them closer to losing. To show this, the game draws a simple stick figure of a     \n"
            "\t\t  man being hung, adding a new part to the drawing with every wrong answer.                      \n\n\n"
            "\t\t                                    *** 1.  Go Back.                                             \n"
            "\t\t  ------------------------------------------------------------------------------------------     \n"
            "\t\t                                     -->";

        std::cin >> ch;
        if (ch== '1'){
            //active = 0;
            system("CLS");
            Hangman();
        }
        else {
            system("CLS");
        }

    }

        inline void HintWord(){
            std::cout << "\n\n\t\t Host, Enter the secret word to be deciphered: \t\t\n"
                "\t\t            -->";
            std::cin >> wordName;
            std::transform(wordName.begin(), wordName.end(), wordName.begin(), tolower);
            std::cout << std::endl;
            std::cout << "\t\t Enter word type \n"
                "\t\t            -->";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline (std::cin, wordType);
            std::cout<< std::endl;

            std::cout<< "\t\t *Enter Hint* --> ";

            std::getline(std::cin, wordHint);

            for(unsigned i=0; i<wordName.length(); ++i)
                answer+= "_";

            system("CLS");
            HangBoard();

        }

        inline void HangBoard(){

            int i=0;
            active = 1;

            while(active){
                HangCheck();
                std::cout<< "\t\t ~TYPE~" << wordType << "\t\t";
                for(unsigned i=0; i< wordName.length(); ++i){
                    std::cout << answer[i] << " ";
                }
                std::cout << "\n\n\t\t HINT " << wordHint << "\n\n";
                std::cout << "\t\t\t\t\t\t\t (*) '#' Shown on the keyboard means it already has been tried.";
                std::cout << "\t\t\t\t\t\\t\t (*) Enter '.' to exit ";
                std::cout << "\n\n" << keyboard;


                if (flag==1){
                    std::cout<< "\t\t   ~X~ -->"; std::cin >> ch;
                }
                else {
                    std::cout << "\t\t\ ~O~ -->"; std::cin >> ch;
                }

                if (ch == '.'){
                    system ("CLS");
                    Hangman();
                    //active=0;
                    break;
                }
                if (ch <=90 && ch>= 65)
                    ch += 32;

                i = wordName.find(ch);
                while (wordName.find (ch, i)!= std:: string:: npos){
                    answer [wordName.find(ch, i)] = ch;
                    ++i;
                }
                if (wordName.find(ch) == std:: string::npos){
                    countHang++;
                    std::cout<< "\a";
                }
                if(countHang == 6){
                    system("CLS");
                    AgainMenu();
                }
                else if (answer == wordName){
                    system ("CLS");
                    AgainMenu();
                }
                system("CLS");
            }
        }

            inline void AgainMenu(){
                active = 1;
                while(active) {
                    if (countHang== 6){
                        std::cout<< "\t\t _____________________________\n"
                               "\t\t|         "<<std:: setw(5) << hanged[rand()% 5] << " DIED!"
                               "\t\t|         ------------        |\n"
                               "\t\t|                             |\n"
                               "\t\t|                             |\n"
                               "\t\t|          ( R.I.P )          |\n"
                               "\t\t|                             |\n"
                               "\t\t|                             |\n"
                               "\t\t|          1. Play Again      |\n"
                               "\t\t|          2. Exit            |\n"
                               "\t\t|_____________________________|\n";
                    }
                    else {
                        std::cout<< "\t\t_____________________________ \n"
                                    "\t\t|           "<< std::setw(5)<< hanged[rand()%5]<< "LIVES!"
                                    "\t\t|           --------         |\n"
                                    "\t\t|                 _____      |\n"
                                    "\t\t|           \O/ _/YEAH!\     |\n"
                                    "\t\t|            |   \_____/     |\n"
                                    "\t\t|           / \              |\n"
                                    "\t\t|                            |\n"
                                    "\t\t|        1. Play Again       |\n"
                                    "\t\t|        2. Exit             |\n"
                                    "\t\t|                            |\n"
                                    "\t\t|____________________________|\n\n\n";

                    }
                    std::cout << "\t\t     -->";
                    std::cin >> ch;
                    if( ch=='1'){
                        active = 0;
                        system ("CLS");
                        countHang = 0;
                        flag = 1;
                        tag = 1;
                        wordName = "0";
                        wordHint = "0";
                        answer ="";
                        wordType ="0";
         keyboard = "\t\t  ___________________________________  \n"
                    "\t\t |             KEYBOARD              | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t | a | b | c | d | e | f | g | h | i | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t | j | k | l | m | n | o | p | q | r | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t | s | t | u | v | w | x | y | z | 0 | \n"
                    "\t\t |-----------------------------------| \n"
                    "\t\t |___________________________________| \n";
                HintWord();
            }
            else if (ch=='2'){
                system("CLS");
                active = 0;
                exit = 1;
            }
            else {system ("CLS");}
                    }
                }

            inline void HangCheck(){

                if (countHang == 0){
                    std:: cout<< "/t/t  ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |                           \n"
                "\t\t    |                           \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 1) {
            std::cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |                           \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 2) {
            std::cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |      |                    \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 3) {
            std::cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |      |\                   \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 4) {
            std::cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |     /|\                   \n"
                "\t\t    |                           \n"
                "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 5) {
            std::cout << "\t\t     ______                     \n"
                         "\t\t    |      |                    \n"
                         "\t\t    |      :                    \n"
                         "\t\t    |      O                    \n"
                         "\t\t    |     /|\                   \n"
                         "\t\t    |     /                     \n"
                         "\t\t ___|___                        \n\n\n";
        }
        else if (countHang == 6) {
            std::cout << "\t\t     ______                     \n"
                "\t\t    |      |                    \n"
                "\t\t    |      :                    \n"
                "\t\t    |      O                    \n"
                "\t\t    |     /|\                   \n"
                "\t\t    |     / \                   \n"
                "\t\t ___|___                        \n\n\n";
        }

                }
            };


        int main(){


            Hangman game ;
            if (game.exit == 1) return 0;
            std::cin.get();
            return 0;
        }









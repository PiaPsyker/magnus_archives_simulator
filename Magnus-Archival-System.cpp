#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "player.h"

void credits() {
    std::cout << "\n" << std::endl;
    std::cout << "\t\t\t\t\t���������������������������ͻ" << std::endl;
    std::cout << "\t\t\t\t\t� Lead Developer: PiaPsyker �" << std::endl;
    std::cout << "\t\t\t\t\t� Art: PiaPsyker            �" << std::endl;
    std::cout << "\t\t\t\t\t� Art: Fliedi               �" << std::endl;
    std::cout << "\t\t\t\t\t� Inspiration: Fliedi       �" << std::endl;
    std::cout << "\t\t\t\t\t� Mental Support: Fliedi    �" << std::endl;
    std::cout << "\t\t\t\t\t� <3                        �" << std::endl;
    std::cout << "\t\t\t\t\t���������������������������ͼ" << std::endl;
    std::cout << "\n";
}


void initial() {
    std::cout << "\n" << std::endl;
    std::cout << "\t\t\t\t\t������������������������ͻ" << std::endl;
    std::cout << "\t\t\t\t\t�                        �" << std::endl;
    std::cout << "\t\t\t\t\t�     Welcome to the     �" << std::endl;
    std::cout << "\t\t\t\t\t�    Magnus Institute    �" << std::endl;
    std::cout << "\t\t\t\t\t�  Archive - Simulator   �" << std::endl;
    std::cout << "\t\t\t\t\t�                        �" << std::endl;
    std::cout << "\t\t\t\t\t������������������������ͼ" << std::endl;
    std::cout << "\n";
}

void show_options() {
    std::cout << "\t\t\t\t\t�> [1] Record new statement" << std::endl;
    std::cout << "\t\t\t\t\t�> [2] Read statement" << std::endl;
    std::cout << "\t\t\t\t\t�> [3] Research" << std::endl;
    std::cout << "\n" << std::endl;
    std::string io;
    while (io != "1" && io != "2" && io != "3") {
        std::cout << ">>>> Choose an Option:\n�> ";
        std::getline(std::cin, io);
    }
    if (io == "1") {
        std::cout << "\t\t\t\t\t>>>> RECORD NEW STATEMENT <<<<" << std::endl;
    } else if (io == "2") {
        std::cout << "\t\t\t\t\t>>>> READ STATEMENT <<<<" << std::endl;
    } else {
        std::cout << "\t\t\t\t\t>>>> RESEARCH <<<<" << std::endl;
    }
}

int title_screen() {
    std::cout << "\t\t\t\t\t�> [1] New User" << std::endl;
    std::cout << "\t\t\t\t\t�> [2] Load User" << std::endl;
    std::cout << "\t\t\t\t\t�> [3] Credits" << std::endl;
    std::cout << "\t\t\t\t\t�> [4] Exit" << std::endl;
    std::cout << "\n" << std::endl;
    std::string io;                                             // TODO Find out why ALT+ 2 6 breaks the code?
    while (io != "1" && io != "2" && io != "3") {
        std::cout << ">>>> Choose an Option:\n�> ";
        std::getline(std::cin, io);
    }
    if (io == "1") {
        std::cout << "\t\t\t\t\t>>>> NEW USER <<<<" << std::endl;
        return 1;
    } else if (io == "2") {
        std::cout << "NOT AVAILABLE" << std::endl;
        return 2;
    } else if (io == "3") {
        credits();
        title_screen();     // TODO Check if better version of this shit exists
    }
    else {
        std::cout << "EXITING..." << std::endl;
        exit(0);
    }
}

void record_statement();

void read_statement();

void research();

int main()
{
    // Starts the title screen
    initial();

    // Sets game state to chosen option
    int game_state = title_screen();
    
    // Initalize Player Object
    Player player;
    std::string pname;
    int page;
    std::string pgender;
    std::string ppronouns;
    int pjob;
    int pavatar;

    // I WAKE UP TO THE SOUNDS
    // Load save file 
    std::ofstream sfile;

    // Exiting game state
    while (game_state == 0) {
        std::cout << "EXITING..." << std::endl;
        exit(0);
    }
    // New game
    while (game_state == 1) {
        
        // Sets player name and writes to save file
        std::cout << "\n>>>> What is your name?\n�> ";
        std::getline(std::cin, pname);
        player.set_name(pname);
        // Opens save file for new player
        sfile.open(pname +".bin", std::ios::out | std::ios::trunc | std::ios::binary);
        sfile << pname << "\n";

        // Sets player age and writes to save file
        std::cout << "\n>>>> What is your age?\n�> ";
        std::string age;
        std::getline(std::cin, age);
        page = std::stoi(age);
        player.set_age(page);
        sfile << page << "\n";

        // Sets players gender and writes to save file
        std::cout << "\n>>>> What is your gender?\n�> ";
        std::getline(std::cin, pgender);
        player.set_gender(pgender);
        sfile << pgender << "\n";

        // Sets players pronouns and checks if syntax works and writes to save file
        while (ppronouns.find("/") == std::string::npos) {
            std::cout << "\n>>>> What are your pronouns?\n(Divided by / )\n�> ";
            std::getline(std::cin, ppronouns);
        }
        player.set_pronouns(ppronouns);
        sfile << ppronouns << "\n";

        // TODO Job
        
        // Sets game state for save file to 5
        sfile << "5" << "\n";

        sfile.close();

        // Sets game state to main state
        std::cout << "\n\t\t\t\t\t>>>> NEW USER '" << pname << "' CREATED" << std::endl;
        game_state = 5;
    }
    // Load game
    while (game_state == 2) {
        // TODO
    }

    // Main game state
    while (game_state == 5) {
        show_options();
    }

    return 0;
}

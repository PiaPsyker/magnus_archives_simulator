#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "player.h"

void credits() {
    std::cout << "\n" << std::endl;
    std::cout << "\t\t\t\t\tษอออออออออออออออออออออออออออออออป" << std::endl;
    std::cout << "\t\t\t\t\tบ Lead Developer: PiaPsyker     บ" << std::endl;
    std::cout << "\t\t\t\t\tบ Assisting Developer: BlckBrst บ" << std::endl;
    std::cout << "\t\t\t\t\tบ Art: PiaPsyker                บ" << std::endl;
    std::cout << "\t\t\t\t\tบ Art: Fliedi                   บ" << std::endl;
    std::cout << "\t\t\t\t\tบ Inspiration: Fliedi           บ" << std::endl;
    std::cout << "\t\t\t\t\tบ Mental Support: Fliedi        บ" << std::endl;
    std::cout << "\t\t\t\t\tบ <3                            บ" << std::endl;
    std::cout << "\t\t\t\t\tศอออออออออออออออออออออออออออออออผ" << std::endl;
    std::cout << "\n";
}

void initial() {
    std::cout << "\n" << std::endl;
    std::cout << "\t\t\t\t\tษออออออออออออออออออออออออป" << std::endl;
    std::cout << "\t\t\t\t\tบ                        บ" << std::endl;
    std::cout << "\t\t\t\t\tบ     Welcome to the     บ" << std::endl;
    std::cout << "\t\t\t\t\tบ    Magnus Institute    บ" << std::endl;
    std::cout << "\t\t\t\t\tบ  Archive - Simulator   บ" << std::endl;
    std::cout << "\t\t\t\t\tบ                        บ" << std::endl;
    std::cout << "\t\t\t\t\tศออออออออออออออออออออออออผ" << std::endl;
    std::cout << "\n";
}

void record_statement(std::string date) {
    // Author
    // Statement Giver
    // Type of Statement
    // Subject / Short Description
    std::ofstream statement;
    // TODO Set name to in-game date
    statement.open(date+".txt", std::ios::out | std::ios::trunc);

    std::string author;
    std::string statement_giver;
    std::string subject;
    std::string statement_txt;
    std::string notes;

    std::cout << "\n>> NEW STATEMENT <<" << std::endl;
    std::cout << "\Recorded by: ";  // Jonathan Sims
    std::getline(std::cin, author);
    statement << "Recorded by: " + author + "\n";

    std::cout << "\nStatement giver: ";     //Nathan Watts
    std::getline(std::cin, statement_giver);
    statement << "Statement giver: " + statement_giver + "\n";

    std::cout << "\nSubject: ";
    std::getline(std::cin, subject);
    statement << "Subject: " + subject + "\n";

    std::cout << "\nStatement: ";
    std::getline(std::cin, statement_txt);
    statement << "Statement: " + statement_txt + "\n";

    std::cout << "\nAdditional Notes: ";
    std::getline(std::cin, notes);
    statement << "Additional Notes: " + notes + "\n";

    statement.close();
}

void read_statement();

void research();

void show_options() {
    std::cout << "\t\t\t\t\tอ> [1] Record new statement" << std::endl;
    std::cout << "\t\t\t\t\tอ> [2] Read statement" << std::endl;
    std::cout << "\t\t\t\t\tอ> [3] Research" << std::endl;
    std::cout << "\n" << std::endl;
    std::string io;
    std::string date = "0230222";
    while (io != "1" && io != "2" && io != "3") {
        std::cout << ">>>> Choose an Option:\nอ> ";
        std::getline(std::cin, io);
    }
    if (io == "1") {
        std::cout << "\t\t\t\t\t>>>> RECORD NEW STATEMENT <<<<" << std::endl;
        record_statement(date);
    } else if (io == "2") {
        std::cout << "\t\t\t\t\t>>>> READ STATEMENT <<<<" << std::endl;
        //read_statement();
    } else {
        std::cout << "\t\t\t\t\t>>>> RESEARCH <<<<" << std::endl;
        //research();
    }
}

int title_screen() {
    std::cout << "\t\t\t\t\tอ> [1] New User" << std::endl;
    std::cout << "\t\t\t\t\tอ> [2] Load User" << std::endl;
    std::cout << "\t\t\t\t\tอ> [3] Credits" << std::endl;
    std::cout << "\t\t\t\t\tอ> [4] Exit" << std::endl;
    std::cout << "\n" << std::endl;
    std::string io;                                             // TODO Find out why ALT+ 2 6 breaks the code?
    while (io != "1" && io != "2" && io != "3") {
        std::cout << ">>>> Choose an Option:\nอ> ";
        std::getline(std::cin, io);
    }
    if (io == "1") {
        std::cout << "\t\t\t\t\t>>>> NEW USER <<<<" << std::endl;
        return 1;
    } else if (io == "2") {
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

// TODO Time System #yyymmdd -A -B :: #8141206 June 12th 1841
//                            ^  ^ If multiple statements in one day

int main()
{
    // Starts the title screen
    initial();

    // Sets game state to chosen option
    int game_state = title_screen();
    
    // Initalize Player Object
    Player player;
    std::string pname;
    std::string page;
    std::string pgender;
    std::string ppronouns;
    std::string pjob;
    std::string pavatar;

    // I WAKE UP TO THE SOUNDS
    // Load save file 
    

    // Exiting game state
    while (game_state == 0) {
        std::cout << "EXITING..." << std::endl;
        exit(0);
    }

    // New game
    while (game_state == 1) {
        
        std::ofstream sfile;

        // Sets player name and writes to save file
        std::cout << "\n>>>> What is your name?\nอ> ";
        std::getline(std::cin, pname);
        player.set_name(pname);

        // Opens save file for new player
        sfile.open(pname +".bin", std::ios::out | std::ios::trunc | std::ios::binary);
        sfile << pname << "\n";

        // Sets player age and writes to save file
        std::cout << "\n>>>> What is your age?\nอ> ";
        std::getline(std::cin, page);
        player.set_age(page);
        sfile << page << "\n";

        // Sets players gender and writes to save file
        std::cout << "\n>>>> What is your gender?\nอ> ";
        std::getline(std::cin, pgender);
        player.set_gender(pgender);
        sfile << pgender << "\n";

        // Sets players pronouns and checks if syntax works and writes to save file
        while (ppronouns.find("/") == std::string::npos) {
            std::cout << "\n>>>> What are your pronouns?\n(Divided by / )\nอ> ";
            std::getline(std::cin, ppronouns);
        }
        player.set_pronouns(ppronouns);
        sfile << ppronouns << "\n";

        // Sets players job and writes to save file
        while (pjob != "0" && pjob != "1" && pjob != "2" && pjob != "3" && pjob != "4" && pjob != "5" && pjob != "6" && pjob != "7" && pjob != "8" && pjob != "98" && pjob != "99") {
            std::cout << "\n>>>> What is your Job at the Magnus Institute?\n\n[0] Archivist\n[1] Archival Assistant\n[2] Artifact Storage\n[3] Librarian\n[4] Researcher\n[5] Archive Security\n[6] Receptionist\n[7] Administrator\n[8] Janitor\n\nEnter Number of Jobอ> ";
            std::getline(std::cin, pjob);
        }
        player.set_job(pjob);
        sfile << pjob << "\n";

        pavatar = "0";
        sfile << pavatar << "\n";
        
        // Sets game state for save file to 5
        sfile << "5" << "\n";

        sfile.close();

        // Sets game state to main state
        std::cout << "\n\t\t\t\t\t>>>> NEW USER '" << pname << "' CREATED" << std::endl;
        game_state = 5;
    }

    // Load game
    while (game_state == 2) {

        std::string file_name;
        std::cout << "Which file to load?\n[Syntax 'player name.bin']\nอ> ";
        std::getline(std::cin, file_name);

        std::ifstream lfile(file_name);
        std::string line;
        std::string text[20];
        for (int i = 0; i < 20; i++) {
            getline(lfile, text[i]);
        }
        lfile.close();
        pname = text[0];
        page = text[1];
        pgender = text[2];
        ppronouns = text[3];
        pjob = text[4];
        pavatar = text[5];
        game_state = std::stoi(text[6]);
    }

    // Main game state
    while (game_state == 5) {
        show_options();
    }

    return 0;
}

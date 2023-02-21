#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "player.h"

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

void show_options() {
    std::cout << "\t\t\t\t\tอ> [1] Record new statement" << std::endl;
    std::cout << "\t\t\t\t\tอ> [2] Read statement" << std::endl;
    std::cout << "\t\t\t\t\tอ> [3] Research" << std::endl;
    std::cout << "\n" << std::endl;
    std::string io;
    while (io != "1" && io != "2" && io != "3") {
        std::cout << ">>>> Choose an Option:\nอ> ";
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

void new_game() {

}

int title_screen() {
    std::cout << "\t\t\t\t\tอ> [1] New User" << std::endl;
    std::cout << "\t\t\t\t\tอ> [2] Load User" << std::endl;
    std::cout << "\t\t\t\t\tอ> [3] Exit" << std::endl;
    std::cout << "\n" << std::endl;
    std::string io;
    while (io != "1" && io != "2" && io != "3") {
        std::cout << ">>>> Choose an Option:\nอ> ";
        std::getline(std::cin, io);
    }
    if (io == "1") {
        std::cout << "\t\t\t\t\t>>>> NEW USER <<<<" << std::endl;
        return 1;
    } else if (io == "2") {
        std::cout << "NOT AVAILABLE" << std::endl;
        return 2;
    } else {
        std::cout << "EXITING..." << std::endl;
        exit(0);
    }
}

void record_statement();

void read_statement();

void research();

int main()
{
    initial();
    int game_state = title_screen();
    Player player;
    std::string pname;
    int page;
    int pgender;
    std::string ppronouns;
    int pjob;
    int pavatar;

    std::ofstream sfile;
    while (game_state == 0) {
        std::cout << "EXITING..." << std::endl;
        exit(0)
    }
    while (game_state == 1) {

        sfile.open("1.bin", std::ios::out | std::ios::trunc | std::ios::binary);

        std::cout << "\n>>>>What is your name?\nอ> ";
        std::getline(std::cin, pname);
        player.set_name(pname);
        sfile << pname << "\n";

        std::cout << "\n>>>>What is your Age?\nอ> ";
        std::string age;
        std::getline(std::cin, age);
        page = std::stoi(age);
        player.set_age(page);
        sfile << page << "\n";

        // TODO Gender Question
        // TODO Pronouns Question
        // TODO Job
        
        sfile.close();
        std::cout << "\n\t\t\t\t\t>>>> NEW USER '" << pname << "' CREATED" << std::endl;
        game_state = 5;
    }
    while (game_state == 2) {
        // TODO
    }
    while (game_state == 5) {
        show_options();
    }
    return 0;
}

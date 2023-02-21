#include <iostream>
#include <stdlib.h>
#include <string>

class Player {
    std::string name;
    int age;
    std::string gender;
    std::string pronouns;
    int job;
    int avatar;

public:
    void set_name(std::string io_name) { name = io_name; };
    void set_age(int io_age) { age = io_age; };
    void set_gender(std::string io_gender) { gender = io_gender; };
    void set_pronouns(std::string io_pronouns) { pronouns = io_pronouns; };
    void set_job(int io_job) { job = io_job; };
    void set_avatar(int io_avatar) { avatar = io_avatar; };

    std::string get_name() { return name; };
    int get_age() { return age; };
    std::string get_gender() { return gender; };
    std::string get_pronouns() { return pronouns; };
    int get_job() { return job; };
    int get_avatar() { return avatar; };
};
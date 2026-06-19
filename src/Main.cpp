#include <iostream>
#include <fstream>
#include "Attributes/Type.h"
#include "Attributes/Form.h"
#include "Attributes/Attribute.h"
#include "Spells/Spell.h"  
#include "Spells/BasicSpell.h"

bool gameIsRunning = true;
std::string name;

void saveGame(std::string name){
    std::ofstream saveFile("save.txt");
     if (saveFile.is_open()) {
        saveFile << name << "\n";

        saveFile.close();
        std::cout << "[SUCCESS] Game saved to save.txt!\n";

    } else {
        std::cout << "[ERROR] Could not create save file.\n";
    }
}

void loadGame(std::string& name){
    std::ifstream saveFile("save.txt");

    if (saveFile.is_open()) {
        std::getline(saveFile,name);
        
        saveFile.close();
        std::cout << "[SUCCESS] Save state loaded perfectly!\n";
    } else {
        name = "";
        std::cout << "[NOTICE] No save state found. Starting new game\n";
    }
}

void deleteSave() {
    std::string path = "save.txt";
    
    if (std::remove(path.c_str()) == 0) {
        std::cout << "[SUCCESS] Save profile deleted permanently.\n";
    } else {
        std::cout << "[NOTICE] No save file found to delete.\n";
    }
}

void nameDec(){
    if(name == ""){
            std::cout << "Welcome to the humble magic town of Ignisgate.\n";
            std::cout << "What is your name young mage.\n";

            std::getline(std::cin,name);
        }else if(name != ""){
            std::cout << "Welcome back to Ignisgate, young " << name << "\n";
        }
}

void menue(){
    std::system("cls");
    loadGame(name);
    std::cout << "Reincarnated as a mage!\n";
    std::cout << "/Play to play\n/Tutorial for a tutorial\n/Options for options\n/Delete to delete save file\n/Exit to exit\n";

    while(true){
        std::string command;
        std::getline(std::cin,command);

        if(command == "/Play"){
            loadGame(name);
            nameDec();
            break;
        }
        else if(command == "/Delete"){
            deleteSave();
            menue();
            break;
        }
        else if(command == "/Exit"){
            saveGame(name);
            std::exit(0);
            break;
        }
        else{
            std::cout << "Incorrect Command, try Again\n";
        }
    }
}

void callForOptions(){
    std::cout << "What would you like to do now? (/Help for a list of options)\n";
    while(true){
        std::string command;
        std::getline(std::cin,command);

        if(command == "/Save"){
            saveGame(name);
            break;
        }
        else if(command == "/Help"){
            std::cout << "/Save to save current state\n/Menue to go back to the main menue\n/Exit to close the game (auto saves)";
            break;
        }
        else if(command == "/Menue"){
            menue();
            break;
        }
        else if(command == "/Exit"){
            saveGame(name);
            std::exit(0);
            break;
        }
        else{
            std::cout << "Incorrect Command, try Again\n";
        }
    }
}


int main(){
    menue();
    while(gameIsRunning){
        //BasicSpell spell(Type(TypeEnum::Fire),Form(FormEnum::Rod),{Attribute(AttributeEnum::Big),Attribute(AttributeEnum::Peirce),Attribute(AttributeEnum::Explode)});
        callForOptions();
    }
    
}


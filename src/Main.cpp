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
    std::ofstream saveFile("Save/save.txt");
     if (saveFile.is_open()) {
        saveFile << name << "\n";

        saveFile.close();
        std::cout << "[SUCCESS] Game saved to build/save.txt!\n";

    } else {
        std::cout << "[ERROR] Could not create save file.\n";
    }
}

void loadGame(std::string& name){
    std::ifstream saveFile("Save/save.txt");

    if (saveFile.is_open()) {
        std::getline(saveFile,name);
        
        saveFile.close();
        std::cout << "[SUCCESS] Save state loaded perfectly!\n";
    } else {
        std::cout << "[NOTICE] No save state found. Starting new game\n";
    }
}

void menue(){
    std::cout << "Reincarnated as a mage!\n";
    std::cout << "/Play to play\n/Tutorial for a tutorial\n/Options for options\n/Load to load\n";

    while(true){
        std::string command;
        std::getline(std::cin,command);

        if(command == "/Play"){
            break;
        }else if(command == "/Load"){
            loadGame(name);
            break;
        }else{
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
            std::cout << "STFU and play the game, its not rocket science dumbass";
            break;
        }
        else if(command == "/Menue"){
            menue();
            break;
        }
        else if(command == "/Exit"){
           std::exit(0);
            break;
        }
        else{
            std::cout << "Incorrect Command, try Again\n";
        }
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

int main(){
    menue();
    nameDec();
    while(gameIsRunning){
        //BasicSpell spell(Type(TypeEnum::Fire),Form(FormEnum::Rod),{Attribute(AttributeEnum::Big),Attribute(AttributeEnum::Peirce),Attribute(AttributeEnum::Explode)});
        callForOptions();
    }
    
}


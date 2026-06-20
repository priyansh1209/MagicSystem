#include <iostream>
#include <fstream>
#include "Attributes/Type.h"
#include "Attributes/Form.h"
#include "Attributes/Attribute.h"
#include "Spells/Spell.h"  
#include "Spells/BasicSpell.h"

bool gameIsRunning = true;
bool homeUnlocked = false;
std::string name;

void saveGame(){
    std::ofstream saveFile("save.txt");
     if (saveFile.is_open()) {
        saveFile << name << "\n";
        saveFile << homeUnlocked << "\n";

        saveFile.close();
        std::cout << "[SUCCESS] Game saved to save.txt!\n";

    } else {
        std::cout << "[ERROR] Could not create save file.\n";
    }
}

void loadGame(){
    std::ifstream saveFile("save.txt");

    if (saveFile.is_open()) {
        std::getline(saveFile,name);

        std::string tempBoolStr;
        std::getline(saveFile,tempBoolStr);

        if (tempBoolStr == "1") {
            homeUnlocked = true;
        } else {
            homeUnlocked = false;
        }
        
        saveFile.close();
        std::cout << "[SUCCESS] Save state loaded perfectly!\n";
    } else {
        name = "";
        homeUnlocked = true;
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

            std::cout << "Well " << name << " I hope Ignisgate treats you as good, I'd recommend taking a look at the Wizards Guild by typing /Navigate(Wizards_Guild). Good Luck out there!\n";
        }else if(name != ""){
            std::cout << "Welcome back to Ignisgate, young " << name << "\n";
        }
}

void menue(){
    std::system("cls");
    loadGame();
    std::cout << "Reincarnated as a mage!\n";
    std::cout << "/Play to play\n/Tutorial for a tutorial\n/Options for options\n/Delete to delete save file\n/Exit to exit\n";

    while(true){
        std::string command;
        std::getline(std::cin,command);

        if(command == "/Play"){
            loadGame();
            nameDec();
            break;
        }
        else if(command == "/Delete"){
            deleteSave();
            menue();
            break;
        }
        else if(command == "/Exit"){
            saveGame();
            std::exit(0);
            break;
        }
        else{
            std::cout << "Incorrect Command, try Again\n";
        }
    }
}

void PrintLocationNames(){
    std::cout << "Dungeon\nWizards_guild\nMagic_Academy\nGrand_Library\nHome\n";
}

void goToHome(){
    if(homeUnlocked == true){
        std::cout << "You walk into your abode, tired, but ready for the next task\n";
    }else{
        std::cout << "You walk around, looking for your home, but then you realise you just got here and dont have a home yet. Would you like to buy one for 300 gold.\n";
    }
    
}

void callForOptionsInTown(){
    std::cout << "What would you like to do now? (/Help for a list of options)\n";
    while(true){
        std::string command;
        std::getline(std::cin,command);

        if(command == "/Save"){
            saveGame();
            break;
        }
        else if(command == "/Help"){
            std::cout << "/Save to save current state\n/Menue to go back to the main menue\n/Exit to close the game (auto saves)\n/Navigate(location)\n/locations for list of locations\n";
            break;
        }
        else if(command == "/Menue"){
            menue();
            break;
        }
        else if(command == "/Exit"){
            saveGame();
            std::exit(0);
            break;
        }
         else if(command == "/Locations"){
            PrintLocationNames();
            std::exit(0);
            break;
        }
        else if(command == "/Navigate(Home)"){
            goToHome();
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
        callForOptionsInTown();
    }
    
}


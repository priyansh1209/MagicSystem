#include <iostream>
#include <thread>
#include <chrono> 
#include <fstream>
#include "Attributes/Type.h"
#include "Attributes/Form.h"
#include "Attributes/Attribute.h"
#include "Spells/Spell.h"  
#include "Spells/BasicSpell.h"

bool gameIsRunning = true;
bool homeUnlocked = false;
bool WizardID = false;
bool wizardGuildScene1 = true;
int dialogueWaitTime = 6;
std::string name;

void saveGame(){
    std::ofstream saveFile("save.txt");
     if (saveFile.is_open()) {
        saveFile << name << "\n";
        saveFile << homeUnlocked << "\n";
        saveFile << WizardID << "\n";
        saveFile << wizardGuildScene1 << "\n";

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
        } else if(tempBoolStr == "0") {
            homeUnlocked = false;
        } else{
            homeUnlocked = false;
        }

        std::getline(saveFile,tempBoolStr);

        if (tempBoolStr == "1") {
            WizardID = true;
        } else if(tempBoolStr == "0") {
            WizardID = false;
        } else{
            WizardID = false;
        }

        std::getline(saveFile,tempBoolStr);

        if (tempBoolStr == "1") {
            wizardGuildScene1 = true;
        } else if(tempBoolStr == "0") {
            wizardGuildScene1 = false;
        } else{
            wizardGuildScene1 = true;
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
    std::system("cls");
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
    std::cout << "/Play to play\n/Options for options\n/Delete to delete save file\n/Exit to exit\n";

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
    std::system("cls");
    if(homeUnlocked == true){
        std::cout << "You walk into your abode, tired, but ready for the next task\n";
    }else{
        std::cout << "You walk around, looking for your home, but then you realise you just got here and dont have a home yet. Would you like to buy one for 300 gold.\n";
    }
    
}

void goToWizardGuild(){
    std::system("cls");
    if(WizardID == true){
        std::cout << "Feature WIP";
    }else{
        if(wizardGuildScene1 == true){
            std::cout << "You arrive at the Wizards' Guild for the first time, its towering spires adorned with gleaming gold accents that shimmer beneath the harsh midday sun. As you step through the grand entrance, the muffled roar of excited conversation greets you, growing louder with every step toward the towering doors ahead..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime + 4));
            std::cout << "\n???:" << std::endl;
            std::cout << "hello sir! Welcome to the wizard guild of the great stronghold city of Ignisgate." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime));
            std::cout << "\n\033[3myou look around, too distracted by the majestic reception area of the guild to hear the stunted receptionist\033[23m" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime));
            std::cout << "\n???:" << std::endl;
            std::cout << "HELLO? SIR? ..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime));
            std::cout << "\nYou:" << std::endl;
            std::cout << "... oh. Um sorry I didnt hear you." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime));
            std::cout << "\nAveline:" << std::endl;
            std::cout << "Thats ok! My name is Aveline, Aveline Thorne. I am the repectionist at the wizards guild here!" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime));
            std::cout << "I havent seen you around here, did you just arrive in town?" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime));
            std::cout << "\nYou:" << std::endl;
            std::cout << "Um yes, I just arrived to Ignisgate this morning" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime));
            std::cout << "\nAveline:" << std::endl;
            std::cout << "Ah, well welcome to our wonderfull city." << std::endl;
            wizardGuildScene1 = false;
        }
        while(true){
            std::cout << "\nAveline:" << std::endl;
            std::cout << "Would you like to register with our guild today? (/Yes, /No)" << std::endl;
            std::string command;
            std::getline(std::cin,command);
            if(command == "/Yes"){
                std::cout << "...Updating Database" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime - 2));
                std::cout << "...Getting User Data From Database" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime - 2));
                std::cout << "...Writing Data To ID Card" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime - 2));
                std::cout << "...Finalising Details" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime - 2));
                std::cout << "\nAveline:" << std::endl;
                std::cout << "Ok Sir, here is you ID card, you can view this card at anytime you visit the guild by typing /ID. \nHope you have a good day and make sure to check out the dungeon if your looking for quick cash, or check the quest board (/Quests) for extra jobs" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTime + 2));
                std::system("cls");
                break;
            }else if(command == "/No"){
                std::cout << "\nAveline:" << std::endl;
                std::cout << "Ok sir, have a good day, come back to the guild when you are ready to make your ID, or need information!" << std::endl;
                std::system("cls");
                break;
            }else{
                std::cout << "Incorrect Command, Please Try Again!";
            }
        }
        
        
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
        else if(command == "/Navigate(Wizards_Guild)"){
            goToWizardGuild();
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


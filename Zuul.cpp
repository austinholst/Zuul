#include <iostream>
#include "room.h"
#include <vector>
#include <cstring>
#include <map>
using namespace std;

/*
 *Author: Austin Holst
 *Date: December 4th 2017
 *Code: Plays zuul game. Has five items and winning and loosing conditions
 */


//functions
void help();
void createItem(map<char*, Item*> &items_map);
void getItem(Item* item, char* name);
void printInventory();
void dropItem(char* item);
//Vectors
vector<room*> vect;
//map
map<char*, Item*> inventory_map;
map<char*, Item*> items_map;
//bool
bool hasSword = false;
bool hasShield = false;
bool hasPotion = false;
bool hasArrows = false;
bool hasBow = false;

int main() {
  map<char*, Item*> items_map;
  //Creating rooms
  room* Forest1 = new room("You are in a forest, there is a cave off to the east");
  room* Forest2 = new room("You are in a forest");
  room* Forest3 = new room("You are in a forest, it looks like there is a bridge off to the west");
  room* Forest4 = new room("You are in a forest");
  room* Forest5 = new room("You are in a forest");
  room* Forest6 = new room("You are in a forest, there seems to be a cave to the north");
  room* Forest7 = new room("You are in a forest");
  room* Forest8 = new room("You are in a forest, there seems to be a cave to the north");
  room* Desert1 = new room("You are in a desert, there appears to be a large temple to the north");
  room* Desert2 = new room("You are in a desert, there is a bridge to the east");
  room* Cave1 = new room("You are in a damp cave");
  room* Cave2 = new room("You are in a damp cave");
  room* Cave3 = new room("You are in a damp cave");
  room* Mountain1 = new room("You are in a large mountain range, a huge castle stands to the west");
  room* Mountain2 = new room("You are in a large mountain range");
  room* Mountain3 = new room("You are in a large mountain range");
  room* Temple = new room("You are in an old temple");
  room* Bridge = new room("You are on an old rope bridge spanning over a canyon");
  room* Castle = new room("You are in a mysterious castle that reeks of danger");
  room* Current = Forest1;
  //Pushing back all the rooms
  vect.push_back(Forest1);
  vect.push_back(Forest2);
  vect.push_back(Forest3);
  vect.push_back(Forest4);
  vect.push_back(Forest5);
  vect.push_back(Forest6);
  vect.push_back(Forest7);
  vect.push_back(Forest8);
  vect.push_back(Desert1);
  vect.push_back(Desert2);
  vect.push_back(Cave1);
  vect.push_back(Cave2);
  vect.push_back(Cave3);
  vect.push_back(Mountain1);
  vect.push_back(Mountain2);
  vect.push_back(Mountain3);
  vect.push_back(Temple);
  vect.push_back(Bridge);
  vect.push_back(Castle);
  //setting exits
  Forest1-> setExit("East", Cave1);
  Forest1-> setExit("North", Forest3);
  Forest1-> setExit("West", Forest2);

  Forest2-> setExit("East", Forest1);
  Forest2-> setExit("West", Forest7);
  
  Forest3-> setExit("North", Forest4);
  Forest3-> setExit("South", Forest1);
  Forest3-> setExit("West", Bridge);

  Forest4-> setExit("South", Forest3);
  Forest4-> setExit("East", Forest5);

  Forest5-> setExit("North", Forest6);
  Forest5-> setExit("West", Forest4);

  Forest6-> setExit("North", Cave3);
  Forest6-> setExit("South", Forest5);

  Forest7-> setExit("North", Desert2);
  Forest7-> setExit("East", Forest2);

  Forest8-> setExit("North", Cave2);
  Forest8-> setExit("South", Desert2);

  Desert1-> setExit("North", Temple);
  Desert1-> setExit("East", Desert2);
  
  Desert2-> setExit("North", Forest8);
  Desert2-> setExit("South", Forest7);
  Desert2-> setExit("East", Bridge);
  Desert2-> setExit("West", Desert1);

  Cave1-> setExit("West", Forest1);
  
  Cave2-> setExit("South", Forest8);

  Cave3-> setExit("South", Forest6);
  Cave3-> setExit("West", Mountain3);

  Mountain1-> setExit("West", Castle);
  Mountain1-> setExit("East", Mountain2);

  Mountain2-> setExit("West", Mountain1);
  Mountain2-> setExit("East", Mountain3);

  Mountain3-> setExit("West", Mountain2);
  Mountain2-> setExit("East", Cave3);
  
  Bridge-> setExit("East", Forest3);
  Bridge-> setExit("West", Desert2);

  Temple-> setExit("South", Desert1);

  Castle-> setExit("Exits", Mountain1);

  createItem(items_map);
 
  //Putting items into their rooms
  Cave1-> addItem(items_map["sword"], "sword");
  Forest2-> addItem(items_map["shield"], "shield");
  Temple-> addItem(items_map["potion"], "potion");
  Cave2 -> addItem(items_map["bow"], "bow");
  Cave3 -> addItem(items_map["arrows"], "arrows");


  //Variables
  bool playing = true;
  
  help();
  cout << Current-> getDescription() << endl;
  Current-> getExit();

  char input[50];
  //While the game is running
  while(playing == true) {
    cin.getline(input, 50);
    //If you want to go somewhere
    if(strcmp(input, "go") == 0) {
      char direction[100];
      cout << "What direction do you want to go" << endl;
      cin.getline(direction, 100);
      room* newroom = Current-> exit(direction);
      if(newroom != NULL) {
	Current = newroom;
	if(Current == Forest2) {
	  if(hasSword == false) {
	    cout << "Without a sword to protect yourself you were killed by a monster" << endl;
	    playing = false;
	  }
	}
	if(Current == Temple) {
	  if(hasShield == false) {
	    cout << "A trap sends arrows flying at you and without a shield to protect you you were riddled with arrows and died a horrific death" << endl;
	    playing = false;
	  }
	}
	if(Current == Cave2) {
	  if(hasPotion == false) {
	    cout << "You were attacked by a bear and killed him. Without a potion to heal with though you bled out on the floor and died" << endl;
	    playing = false;
	  }
	}
	if(Current == Cave3) {
	  if(hasSword == false) {
	    cout << "A bandit was hiding in the cave and without a sword to defend yourself you were brutally murdered" << endl;
	    playing = false;
	  }
	}
	if(Current == Mountain1) {
	  if(hasBow == false || hasArrows == false) {
	    cout << "Theres a big castle but you need to shoot the bridge down with an arrow. Without a bow and arrows you sat there and died of boredom" << endl;
	    playing = false;
	  }
	}
	cout << Current-> getDescription() << endl;
	Current-> getExit();
	Current-> listItem();
	if(Current == Castle) {
	  cout << "There was a totally evil guy in the castle and you straight up murdered him without a second thought. I guess that means you win." << endl;
	  playing = false;
	}
      }
      else {
	cout << "You can't go that way...." << endl;
      }
    }
    //If you want to get an item
    else if(strcmp(input, "get") == 0) {
      char* item = new char[100];
      cout << "What item do you want to get" << endl;
      cin.getline(item, 100);
      //Putting the item into the inventory map
      getItem(items_map[item], item);
      //Deleting item from items map
      Current-> removeItem(item);
    }
    //If you want to drop an item
    else if(strcmp(input, "drop") == 0) {
      char item[100];
      cout << "What item would you like to drop" << endl;
      cin.getline(item, 100);
      Current-> addItem(inventory_map[item], item);
      dropItem(item);
    }
    //If you need help
    else if(strcmp(input, "help") == 0) {
      help();
    }
    //Access the inventory
    else if(strcmp(input, "inventory") == 0) {
      printInventory();
    }
    //If you want to quit
    else if(strcmp(input, "quit") == 0) {
      cout << "The game has ended" << endl;
      playing = false;
    }
    //If none of the above
    else {
      cout << "You can't do that" << endl;
    }
  }
  return 0;
}

//Help function for game
void help() {
  cout << "Welcome to Zuul. On your adventures you will need the following commands" << endl;
  cout << "go - input this and then after prompted input a direction to go that direction" << endl;
  cout << "get - input this and then after promted input an item to get that item" << endl;
  cout << "drop - input this and then after prompted input an item from your inventory to drop it" << endl;
  cout << "help - input this to see this screen again" << endl;
  cout << "Inventory - input this to see what items you have" << endl;
  cout << "quit - input this to end the game" << endl;
  cout << "" << endl;
}
//Creates all the items
void createItem(map<char*, Item*> &items_map) {
  Item* sword = new Item;
  sword-> itemName = "sword";

  Item* shield = new Item;
  shield-> itemName = "shield";

  Item* potion = new Item;
  potion-> itemName = "potion";

  Item* bow = new Item;
  bow-> itemName = "bow";

  Item* arrows = new Item;
  arrows-> itemName = "arrows";
}
//Picks up items
void  getItem(Item* item, char* name) {
  if(strcmp(name, "sword") == 0) {
    inventory_map[name] = item;
    hasSword = true;
  }
  else if(strcmp(name, "shield") == 0) {
    inventory_map[name] = item;
    hasShield = true;
  }
  else if(strcmp(name, "potion") == 0) {
    inventory_map[name] = item;
    hasPotion = true;
  }
  else if(strcmp(name, "bow") == 0) {
    inventory_map[name] = item;
    hasBow = true;
  }
  else if(strcmp(name, "arrows") == 0) {
    inventory_map[name] = item;
    hasArrows = true;
  }
  else {
    cout << "That item isn't here..." << endl;
  }
}


void printInventory() {
  cout << "Your items: " << endl;
  for(map<char*, Item*>::iterator it = inventory_map.begin(); it != inventory_map.end(); it++) {
    cout << it-> first << endl;
  }
}

//This function does not work but IDK how to fix it
void dropItem(char* item) {
  if(strcmp(item, "sword") == 0) {
    inventory_map.erase("sword");
  }
  else if(strcmp(item, "shield") == 0) {
    inventory_map.erase("shield");
  }
  else if(strcmp(item, "potion") == 0) {
    inventory_map.erase("potion");
  }
  else if(strcmp(item, "bow") == 0) {
    inventory_map.erase("bow");
  }
  else if(strcmp(item, "arrows") == 0) {
    inventory_map.erase("arrows");
  }
}

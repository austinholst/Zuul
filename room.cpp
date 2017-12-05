#include <iostream>
#include "room.h"
#include <map>
#include <cstring>

/*
 *This is the cpp file for the room class
 */

using namespace std;
//all rooms have descriptions
room::room(char* newDescription) {
  description = newDescription;
}
//getting description
char* room::getDescription() {
  return description;
}
//setting exits
void room::setExit(char* direction, room* room) {
  exits_map[direction] = room;
}
//getting the exits to cout
void room::getExit() {
  cout << "Exits:" << endl;
  for(map<char*, room*>::iterator it = exits_map.begin(); it != exits_map.end(); it++) {
    cout << it->first << endl;
  }
}
//exiting a room
room* room::exit(char* direction) {
  //map iterator
  for(map<char*, room*>::iterator it = exits_map.begin(); it != exits_map.end(); it++) {
    //string compare direction and it-> first
    if(strcmp(direction, it->first) == 0) {
      return exits_map[it-> first];
    }
  }
  if(exits_map.find(direction) == exits_map.end()) {
    cout << "You can't go that way..." << endl;
    return NULL;
  }
}
//add items
void room::addItem(Item* item, char* name) {
  items_map[name] = item; 
}
//cout the items
void room::listItem() {
  cout << "Items:" << endl;
  for(map<char*, Item*>::iterator it = items_map.begin(); it != items_map.end(); it++) {
    cout << it->first << endl;
  }
}
//remove item once in inventory
void room::removeItem(char* item) {
  if(strcmp(item, "sword") == 0) {
    items_map.erase("sword");
  }
  else if(strcmp(item, "shield") == 0) {
    items_map.erase("shield");
  }
  else if(strcmp(item, "potion") == 0) {
    items_map.erase("potion");
  }
  else if(strcmp(item, "bow") == 0) {
    items_map.erase("bow");
  }
  else if(strcmp(item, "arrows") == 0) {
    items_map.erase("arrows");
  }
}

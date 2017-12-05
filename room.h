#include <iostream>
#include <map>

using namespace std;

/*
 *This is the h file for the room class
 */

//Struct for Items                                                             
struct Item {
  char* itemName;
};

class room {
 public:
  room(char* description);
  char* getDescription();
  void setExit(char*, room*);
  void getExit();
  room* exit(char*);
  void addItem(Item*, char*);
  void listItem();
  void getItem(Item*, char*);
  void removeItem(char*);
 private:
  char* description;
  map<char*, room*> exits_map;
  map<char*, Item*> items_map;
};

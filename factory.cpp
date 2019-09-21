#include <iostream>
#include <string>
using namespace std;

class toy {
public:
   toy(){}
   string toyName;
   static toy* getToy(int);
};
class dinosaur : public toy {
public:
   dinosaur() {
      toyName = "dinoSaur";
   }
};
class car : public toy {
public:
   car() {
      toyName = "car";
   }
};

toy* toy::getToy(int id) {
   if (id == 1) 
       return new dinosaur();
   else if(id == 2)
       return new car();
   return nullptr;
}

int main() {
toy* carPtr = toy::getToy(2);
cout<<carPtr->toyName<<endl;
toy* dsrPtr = toy::getToy(1);
cout<<dsrPtr->toyName<<endl;
return 0;
}

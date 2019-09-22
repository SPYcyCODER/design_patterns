#include <iostream>
#include <string>
#include <vector>
using namespace std;

class feed {
public:
   feed() = default;
   ~feed() = default;
   virtual void receiveUpdate(string) = 0;
};

class follower1 : public feed {
public:
   void receiveUpdate(string feedUpdate) {
      cout << "Follower 1 received update : "<<feedUpdate<<endl;
   }
};

class follower2 : public feed {
public:
   void receiveUpdate(string feedUpdate) {
      cout << "Follower 2 received update : "<<feedUpdate<<endl;
   }
};
class superstar {
private:
   vector<feed*> _followers;
public:
   //superstar() = default;
   //~superstar() = default;

   void allowToReceive(feed* fObj) {
      _followers.push_back(fObj);
   }

   void denyToReceive(feed* fObj) {
     _followers.erase(std::remove(_followers.begin(),_followers.end(),fObj),_followers.end());
   }

   void notify(string newPost) {
      for (int fInd = 0; fInd < _followers.size(); fInd++) {
              _followers[fInd]->receiveUpdate(newPost);
      }
   }
}; 
int main() {
   follower1* _follower1 = new follower1();
   follower2* _follower2 = new follower2();
   superstar* star = new superstar();
   star->allowToReceive(_follower1);
   star->allowToReceive(_follower2);
   star->notify("Hi all.");
   star->denyToReceive(_follower1);
   star->notify("How are you fellas.");
return 0;
}

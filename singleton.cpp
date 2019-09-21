#include <iostream>
#include <string>
using namespace std;

class singleton {
private:
    singleton(const singleton&) = delete; // Copy Constructor
    singleton& operator=(const singleton&) = delete; // Equal operator overloading
    singleton() = default; // defalut implementation
    static unique_ptr<singleton> _classPtr;
    string _message; 
public:
   static singleton& getInstance() {
      static once_flag m_once; // Used for call_once function, allow multiple calls but execute one
      std::call_once(m_once,[]() { _classPtr.reset(new singleton());});
      return *_classPtr.get();
   }
   void setMessage(string input) {
      _message = input;
   }
   void printMessage() {
      cout << "Message : "<< _message << endl;
   }
};
unique_ptr<singleton> singleton::_classPtr = nullptr;
int main() {
   singleton& obj1 = singleton::getInstance();
   obj1.setMessage("This is from first pointer.");
   obj1.printMessage();
   singleton& obj2 = singleton::getInstance();
   obj2.printMessage();
   return 0;
}

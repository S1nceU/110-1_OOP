#ifndef TOY_H
#define TOY_H
class Toy {
public:
  Toy(){
    
  }
  // constructor with parameter
  Toy(std::string name) { 
      this->_name = name;
    }

  // get the name of the toy
  std::string getName() const { 
      return _name;
    }

private:
  std::string _name;
};
#endif
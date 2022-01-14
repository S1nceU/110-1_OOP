#ifndef CAT_H
#define CAT_H
#include <string>
#include "toy.h"
class Cat {
public:
  Cat(){

  }
  Cat(std::string name, double weight) {
		
		if(name == "" || weight < 10 || weight > 50){
		  throw std::string("undefine.");
		}
		
		this->_name = name;
		this->_weight = weight;
		this->_toyAmount = 0;
		this->_toyCollections = NULL;
  }
  std::string getName() {
		return _name;
  }

  double getWeight() {
		return _weight;
  }

  void addNewToy(Toy const & toyName) {
	Toy* temp = new Toy[_toyAmount + 1];
	for(int i = 0; i < _toyAmount; i++){
		temp[i] = _toyCollections[i];
	}
	temp[_toyAmount] = toyName;
	if(_toyAmount){
		delete[] _toyCollections;
	}
	_toyCollections = temp;
	_toyAmount += 1;
  }

  Toy getToy(int index) const{
	  if(index >= _toyAmount || index < 0){
	  	throw std::string("undefined.");
	  }
	  return _toyCollections[index];
  }
  Cat & operator =(Cat const & c1){
	this->_name = c1._name;
	this->_weight = c1._weight;
	this->_toyAmount = c1._toyAmount;
	Toy * toyCollections = new Toy[c1._toyAmount];
	for(int i = 0; i < c1._toyAmount; i ++){
		toyCollections[i] = Toy(c1._toyCollections[i].getName());
	}
	this->_toyCollections = toyCollections;
	return *this;
  }

  Cat(Cat const & c1){
	this->_name = c1._name;
	this->_weight = c1._weight;
	this->_toyAmount = c1._toyAmount;
	Toy * toyCollections = new Toy[c1._toyAmount];
	for(int i = 0; i < c1._toyAmount; i ++){
		toyCollections[i] = Toy(c1._toyCollections[i].getName());
	}
	this->_toyCollections = toyCollections;
  }
  bool isHeavierThan(Cat const & other){
  		return this->_weight > other._weight;
  }
  ~Cat() {
	delete[] _toyCollections;
  }
private:
	std::string _name;
	double _weight;
	Toy* _toyCollections;
	int _toyAmount;
};

#endif
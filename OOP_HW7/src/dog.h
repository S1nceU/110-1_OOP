#ifndef DOG_H
#define DOG_H
#include <stdexcept>
#include "pet.h"
class Dog : public Pet {
    public:
        Dog(){}
        Dog(std::string naame,double weightt){
            if(weightt < 10 || weightt > 50){
                throw std::range_error("undefined.");
            }
            _name = naame;
            _weight = weightt;
        }
        void feed() override {
            _weight += 0.8;
            if(_weight > 50){
                throw std::out_of_range("undefined.");
            }
        }
        ~Dog() {}
        std::string name() const override{
            return _name;
        }
        double weight() const override{
            return _weight;
        }
    private:
        std::string _name;
        double _weight;
};

#endif
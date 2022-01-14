#ifndef CAT_H
#define CAT_H
#include <stdexcept>
#include "pet.h"
class Cat : public Pet{
    public:
        Cat(){}
        Cat(std::string name,double weight){
            if(weight < 2 || weight > 6){
                throw std::range_error("undefined.");
            }
            _name = name;
            _weight = weight;
        }
        ~Cat(){}
        void feed() override{
            _weight += 0.2;
            if(_weight > 6){
                throw std::out_of_range("undefined.");
            }
        }
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
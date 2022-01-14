#ifndef PET_H
#define PET_H
class Pet{
    public:
        Pet(){
            _name = "none";
            _weight = 0;
        }
        virtual std::string name()const = 0;
        virtual double weight()const = 0;
        virtual ~Pet(){}
        virtual void feed() = 0;
    private:
        std::string _name;
        double _weight;
};
#endif
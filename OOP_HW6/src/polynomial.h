#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <algorithm>
#include <vector>
#include "term.h"

class Polynomial {
private:
    std::vector<Term> _terms;
    int _degree;
    static bool compare(const Term &a,const Term &b){
        return a.exponent() < b.exponent();
    }
public:
    Polynomial(std::vector<Term> terms, int degree) {
        std::stable_sort(terms.begin(),terms.end(),compare); 
        printf("%d %d %d\n",terms[0].exponent(),terms[1].exponent(),terms[2].exponent());
        for(int i = 1;i < terms.size();i++){
           if(terms[i].exponent() == terms[i-1].exponent()){
                throw std::string("undefined.");
            }
        }
        
        int cou = 0;
        int t_size = terms.size();
        
        for(int fuck = 0;fuck < t_size;fuck++){
            if (terms[fuck].exponent() != cou){
                //printf("where my third %d  %d  %d\n",fuck,terms[fuck].exponent(),cou);
                terms.push_back(Term(0.0,cou));
                cou++;
                fuck--;
            }
            else {
                cou++;
                //printf("where my  %d\n",fuck);
            }
            //printf("%dtest\n",cou);
        }
        cou--;
        int xx = degree - cou;
        if(xx > 0){
            for (int i = 0;i < xx;i++){
                cou++;
                terms.push_back(Term(0.0,cou));
                cou++;
            }
            printf("test\n");
        }
        std::stable_sort(terms.begin(),terms.end(),compare);  
        _terms = terms;
        _degree = degree;
    }

    // get a term by exponent
    // If the term does not exist, return the term (0, exponent)
    Term term(int exponent) const {
        return _terms[exponent];
    }

    // get the degree
    int degree() const {
        return _degree;
    }
    // add two polynomials 123
    Polynomial operator+ (const Polynomial & q) const {
        int degree_copy = 0;
        std::vector<Term> p;
        degree_copy = std::max(this->_degree,q._degree);
        //printf("%f ^ %d\n",_terms[2].coefficient(),_terms[2].exponent());
        Polynomial p1 (this->_terms,degree_copy);
        Polynomial p2 (q._terms,degree_copy);
        //printf("%f %d\n",p2._terms[3].coefficient(),p2._terms[3].exponent());
        for (int i = 0;i <= degree_copy;i++){
            p.push_back(p1._terms[i] + p2._terms[i]); 
            //printf("%f %d\n",(p1._terms[i] + p2._terms[i]).coefficient(),i);
        }
        Polynomial fin_ans(p,degree_copy);
        return fin_ans;
    }

    // multiply by a term
    Polynomial operator* (Term t) const {
        std::vector<Term> p;
        int degree_copy = this->_degree + t.exponent();
        for(int i = 0;i <= this->_degree;i++){
            p.push_back(this->_terms[i] * t);
        }
        Polynomial fin_ans(p,degree_copy);
        return fin_ans;
    }

    // multiply by another Polynomial
    // Polynomial operator* (const Polynomial & q) const {
    //     int degree_copy = 0;
    //     std::vector<Term> p,w;
    //     degree_copy = this->_degree + q._degree;
    //     Polynomial p1 (this->_terms,degree_copy);
    //     Polynomial p2 (q._terms,degree_copy);
    //     for (int i = 0;i <= degree_copy;i++){
    //         p.push_back(p1._terms[i] * p2._terms[0]);
    //     }
    //     for (int i = 1;i <= degree_copy;i++){
    //         for (int j = 0;j <= degree_copy;j++){
    //             w.push_back(this->_terms[i] * q._terms[i]); 
    //         }
    //         for (int cin = i;cin < degree_copy;cin++){
    //             p[i] = p[i] + w[i];
    //         }
    //         w.clear();
    //     }
    //     Polynomial fin_ans(p,degree_copy);
    //     return fin_ans;
    // }
};

#endif
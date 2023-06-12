
#include "MagicalContainer.hpp"


using namespace ariel;
using namespace std;
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container):magicalContainer(container),pIter(0){
        
    }
    
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator& iter)
    :magicalContainer(iter.magicalContainer),pIter(iter.pIter){

    }
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator& other){
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't assign iterators with different container");
        }
        this->pIter = other.pIter;
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        MagicalContainer::PrimeIterator beginIter(magicalContainer);
        return beginIter;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        MagicalContainer::PrimeIterator endIter(magicalContainer);
        endIter.pIter =magicalContainer.primeIndexContainer.size();
        return endIter;
    }
    int& MagicalContainer::PrimeIterator::operator*() const{
        return magicalContainer.container[magicalContainer.primeIndexContainer[pIter]];
    }
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
        if(pIter==magicalContainer.primeIndexContainer.size()){
            throw runtime_error("can't increment beyond the end");
        }
        pIter++;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator& other) const {
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return this->pIter<other.pIter;
    }
    bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator& other) const{
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return other<(*this);
    }
    bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator& other) const{
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return !(*this<other) && !(*this>other);
    }
    bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator& other) const{
        if(&magicalContainer!= &other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return (*this<other) || (*this>other);
    }

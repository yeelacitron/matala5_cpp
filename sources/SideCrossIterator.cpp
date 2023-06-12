
#include "MagicalContainer.hpp"


using namespace ariel;
using namespace std;
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    :magicalContainer(container),placemnt(0),scIterbegin(0),scIterend((size_t)container.size()-1),inStart(true){}
    
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator& iter)
    :magicalContainer(iter.magicalContainer),placemnt(iter.placemnt),scIterbegin(iter.scIterbegin),scIterend(iter.scIterend),inStart(iter.inStart){

    }
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator& other){
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't assign iterators with different container");
        }
        this->scIterbegin = other.scIterbegin;
        this->scIterend = other.scIterend;
        this->placemnt = other.placemnt;
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        MagicalContainer::SideCrossIterator beginIter(magicalContainer);
        return beginIter;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        MagicalContainer::SideCrossIterator endIter(magicalContainer);
        endIter.placemnt = magicalContainer.container.size();
        return endIter;
    }
    int MagicalContainer::SideCrossIterator::operator*() const{
        if(inStart){
            return magicalContainer.container[magicalContainer.ascIndexContainer[scIterbegin]];
        }
        else{
            return magicalContainer.container[magicalContainer.ascIndexContainer[scIterend]];
        }
        
    }
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        if(placemnt==magicalContainer.size()){
            throw runtime_error("can't increment beyond the end");
        }
        if(inStart){
            scIterbegin++;
            inStart=false;
        }
        else{
            scIterend--;
            inStart=true;
        }
        placemnt++;
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator& other) const{
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return this->placemnt<other.placemnt;
    }
    bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator& other) const{
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return other<(*this);
    }
    bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator& other) const{
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return !(*this<other) && !(*this>other);
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator& other) const{
        if(&magicalContainer!= &other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return (*this<other) || (*this>other);
    }


#include "MagicalContainer.hpp"


using namespace ariel;
using namespace std;
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container):magicalContainer(container),ascIter(0){

    }
    
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator& iter)
    :magicalContainer(iter.magicalContainer),ascIter(iter.ascIter){

    }
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator& other){
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't assign iterators with different container");
        }
        this->ascIter = other.ascIter;
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        MagicalContainer::AscendingIterator beginIter(magicalContainer);
        return beginIter;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        MagicalContainer::AscendingIterator endIter(magicalContainer);
        endIter.ascIter= magicalContainer.container.size();
        return endIter;
    }
    int& MagicalContainer::AscendingIterator::operator*() const{
        return magicalContainer.container[magicalContainer.ascIndexContainer[ascIter]];
    }
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        if(ascIter==magicalContainer.size()){
            throw runtime_error("can't increment beyond the end");
        }
        ascIter++;
        return *this;
    }
    bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator& other) const{
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return this->ascIter<other.ascIter;
    }
    bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator& other) const{
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return other<(*this);
    }
    bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator& other) const{
        if(&magicalContainer!=&other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return !(*this<other) && !(*this>other);
    }
    bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator& other) const{
        if(&magicalContainer!= &other.magicalContainer){
            throw runtime_error("can't use operator on iterators with different container");
        }
        return (*this<other) || (*this>other);
    }

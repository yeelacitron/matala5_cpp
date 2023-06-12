#include "MagicalContainer.hpp"
#include <algorithm>
#include <cmath>

using namespace ariel;
using namespace std;
MagicalContainer::MagicalContainer(){

    
}

void MagicalContainer::addElement(int num){
    //insert the number to the container 
    container.emplace_back(num);
    size_t indexOfElement = container.size()-1;
    //insert the index of tne number to the ascIndexContainer so it is sorted 
    bool inserted = false;
    for(size_t i = 0; i<ascIndexContainer.size();i++){
        if(container[ascIndexContainer[i]]==num){
            return;
        }
        if(num<container[ascIndexContainer[i]]){
            ascIndexContainer.insert(ascIndexContainer.begin()+(int)i,indexOfElement);
            inserted = true;
            break;
        }
    }
    if(!inserted){
        ascIndexContainer.emplace_back(indexOfElement);
    }
    

    //insert the index of the number if its prime to the correct place so that is sorted
    if(isPrime(num)){
        
        inserted = false;
        
        for(size_t i = 0; i<primeIndexContainer.size();i++){
            if(num<container[primeIndexContainer[i]]){
                primeIndexContainer.insert(primeIndexContainer.begin()+(int)i,indexOfElement);
                inserted = true;
                break;
            }
        }
        if(!inserted){
            primeIndexContainer.emplace_back(indexOfElement);
        }

    }
}
int MagicalContainer::size() const{
    return container.size();
}
void MagicalContainer::removeElement(int num){
    auto itToRemove = find(container.begin(),container.end(), num);
    if(itToRemove==container.end()){
        throw runtime_error("can't remove a non-exiesting element");
    }
    // remove the index of the element from the primePtrContainer and update the indexes of the rest
    for(size_t i = 0; i<primeIndexContainer.size();i++){
        if(container[primeIndexContainer[i]]==num){
            primeIndexContainer.erase(primeIndexContainer.begin()+(int)i);
            for(size_t j =primeIndexContainer[i]+1 ;j<container.size();j++){
                decriseByOne(j,primeIndexContainer);
            }
            break;
        }
    }
    // remove the index of the element from the ascIndexContainer and update the indexes of the rest
    for(size_t i = 0; i<ascIndexContainer.size();i++){
        if(container[ascIndexContainer[i]]==num){
            ascIndexContainer.erase(ascIndexContainer.begin()+(int)i);
            for(size_t j =ascIndexContainer[i]+1 ;j<container.size();j++){
                decriseByOne(j,ascIndexContainer);
            }
            break;
        }
    }
    // remove the element from the container
    container.erase(itToRemove);

}
void MagicalContainer::decriseByOne(size_t index,vector<size_t> vec){
     for(size_t i=0 ;i<vec.size();i++){
        if(vec[i]==index){
            vec[i]--;
        }
    }
}
bool MagicalContainer::isPrime(const int &num) const{
    if(num==1){
        return false;
    }
    int squrt =sqrt(num);
    for(int i = 2; i<= squrt;++i){
        if(num%i==0){
            return false;
        }
    }
    return true;

}
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
namespace ariel{ 
    class MagicalContainer{
        private:
            std::vector<int> container;
            std::vector<size_t> primeIndexContainer;
            std::vector<size_t> ascIndexContainer;
            bool isPrime(const int &num) const;
            void decriseByOne(size_t index,std::vector<size_t> vec);
        public:
            MagicalContainer();
            void addElement(int num);
            int size() const;
            void removeElement(int num);
            class AscendingIterator{
                private:
                    MagicalContainer & magicalContainer;
                    size_t ascIter;
                public:
                    AscendingIterator();
                    AscendingIterator(MagicalContainer &continaier);
                    ~AscendingIterator()= default;
                    AscendingIterator(const AscendingIterator& iter);
                    AscendingIterator& operator=(const AscendingIterator& other);
                    AscendingIterator begin();
                    AscendingIterator end();
                    int& operator*() const;
                    AscendingIterator& operator++();
                    bool operator<(const AscendingIterator& other) const;
                    bool operator>(const AscendingIterator& other) const;
                    bool operator==(const AscendingIterator& other) const;
                    bool operator!=(const AscendingIterator& other) const;

            };
            class SideCrossIterator{
                private:
                    MagicalContainer & magicalContainer;
                    size_t scIterbegin;
                    size_t scIterend;
                    size_t placemnt;
                    bool inStart;
                public:
                    SideCrossIterator();
                    SideCrossIterator(MagicalContainer &continaier);
                    ~SideCrossIterator()= default;
                    SideCrossIterator(const SideCrossIterator& iter);
                    SideCrossIterator& operator=(const SideCrossIterator& other);
                    SideCrossIterator begin();
                    SideCrossIterator end();
                    int operator*() const;
                    SideCrossIterator& operator++();
                    bool operator<(const SideCrossIterator& other) const;
                    bool operator>(const SideCrossIterator& other) const;
                    bool operator==(const SideCrossIterator& other) const;
                    bool operator!=(const SideCrossIterator& other) const;
            };
            class PrimeIterator{
                private:
                    MagicalContainer & magicalContainer;
                    size_t pIter;
                public:
                    PrimeIterator();
                    PrimeIterator(MagicalContainer &continaier);
                    ~PrimeIterator()= default;
                    PrimeIterator(const PrimeIterator& iter);
                    PrimeIterator& operator=(const PrimeIterator& other);
                    PrimeIterator begin();
                    PrimeIterator end();
                    int& operator*() const;
                    PrimeIterator& operator++();
                    bool operator<(const PrimeIterator& other) const;
                    bool operator>(const PrimeIterator& other) const;
                    bool operator==(const PrimeIterator& other) const;
                    bool operator!=(const PrimeIterator& other) const;

            };
            

    };
}
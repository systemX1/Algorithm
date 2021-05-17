#pragma once
#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <utility>
using std::pair;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr; using std::make_shared;

#include <string>
using std::basic_string;

#include <fmt/core.h>
#include <fmt/format.h>

#include "Hash.h"

namespace sy
{
    template<class K, class V>
    class HashMap
    {
    public:
        explicit HashMap(int divisor_ = 13);
        ~HashMap() = default;

        bool isEmpty() const;
        bool isValidIndex(size_t idx) const;
        size_t getSize() const { return elem_n; }
        int getDivisor() const { return divisor; }
        int find(const K& key) const;               // return the idx of key
        size_t findBlank(const K& key) const;       // return the idx for key to be inserted
        void insert(const K& key, const V& val);
        void insert(const vector<pair<K, V> >& data);
        void insert(const pair<K, V>& data);
        void printTable() const;
        void printExtraInfo() const;
        void deleteElem(const K& key);
        void reset(int divisor_ = 13);
    
    private:
        vector<shared_ptr<pair<K, V> > > table; // hash table
        Hash<K> hash;                           // maps type K to a nonnegative integer
        size_t elem_n;                          // number of pairs in table
        int divisor;                            // hash function divisor
    };

    template<class K, class V>
    HashMap<K, V>::HashMap(int divisor_) : elem_n(0), divisor(divisor_)
    {
        table.resize(get_odd_next(static_cast<size_t>(divisor_) * 2));
    }

    template <class K, class V>
    bool HashMap<K, V>::isEmpty() const
    {
	    return elem_n == 0;
    }

    template<class K, class V>
    inline bool HashMap<K, V>::isValidIndex(size_t idx) const
    {
        return (idx >= 0) && (idx < table.size() );
    }

    template<class K, class V>
    int HashMap<K, V>::find(const K& key) const
    {
	    const size_t home = hash(key, divisor);     // home bucket

        fmt::print("{:<3} ", home);
        if (table[home] == nullptr)
            return static_cast<int>(home);
    	
        int i = static_cast<int>(home);             // d
        int j = 1;                                  // counter

        while(true)
        {
            i = static_cast<int>((home + static_cast<unsigned long long>(j) * j + table.size()) % table.size());
            if (isValidIndex(i))
            {
                if (table[i] == nullptr) {
                    fmt::print("( {0:} + {1:}*{1:} + {2:} ) % {2:} = {3:} ", home, j, table.size(), i);
                    return -1;
                }
                if (table[i]->first == key) {
                    fmt::print("( {0:} + {1:}*{1:} + {2:} ) % {2:} = {3:} ", home, j, table.size(), i);
                    return i;
                }
            }
        	
            i = static_cast<int>((home - static_cast<unsigned long long>(j) * j + table.size()) % table.size());
            if (isValidIndex(i))
            {
                if (table[i] == nullptr) {
                    fmt::print("( {0:} - {1:}*{1:} + {2:} ) % {2:} = {3:} ", home, j, table.size(), i);
                    return -1;
                }
                if (table[i]->first == key) {
                    fmt::print("( {0:} - {1:}*{1:} + {2:} ) % {2:} = {3:} ", home, j, table.size(), i);
                    return i;
                }
            }
            j++;
        }
    }

    template<class K, class V>
    inline size_t HashMap<K, V>::findBlank(const K& key) const
    {
        const size_t home = hash(key, divisor);     // home bucket

        fmt::print("{:<3} ", home);
        if(table[home] == nullptr)
            return home;
            
        int i = static_cast<int>(home);             // d
        int j = 1;                                  // counter
    	
        while (true)
        {
            i = static_cast<int>((home + static_cast<unsigned long long>(j) * j + table.size()) % table.size());
            if (isValidIndex(i))
            {
                
                if (table[i] == nullptr) {
                    fmt::print("( {0:} + {1:}*{1:} + {2:} ) % {2:} = {3:} ", home, j, table.size(), i);
                    return i;
                }
            }

            i = static_cast<int>((home - static_cast<unsigned long long>(j) * j + table.size()) % table.size());
            if (isValidIndex(i))
            {
                if (table[i] == nullptr) {
                    fmt::print("( {0:} - {1:}*{1:} + {2:} ) % {2:} = {3:} ", home, j, table.size(), i);
                    return i;
                }
            }
            j++;
        }
    }

    template<class K, class V>
    void HashMap<K, V>::insert(const K& key, const V& val)
    {
        elem_n++;
        if (elem_n >= table.size() / 2) {
            table.resize(get_odd_next(static_cast<size_t>(elem_n) * 2));
        }

        fmt::print("insert key {}:\t", key);
        size_t idx = findBlank(key);
        fmt::print("\n");
        table[idx] = make_shared<pair<K, V> >(key, val);
    }

    template<class K, class V>
    inline void HashMap<K, V>::insert(const vector<pair<K, V> >& data)
    {
    	for(const auto& i : data)
    	{
            insert(i.first, i.second);
    	}
    }

    template<class K, class V>
    inline void HashMap<K, V>::insert(const pair<K, V>& data)
    {
        insert(data.first, data.second);
    }

    template<class K, class V>
    void HashMap<K, V>::printTable() const
    {
        printExtraInfo();
        for(size_t i = 0; i < table.size(); i++)
        {
            if (i % 5 == 0)
                fmt::print("\nidx: {:<8}", i);
            if (table[i] != nullptr) {
                fmt::print(" {:<12}", *(table[i]) );
            }
            else {
                fmt::print(" {:<12}", "NULL");
            }
        }
        fmt::print("\n");
    }

    template<class K, class V>
    inline void sy::HashMap<K, V>::printExtraInfo() const
    {
        fmt::print("\nsize: {:<6} divisor: {:<6} length: {:<6} α: {:<6.4f}", 
            getSize(), getDivisor(), table.size(), 
            static_cast<double>(getSize()) / static_cast<double>(table.size() ) );
    }

    template<class K, class V>
    inline void sy::HashMap<K, V>::deleteElem(const K& key)
    {
        fmt::print("delete key {}:\t", key);
        size_t idx = find(key);
        fmt::print("{}\n", static_cast<int>(idx) == -1 ? "not exists" : "successful");
        table[idx] = nullptr;
        elem_n--;
    }

    template<class K, class V>
    inline void HashMap<K, V>::reset(int divisor_)
    {
        divisor = divisor_;
        for (auto& i : table)
            i = nullptr;
        vector<shared_ptr<pair<K, V> > > tmp(get_odd_next(static_cast<size_t>(divisor) * 2));
        tmp.swap(table);
        elem_n = 0;
    }


}

#endif

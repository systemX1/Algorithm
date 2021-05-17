#pragma once
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <utility>
#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <memory>
using std::shared_ptr; using std::make_shared;

#include "fmt/core.h"

#include "Hash.h"

namespace sy
{
    template<class E>
    class HashTableNode
    {
    public:
        explicit HashTableNode() : data() {}
        explicit HashTableNode(E elem) : data(std::move(elem)) {}
    private:
        E data;
        shared_ptr<HashTableNode<E> > next;

    template<class E_>
    friend class HashTable;
    };
	
    template<class E>
    class HashTable
    {
    public:
        explicit HashTable(int divisor_ = 13);
        ~HashTable() = default;

        bool isEmpty() const;
        bool isValidIndex(size_t idx) const;
        size_t getSize() const { return elem_n; }
        int getDivisor() const { return divisor; }
        void insert(const E& elem);
        void insert(const vector<E>& data);
        shared_ptr<HashTableNode<E>> find(const E& elem) const;   // return the prev node, return NULL if not found
        void printTable() const;
        void printExtraInfo() const;
        void deleteElem(const E& elem);
        void reset(int divisor_);

    private:
        vector<shared_ptr<HashTableNode<E> > > table;   // hash table
        Hash<E> hash;                               // maps type K to a nonnegative integer
        size_t elem_n;                              // number of pairs in table
        int divisor;                                // hash function divisor
    };


    template<class E>
    HashTable<E>::HashTable(int divisor_) : elem_n(0), divisor(divisor_)
    {
        table.resize(divisor_);
    }

    template <class E>
    bool HashTable<E>::isEmpty() const
    {
        return elem_n == 0;
    }

    template<class E>
    inline bool HashTable<E>::isValidIndex(size_t idx) const
    {
        return (idx >= 0) && (idx < table.size());
    }

    template<class E>
    inline void sy::HashTable<E>::insert(const E& elem)
    {
        const size_t home = hash(elem, divisor);
        if (!isValidIndex(home)) {
            fmt::print("Invalid Elem\n");
            return;
        }
        auto p = table[home];
        elem_n++;
    	
        if (p == nullptr) {
            table[home] = make_shared<HashTableNode<E> >(elem);
            return;
        }
    	
        while (p && p->next) {
            p = p->next;
        }
        p->next = make_shared<HashTableNode<E> >(elem);
    }

    template<class E>
    inline void sy::HashTable<E>::insert(const vector<E>& data)
    {
        for (const auto& i : data)
        {
            insert(i);
        }
    }

    // return the prev node
    template<class E>
    inline shared_ptr<HashTableNode<E>> HashTable<E>::find(const E& elem) const
    {
        const size_t home = hash(elem, divisor);
        if (!isValidIndex(home)) {
            fmt::print("Invalid Elem\n");
            return nullptr;
        }

        auto p = table[home];
        if (p == nullptr || p->data == elem)
            return p;

        while (p && p->next) {
            if (p->next->data == elem)
                return p;
            p = p->next;
        }
    	
        return nullptr;
    }

    template<class E>
    inline void sy::HashTable<E>::printTable() const
    {
        deque<E> deq;
    	for (size_t i = 0; i < table.size(); i++)
    	{
            if (i == 0)
                fmt::print("\n┌{0:─^{1}}┐", "", 5);
            fmt::print("\n│{1: ^{2}}│", "", i, 5);
    		if(table[i] != nullptr)
    		{
                for (auto p = table[i]; p; p = p->next)
                    fmt::print("{:->8}", p->data);
    		}
    		if(i == (table.size() - 1) )
				fmt::print("\n└{0:─^{1}}┘\n", "", 5);
    	}
    }

    template<class E>
    inline void HashTable<E>::printExtraInfo() const
    {
        fmt::print("\nsize: {:<6} divisor: {:<6} length: {:<6}", getSize(), getDivisor(), table.size());
    }

    template<class E>
    inline void sy::HashTable<E>::deleteElem(const E& elem)
    {
        auto prev = find(elem);
        auto home = hash(elem, divisor);
        if (prev == nullptr)                                // elem not found
            return;
        else if(prev == table[home] && prev->data == elem)  // elem is the head
            table[home] = prev->next;
        else
            prev->next = prev->next->next;
    }

    template<class E>
    inline void HashTable<E>::reset(int divisor_)
    {
        divisor = divisor_;
        for (auto& i : table)
            i = nullptr;
        vector<shared_ptr<HashTableNode<E> > > tmp(get_odd_next(divisor_) );
        tmp.swap(table);
        elem_n = 0;
    }

}

#endif


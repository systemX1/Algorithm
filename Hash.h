#pragma once
#ifndef HASH_H_
#define HASH_H_

#include <string>
using std::string;

#include <cmath>

namespace sy
{
    template <typename K>
    class Hash;

    template<>
    class Hash<string>
    {
    public:
        // Convert key to a nonnegative integer
        size_t operator()(const string& key, int divisor) const
        {
            if(key[0] > '0' && key[0] < '9')
                return (key[0] - '0') % divisor;
            return (key[0] - 'A') % divisor;
        }
    };

    template<>
    class Hash<int>
    {
    public:
        size_t operator()(const int key, int divisor) const
        {
            return static_cast<size_t>(key) % divisor;
        }
    };

    template<>
    class Hash<long>
    {
    public:
        size_t operator()(const long key, int divisor) const
        {
            return static_cast<size_t>(key) % divisor;
        }
    };


    inline size_t get_odd_next(size_t value) {
        size_t v_next = value;
        while (true) {
            auto v_next_sqrt = static_cast<size_t>(sqrt(v_next));

            bool is_odd = true;
            for (size_t v_dv = 2; v_dv < v_next_sqrt + 1; v_dv++) {
                if (v_next % v_dv == 0) {
                    is_odd = false;
                    break;
                }
            }

            if (is_odd)
                return v_next;

            v_next++;
        }
    }

}

#endif
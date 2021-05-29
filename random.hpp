#pragma once
#ifndef RANDOM_H_
#define RANDOM_H_

#include <random>

#include <vector>

namespace sy
{
	template <typename E>
	class random;

    template<>
    class random<int>
    {
    public:
        // Convert key to a nonnegative integer
        std::vector<int> operator()(int n, int low, int high) const
        {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> distribution(low, high);
        	
            std::vector<int> ret;
            ret.reserve(n);
            for (int i = 0; i < n; i++)
                ret.push_back(distribution(rng));

            return ret;
        }
    };
}

#endif


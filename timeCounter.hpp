#pragma once
#ifndef TIMECOUNTER_H_
#define TIMECOUNTER_H_

#include <chrono>

#include <functional>
using std::function;

#include <fmt/core.h>

namespace sy
{
	template<typename Func, typename... Args>
	struct timeCounter
	{
		timeCounter() = delete;
		timeCounter(function<Func>&& func, Args... args) {
			auto t_begin = std::chrono::system_clock::now();

			func(args);
			auto t_end = std::chrono::system_clock::now();
			std::chrono::duration<double, std::milli> fp_ms = t_end - t_begin;
			fmt::print("duration:{:>10}\n", fp_ms.count());
		}
	};
	
}

#endif

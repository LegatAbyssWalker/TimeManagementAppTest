#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <ctime>

template <typename Engine = std::mt19937>
class Random {
	template<typename T>
	using UniformDist = std::uniform_real_distribution<T>;
	using UniformIntDist = std::uniform_int_distribution<int>;

	public:
		static Random gRand;

		Random(int seed = std::time(nullptr))
			: engine(seed) {
		}

		int getInt(int low, int high) {
			return getNumberInRange<UniformIntDist>(low, high);
		}

		float getFloat(float low, float high) {
			return getNumberInRange<UniformDist<float>>(low, high);
		}

		template<typename T>
		T getNumberInRange(T low, T high) {
			return getNumberInRange<UniformDist<T>>(low, high);
		}

		template<typename Dist, typename T>
		T getNumberInRange(T low, T high) {
			Dist dist(low, high);
			return dist(engine);
		}

	private:
		Engine engine;
};
#endif
/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-05 */


#ifndef _SICT_LIST_H
#define _SICT_LIST_H

namespace sict {
	template <typename T, int N>
	class List {
		T arr[N];
		size_t num;

	public:
		List() :num{ 0u } {}
		size_t size() const {
			return num;
		}

		const T& operator[](size_t i) const {
			return arr[i];
		}

		void operator+=(const T& t) {
			if (num < N) {
				arr[num] = t;
				num++;
			}
		}
	};

	template <typename T, typename L, typename V, int N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
			V sumOfElements = SummableLVPair<L, V>::getInitialValue();

			for (size_t i = 0; i < this->size(); i++) {
				sumOfElements = (*this)[i].sum(label, sumOfElements);
			}

			return sumOfElements;
		}
	};
}
#endif
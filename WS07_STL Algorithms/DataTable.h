/*
 name: Youngeun Hong
 ID: 159100171
 Email: yhong38@myseneca.ca
 Date: 2019-07-03 */

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <algorithm>

extern int FW;  // field width
extern int ND;  // precision for numbers

namespace sict {
	template<typename T>
	class DataTable {
		std::vector<T> dataX;
		std::vector<T> dataY;
	public:
		DataTable(std::ifstream& srcData) {
			T x, y;
			while (srcData >> x >> y) {
				dataX.push_back(x);
				dataY.push_back(y);
			}			
		}		

		//sample mean -- the average of all values in the sample
		T mean() const {
			T accSum = std::accumulate(dataY.begin(), dataY.end(), (T)0);
			return accSum / dataY.size();
		}

		//sample standard deviation -- the spread of the numbers away from their mean
		T sigma() const {
			T m = mean();
			T tmp = 0.0;
			for (size_t i = 0; i < dataY.size(); i++)
				tmp += (dataY.at(i) - m) * (dataY.at(i) - m);			
			return std::sqrt(tmp / (dataY.size() - 1));
		}

		//sample median -- the middle number in the sorted set of the values
		T median() const {
			std::vector<T> tmp = dataY;
			std::sort(tmp.begin(), tmp.end());			
			return tmp[tmp.size() / 2];
		}

		//the slope of the line in the x-y plane
		T slope() const {
			T sizeX = dataX.size();
			T sizeY = dataY.size();
			T sumX = std::accumulate(dataX.begin(), dataX.end(), 0.0) / sizeX;
			T sumY = std::accumulate(dataY.begin(), dataY.end(), 0.0) / sizeY;
			T n = 0.0;
			T d = 0.0;

			for (size_t i = 0; i < sizeX; i++) {
				n += (dataX[i] - sumX) * (dataY[i] - sumY);
				d += (dataX[i] - sumX) * (dataX[i] - sumX);
			}
			return n/d;
		}

		//the y value of the line where it crosses the y-axis in the x-y plane
		T intercept() const {
			T sizeX = dataX.size();
			T sizeY = dataY.size();
			T sumX = std::accumulate(dataX.begin(), dataX.end(), 0.0) / sizeX;
			T sumY = std::accumulate(dataY.begin(), dataY.end(), 0.0) / sizeY;
			T n = 0.0;
			T d = 0.0;

			for (size_t i = 0; i < sizeX; i++) {
				n += (dataX[i] - sumX) * (dataY[i] - sumY);
				d += (dataX[i] - sumX) * (dataX[i] - sumX);
			}			
			return sumY - (slope() * sumX);
		}

		void displayData(std::ostream& os) const {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;

			os << std::setw(FW) << 'x' << std::setw(FW) << 'y' << std::endl;

			for (size_t i = 0; i < dataX.size(); i++) {
				os << std::setw(FW) << std::setprecision(ND) << std::fixed << dataX[i]
				   << std::setw(FW) << std::setprecision(ND) << std::fixed << dataY[i]
				   << std::endl;
			}	
			os << std::endl;
		}

		void displayStatistics(std::ostream& os) const {
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << "  y mean    = " << std::setw(FW) << mean() << std::endl;
			os << "  y sigma   = " << std::setw(FW) << sigma() << std::endl;
			os << "  y median  = " << std::setw(FW) << median() << std::endl;
			os << "  slope     = " << std::setw(FW) << slope() << std::endl;
			os << "  intercept = " << std::setw(FW) << intercept() << std::endl;
		}		
	};
}
#endif
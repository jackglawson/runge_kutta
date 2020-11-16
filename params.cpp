#include "params.h"

namespace p {
	double acc{ 0.001 };			// desired truncation error per step
	double S{ 10 };					// step-length cannot change by more than this factor from step to step
	int maxrept{ 10 };				// maximum allowable number of step recalculations
	double h_min{ 0.001 };			// minimum allowable step-length
	double h_max{ 1 };				// maximum allowable step-length
	int flag{ 2 };					// controls manner in which truncation error is calculated
									// flag = 0 ... error is absolute
									// flag = 1 ... error is relative
									// flag = 2 ... error is mixed
}
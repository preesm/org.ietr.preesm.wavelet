#ifndef FILTER_HPP
#define FILTER_HPP

#include "hls_math.h"
#include "hls_stream.h"

template<typename T>
void soft_threshold(hls::stream<T> &src, hls::stream<T> &snk) {
#pragma HLS PIPELINE II=1 style=flp
	T threshold_value = 1;

	T data = src.read();
	T filtered = fmaxf(data - threshold_value, 0);

	filtered = std::copysign(filtered, data);
	snk.write(filtered);
}

#endif //FILTER_HPP

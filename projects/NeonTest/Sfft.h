/*
 * Sfft.h
 *
 *  Created on: 18.03.2022
 *      Author: marius.baumann
 */

#ifndef SFFT_H_
#define SFFT_H_

#include <vector>
#include <array>
#include "constants.h"

std::vector<std::vector<float>> calcSFFT(std::vector<float> input);
std::vector<float> calcISFFT(std::vector<std::vector<float>> input, std::array<float, FFT_SIZE-AUDIO_BUFFER_SIZE>& overlapAddBuffer);

#endif /* SFFT_H_ */

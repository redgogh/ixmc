/* -------------------------------------------------------------------------------- *\
|*                                                                                  *|
|*    Copyright (C) 2019-2024 RedGogh All rights reserved.                          *|
|*                                                                                  *|
|*    Licensed under the Apache License, Version 2.0 (the "License");               *|
|*    you may not use this file except in compliance with the License.              *|
|*    You may obtain a copy of the License at                                       *|
|*                                                                                  *|
|*        http://www.apache.org/licenses/LICENSE-2.0                                *|
|*                                                                                  *|
|*    Unless required by applicable law or agreed to in writing, software           *|
|*    distributed under the License is distributed on an "AS IS" BASIS,             *|
|*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.      *|
|*    See the License for the specific language governing permissions and           *|
|*    limitations under the License.                                                *|
|*                                                                                  *|
\* -------------------------------------------------------------------------------- */
#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-reserved-identifier"

#include "xmc.h"
// std
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

typedef float (*FN_SQRT) (float);
typedef void* (*FN_TEST_PFM) ();

std::vector<float[3]> random_numbers(unsigned int count = 10000000)
{
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(0.0f, 100.0f);

        std::vector<float[3]> numbers(count);
        for (size_t i = 0; i < count; i++) {
                numbers[i][0] = dist(gen);
                numbers[i][1] = dist(gen);
                numbers[i][2] = dist(gen);
        }

        return numbers; 
}

static std::vector<float[3]> s_numbers = random_numbers();

void* xmc_calc_trs_matrix()
{
        xmc::vec3 _;
        for (const auto &fvec : s_numbers) {
                xmc::vec3 P(fvec[0], fvec[1], fvec[2]);
                xmc::mat4 T = xmc::translate(xmc::mat4(1.0f), xmc::vec3(5.0f, 5.0f, 0.0f));
                xmc::mat4 R = xmc::rotate(xmc::mat4(1.0f), xmc::radians(90), xmc::vec3(1.0f, 1.0f, 1.0f));
                xmc::mat4 S = xmc::scale(xmc::mat4(1.0f), xmc::vec3(5.0f));
                _ = (P = (T * R * S * xmc::vec4(P, 1.0f)).xyz());
        }
        return xmc::value_ptr(_);
}

void* glm_calc_trs_matrix()
{
        glm::vec3 _;
        for (const auto &fvec : s_numbers) {
                glm::vec3 P(fvec[0], fvec[1], fvec[2]);
                glm::mat4 T = glm::translate(glm::mat4(1.0f), glm::vec3(5.0f, 5.0f, 0.0f));
                glm::mat4 R = glm::rotate(glm::mat4(1.0f), glm::radians((float) 90), glm::vec3(1.0f, 1.0f, 1.0f));
                glm::mat4 S = glm::scale(glm::mat4(1.0f), glm::vec3(5.0f));
                _ = (P = glm::vec3((T * R * S * glm::vec4(P, 1.0f))));
        }
        return glm::value_ptr(_);
}

void performance(const char *title, FN_TEST_PFM fn_performance_ptr)
{
        auto start = std::chrono::high_resolution_clock::now();
        fn_performance_ptr();
        auto end = std::chrono::high_resolution_clock::now();
        
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << title << ", " << duration.count() << "ms, " << duration.count() / 1000 << "sec" << std::endl;
}

int main()
{
        performance("glm_calc_trs_matrix", glm_calc_trs_matrix);
        performance("xmc_calc_trs_matrix", xmc_calc_trs_matrix);
}

#pragma clang diagnostic pop
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

#include "xne.h"
// std
#include <iostream>
#include <chrono>
#include <vector>
#include <random>

typedef float (*FN_SQRT) (float);

std::vector<float> random_numbers(unsigned int count = 10000)
{
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(0.0f, 1000000.0f);

        std::vector<float> numbers(count);
        for (size_t i = 0; i < count; i++)
                numbers[i] = dist(gen);

        return numbers; 
}

void testing(const std::vector<float> &numbers, const char *title, FN_SQRT _sqrt)
{
        auto start = std::chrono::high_resolution_clock::now();
        
        float a = 0.0f;
        for (const auto &number : numbers)
                a += _sqrt(number);

        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        
        std::cout << title << ", time: " << duration.count() << "ns" << std::endl;
}

int main()
{
        xmc::vec3 P(5.0f, 10.0f, 32.0f);
        xmc::mat4 T = xmc::translate(xmc::mat4(1.0f), xmc::vec3(5.0f, 5.0f, 0.0f));
        xmc::mat4 R = xmc::rotate(xmc::mat4(1.0f), xmc::radians(90), xmc::vec3(1.0f, 1.0f, 1.0f));
        xmc::mat4 S = xmc::scale(xmc::mat4(1.0f), xmc::vec3(5.0f));
        P = (T * R * S * xmc::vec4(P, 1.0f)).xyz();
        xmc_write_vector3(P);
        
        // std::vector<float> numbers = random_numbers();
        // testing(numbers, "xmc::sqrt", xmc::sqrt);
        // testing(numbers, "std::sqrt", std::sqrt);
}

#pragma clang diagnostic pop
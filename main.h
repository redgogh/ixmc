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
#ifndef VRT_MAIN_H_
#define VRT_MAIN_H_

#include "vrt.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// std
#include <iostream>
#include <random>
#include <tuple>
#include <array>
#include <chrono>

float rdf32()
{
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<float> dis(0.0f, 100.0f);

        return dis(gen);
}

std::array<float, 2> random_float2()
{
        return { rdf32(), rdf32() };
}

std::array<float, 3> random_float3()
{
        return { rdf32(), rdf32(), rdf32() };
}

std::array<float, 4> random_float4()
{
        return { rdf32(), rdf32(), rdf32(), rdf32() };
}

#endif /* VRT_MAIN_H_ */

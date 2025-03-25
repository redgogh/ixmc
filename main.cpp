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

#include "vrt.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// std
#include <iostream>

void vrt_test_vec2()
{
        {
                vrt::vec2 p(5.23f, 1.32f);
                vrt::mat2 m(1.0f);

                m[0][0] = 23.02f;
                m[0][1] = 43.02f;

                m[1][0] = 93.02f;
                m[1][1] = 124.02f;

                p = m * p;

                VRT_PRINT_FORMAT_VECTOR2(p);
        }

        std::cout << std::endl;

        {
                glm::vec2 p(5.23f, 1.32f);
                glm::mat2 m(1.0f);

                m[0][0] = 23.02f;
                m[0][1] = 43.02f;

                m[1][0] = 93.02f;
                m[1][1] = 124.02f;

                p = m * p;

                VRT_PRINT_FORMAT_VECTOR2(p);
        }
}

void vrt_test_vec3()
{
        {
                vrt::mat4 m(1.0f);
                vrt::vec3 p(1.0f);

                m = vrt::translate(m, vrt::vec3(3.0f, 6.0f, 9.0f));
                m = vrt::scale(m, vrt::vec3(2.0));

                p = (m * vrt::vec4(p, 1.0f));

                VRT_PRINT_FORMAT_VECTOR3(p);
        }

        std::cout << std::endl;
        
        {
                glm::mat4 m(1.0f);
                glm::vec3 p(1.0f);

                m = glm::translate(m, glm::vec3(3.0f, 6.0f, 9.0f));
                m = glm::scale(m, glm::vec3(2.0f));

                p = (m * glm::vec4(p, 1.0f));

                VRT_PRINT_FORMAT_VECTOR3(p);
        }
}

int main()
{
        vrt::vec2 V(0.0f, 1.0f);

        V -= -1;
        
        VRT_PRINT_FORMAT_VECTOR2(V);
}

#pragma clang diagnostic pop
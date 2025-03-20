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

#include "alg.h"
#include <glm/glm.hpp>

void MAT_MUL_VEC()
{
        {
                using namespace alg;

                mat4 M, R;

                R = {
                        1, 2, 3, 8,
                        4, 5, 6, 8,
                        7, 8, 9, 7,
                        3, 2, 1, 7
                };

                M = R * 5.0f;

                ALG_PRINT_FORMAT_MATRIX4(M);
        }

        printf("\n");

        {
                using namespace glm;

                mat4 M, R;

                R = {
                        1, 2, 3, 8,
                        4, 5, 6, 8,
                        7, 8, 9, 7,
                        3, 2, 1, 7
                };

                M = R * 5.0f;

                ALG_PRINT_FORMAT_MATRIX4(M);
        }
}

int main()
{
        alg::vec4 vec(9.0f, 25.0f, 64.0f, 256.0f);
        alg::vec4 result = alg::sqrt(vec);
        ALG_PRINT_FORMAT_VECTOR4(result);
}

#pragma clang diagnostic pop
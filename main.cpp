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
#include "numcp.h"
// std
#include <iostream>

using namespace umc;

int main()
{
        int   angdeg = 90;
        float angrad = radians(angdeg);

        printf("r = %f, sin(r) = %f, cos(r) = %f\n", angrad, sin(angrad), cos(angrad));

        umc::vec2 a_vec2(1.0f, 2.0f);
        umc::vec2 b_vec2(2.0f, 3.0f);

        vec2 r_vec2 = a_vec2 * b_vec2;
        printf("c = a * b = (%f, %f)\n", r_vec2.x, r_vec2.y);

        umc::vec3 a_vec3(1.0f, 2.0f, 1.0f);
        umc::vec3 b_vec3(2.0f, 3.0f, 1.0f);

        vec3 r_vec3 = cross(a_vec3, b_vec3);
        printf("c = a x b = (%f, %f, %f)\n", r_vec3.x, r_vec3.y, r_vec3.z);

        printf("matrix 3x3:\n");
        
        umc::mat3 a_mat3(3.5);
        umc::mat3 b_mat3(5.0f);

        umc::mat3 c_mat3 = a_mat3 * b_mat3;

        printf_matrix_3x3(c_mat3);
        
        printf("matrix 4x4:\n");

        umc::mat4 a_mat4(3.5);
        umc::mat4 b_mat4(5.0f);

        umc::mat4 c_mat4 = a_mat4 * b_mat4;

        printf_matrix_4x4(c_mat4);
        
        return 0;
}

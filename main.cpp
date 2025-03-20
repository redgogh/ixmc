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

#include "vec.h"
#include <glm/glm.hpp>

int main()
{
        equ::vec4 vec(1.0f, 2.0f, 0.0f, 0.0f);
        
        vec[0] = 3.0f;
        vec[1] = 4.0f;
        vec[2] = 5.0f;
        vec[3] = 6.0f;
        
        printf("%f, %f\n", vec[0], vec[1]);
        printf("%f, %f\n", vec[2], vec[3]);
        
        equ::vec2 V2 = vec.xy() * vec.xy();
        
        printf("%f, %f\n", V2[0], V2[1]);
        
        return 0;
}

#pragma clang diagnostic pop
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

#include "art.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// std
#include <iostream>

int main()
{
        {
                art::mat4 m(1.0f);
                art::vec3 p(1.0f);

                m = art::translate(m, art::vec3(3.0f, 6.0f, 9.0f));
                
                p = (m * art::vec4(p, 1.0f));

                ART_PRINT_FORMAT_VECTOR3(p);
        }

        {
                glm::mat4 m(1.0f);
                glm::vec3 p(1.0f);

                m = glm::translate(m, glm::vec3(3.0f, 6.0f, 9.0f));

                p = (m * glm::vec4(p, 1.0f));

                ART_PRINT_FORMAT_VECTOR3(p);
        }   
}

#pragma clang diagnostic pop
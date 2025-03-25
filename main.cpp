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

#include "main.h"

typedef void (*FN_PERFORMANCE)();

void performance(const char *name, FN_PERFORMANCE fn_performance_ptr)
{
        auto start = std::chrono::high_resolution_clock::now();
        fn_performance_ptr();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Run task (" << name << "): " << duration.count() << "ms" << std::endl;
}

void *call(void *ptr)
{
        return ptr;
}

int main()
{
        static std::vector<std::array<float, 3>> numbers;
        
        for (int i =0; i < 10000; i++)
                numbers.push_back(random_float3());
        
        performance("vrt", []{
                using namespace vrt;

                mat4 m(1.0f);
                // vec3 v(0.0f, 1.0f, 5.0f);

                for (const auto &f3 : numbers) {
                        vec3 v(f3[0], f3[1], f3[2]);
        
                        // m = translate(m, vec3(2.0f, 0.0f, 0.0f));
                        // m = rotate(m, 90.0f, vec3(0.0f, 1.0f, 1.0f));
        
                        v = m * vec4(v, 1.0f);

                        call(&v);
                }
        });

        performance("glm", []{
                using namespace glm;

                mat4 m(1.0f);
                // vec3 v(0.0f, 1.0f, 5.0f);

                for (const auto &f3 : numbers) {
                        vec3 v(f3[0], f3[1], f3[2]);

                        // m = translate(m, vec3(2.0f, 0.0f, 0.0f));
                        // m = rotate(m, 90.0f, vec3(0.0f, 1.0f, 1.0f));

                        v = m * vec4(v, 1.0f);

                        call(&v);
                }
        });
}

#pragma clang diagnostic pop
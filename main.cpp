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

#include "sci.h"
// std
#include <iostream>

/**
 * this method for test and validation Matrix2x2 multiply result
 * is correct.
 */
void __mat2_mul()
{
        printf("MATRIX(2x2) C = A x B\n");
        sci::mat2 A, B, C;

        A = sci::mat2 (
            1, 2,
            4, 5
        );

        B = sci::mat2(
            9, 8,
            6, 5
        );
        
        C = A * B;

        printf("A = \n");
        sci_println_matrix2(A);
        printf("B = \n");
        sci_println_matrix2(B );
        printf("A x B = \n");
        sci_println_matrix2(C);

        printf("\n");
}

/**
 * this method for test and validation Matrix3x3 multiply result
 * is correct.
 */
void __mat3_mul()
{
        printf("MATRIX(3x3) C = A x B\n");;
        sci::mat3 A, B, C;
        
        A = sci::mat3(
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
        );
        
        B = sci::mat3(
            9, 8, 7,
            6, 5, 4,
            3, 2, 1
        );
        
        C = A * B;

        printf("A = \n");
        sci_println_matrix3(A);
        printf("B = \n");
        sci_println_matrix3(B );
        printf("A x B = \n");
        sci_println_matrix3(C);

        printf("\n");
}

/**
 * this method for test and validation Matrix3x3 multiply result
 * is correct.
 */
void __mat4_mul()
{
        printf("MATRIX(4x4) C = A x B\n");
        sci::mat4 A, B, C;

        A = sci::mat4(
            1, 2, 3, 5,
            4, 5, 6, 6,
            7, 8, 9, 7,
            7, 8, 9, 7
        );
        
        B = sci::mat4(
            9, 8, 7, 2,
            6, 5, 4, 4,
            3, 2, 1, 6,
            6, 5, 4, 4
        );
        
        C = A * B;

        printf("A = \n");
        sci_println_matrix3(A);
        printf("B = \n");
        sci_println_matrix3(B);
        printf("A x B = \n");
        sci_println_matrix4(C);

        printf("\n");
}

void __vec2_mul()
{
        printf("VECTOR(2) C = A x B\n");
        sci::vec2 A, B, C;
        
        A = sci::vec2(1.0f, 2.0f);
        B = sci::vec2(3.0f, 4.0f);
        C = A * B;

        printf("    A = ");
        sci_println_vector2(A);
        printf("    B = ");
        sci_println_vector2(B);
        printf("A x B = ");
        sci_println_vector2(C);
        
        printf("\n");
}

void __vec3_cross()
{
        printf("VECTOR(3) C = A x(cross) B\n");
        sci::vec3 A, B, C;
        A = sci::vec3(1.0f, 2.0f, 3.0f);
        B = sci::vec3(3.0f, 2.0f, 1.0f);
        C = sci::cross(A, B);
        
        printf("    A = ");
        sci_println_vector3(A);
        printf("    B = ");
        sci_println_vector3(B);
        printf("A x B = ");
        sci_println_vector3(C);

        printf("\n");
}

int main()
{
        __mat2_mul();
        __mat3_mul();
        __mat4_mul();
        
        __vec2_mul();

        __vec3_cross();

        return 0;
}

#pragma clang diagnostic pop
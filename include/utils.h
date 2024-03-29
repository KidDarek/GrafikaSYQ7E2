#ifndef UTILS_H
#define UTILS_H

/**
 * GLSL-like three dimensional vector
 */
typedef struct vec3
{
    float x;
    float y;
    float z;
} vec3;

/**
 * Color with RGB components
 */
typedef struct Color
{
    float red;
    float green;
    float blue;
} Color;

/**
 * Material
 */
typedef struct Material
{
    struct Color ambient;
    struct Color diffuse;
    struct Color specular;
    float shininess;
} Material;

/**
 * Calculates radian from degree.
 */
double degree_to_radian(double degree);

void init_vec3(vec3 *vector, float x, float y, float z);

/*
    Places x,y,z coordinates into corresponding mins if they are smaller
*/
void min_v(float *x_min, float *y_min, float *z_min, float x, float y, float z);

/*
    Places x,y,z coordinates into corresponding maxes if they are smaller
*/
void max_v(float *x_min, float *y_min, float *z_min, float x, float y, float z);

/*
    Fill a vector3 with x,y,z values
*/
void fill_v(vec3 *vector, float x, float y, float z);

/*
    Fill a vector3 with an other vector3
*/
void fill_v_v(vec3 *vector, vec3 fill_with_v);

/*
    Add every coordinate to a vector
*/
void add_to_v(vec3 *vector, float x, float y, float z);

/*
    Multiplies every coordinate of the vector by a number
*/
void multiply_v(vec3 *vector, float value);
/*
    Add every coordinate of a vector to a vector
*/
void add_v_to_v(vec3 *vector1, vec3 vector2);

/*
    Calculate the distance between two points
*/
float p2_dist(float x1, float y1, float x2, float y2);

#endif /* UTILS_H */

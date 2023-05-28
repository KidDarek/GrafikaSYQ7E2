#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "utils.h"
#include <obj/model.h>

typedef struct BoundingBox
{
    vec3 base_min_max[2];
    vec3 min_max[2];
} BoundingBox;

/*
    Initializes a bounding box according to the model's vertices
*/
void init_bounding_box(BoundingBox *box, Model *model);

/*
    Updates a bounding box according to the vector's position
*/
void update_bounding_box(BoundingBox *box, vec3 vector);
/*
    Determines if the given point is in the bounding box
*/
int point_is_in_box(vec3 point, BoundingBox *box);

#endif
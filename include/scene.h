#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "bounding_box.h"

#include <obj/model.h>

typedef struct ModelData
{
    Model model;
    GLuint texture_id;
    vec3 positon;
    vec3 rotation;
    BoundingBox box;
    int Index;
} ModelData;

typedef struct Scene
{
    ModelData *models;
    Material material;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene *scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(float value);

/**
 * Set the current material.
 */
void set_material(const Material *material);

/**
 * Update the scene.
 */
void update_scene(Scene *scene, int index, float x, float y);

/**
 * Render the scene objects.
 */
void render_scene(const Scene *scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/*
re-render an object
*/
void re_render_obj(Scene *scene, int index, float x, float y);

#endif /* SCENE_H */

#include "scene.h"
#include <stdlib.h>

#include <obj/load.h>
#include <obj/draw.h>
int angle = 0;
double move = 0;
GLfloat matrix[16];

void init_scene(Scene *scene)
{
    int row = 1;
    scene->models = malloc(sizeof(ModelData) * 33);
    for (int i = 0; i < 16; i++)
    {
        if (i == 8)
        {
            row += 1.2;
        }
        load_model(&(scene->models[i].model), "assets/models/paraszt.obj");
        scene->models[i].texture_id = load_texture("assets/textures/Brick.jpg");
        glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
        init_vec3(&(scene->models[i].positon), row, (i % 8) + 0.4, 0);
        init_vec3(&(scene->models[i].rotation), 0, 0, 0);
    }
    for (int i = 16; i < 32; i++)
    {
        if (i == 24)
        {
            row += 1;
        }
        load_model(&(scene->models[i].model), "assets/models/paraszt.obj");
        scene->models[i].texture_id = load_texture("assets/textures/Brick.jpg");
        glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
        init_vec3(&(scene->models[i].positon), row + 4.7, (i % 8) + 0.4, 0);
        init_vec3(&(scene->models[i].rotation), 0, 0, 180);
    }
    load_model(&(scene->models[32].model), "assets/models/table.obj");
    scene->models[32].texture_id = load_texture("assets/textures/BoardColor.jpg");
    glBindTexture(GL_TEXTURE_2D, scene->models[32].texture_id);
    init_vec3(&(scene->models[32].positon), 4.5, 4.5, -0.6);
    init_vec3(&(scene->models[32].rotation), 0, 0, 0);

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 0.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;
}

void set_lighting(float value)
{
    static float lightcontroll = 1.0;
    lightcontroll += value;
    float ambient_light[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float diffuse_light[] = {1.0f + lightcontroll, 1.0f + lightcontroll, 1.0f + lightcontroll, 1.0f + lightcontroll};
    float specular_light[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float position[] = {5.5f, 7.0f, 10.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material *material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue};

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue};

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene *scene)
{
    angle++;
    move += 0.01;
}

void render_scene(const Scene *scene)
{
    glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
    set_material(&(scene->material));
    set_lighting(0);
    draw_origin();
    for (int i = 0; i < 32; i++)
    {
        glLoadMatrixf(matrix);
        glTranslatef(scene->models[i].positon.x, scene->models[i].positon.y, scene->models[i].positon.z);
        glRotatef(scene->models[i].rotation.x, 1.0, 0.0, 0.0);
        glRotatef(scene->models[i].rotation.y, 0.0, 1.0, 0.0);
        glRotatef(scene->models[i].rotation.z, 0.0, 0.0, 1.0);
        draw_model(&(scene->models[i].model));
    }
    glLoadMatrixf(matrix);
    glTranslatef(scene->models[32].positon.x, scene->models[32].positon.y, scene->models[32].positon.z);
    glRotatef(scene->models[32].rotation.x, 1.0, 0.0, 0.0);
    glRotatef(scene->models[32].rotation.y, 0.0, 1.0, 0.0);
    glRotatef(scene->models[32].rotation.z, 0.0, 0.0, 1.0);
    draw_model(&(scene->models[32].model));
    glLoadMatrixf(matrix);
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

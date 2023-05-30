#include "scene.h"
#include "bounding_box.h"
#include <stdlib.h>

#include <obj/load.h>
#include <obj/draw.h>

GLfloat matrix[16];

void init_scene(Scene *scene)
{
    float row = 1.3;
    scene->models = malloc(sizeof(ModelData) * 33);
    for (int i = 0; i < 16; i++)
    {
        if (i == 8)
        {
            row += 1;
        }

        if (i == 0 || i == 7)
        {
            load_model(&(scene->models[i].model), "assets/models/bastya.obj");
            scene->models[i].texture_id = load_texture("assets/textures/feher.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 270);
            scene->models[i].Index = i;
        }
        if (i == 1 || i == 6)
        {
            load_model(&(scene->models[i].model), "assets/models/futo.obj");
            scene->models[i].texture_id = load_texture("assets/textures/feher.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 270);
            scene->models[i].Index = i;
        }
        if (i == 2 || i == 5)
        {
            load_model(&(scene->models[i].model), "assets/models/horse.obj");
            scene->models[i].texture_id = load_texture("assets/textures/feher.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 270);
            scene->models[i].Index = i;
        }
        if (i == 3)
        {
            load_model(&(scene->models[i].model), "assets/models/king.obj");
            scene->models[i].texture_id = load_texture("assets/textures/feher.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 270);
            scene->models[i].Index = i;
        }
        if (i == 4)
        {
            load_model(&(scene->models[i].model), "assets/models/kiralyno.obj");
            scene->models[i].texture_id = load_texture("assets/textures/feher.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 270);
            scene->models[i].Index = i;
        }
        if (i >= 8)
        {
            load_model(&(scene->models[i].model), "assets/models/paraszt.obj");
            scene->models[i].texture_id = load_texture("assets/textures/feher.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 270);
            scene->models[i].Index = i;
        }
    }
    for (int i = 16; i < 32; i++)
    {
        if (i == 24)
        {
            row += 1;
        }
        if (i == 24 || i == 31)
        {
            load_model(&(scene->models[i].model), "assets/models/bastya.obj");
            scene->models[i].texture_id = load_texture("assets/textures/fekete.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row + 4.4, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 90);
            scene->models[i].Index = i;
        }
        if (i == 25 || i == 30)
        {
            load_model(&(scene->models[i].model), "assets/models/futo.obj");
            scene->models[i].texture_id = load_texture("assets/textures/fekete.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row + 4.4, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 90);
            scene->models[i].Index = i;
        }
        if (i == 26 || i == 29)
        {
            load_model(&(scene->models[i].model), "assets/models/horse.obj");
            scene->models[i].texture_id = load_texture("assets/textures/fekete.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row + 4.4, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 90);
            scene->models[i].Index = i;
        }
        if (i == 28)
        {
            load_model(&(scene->models[i].model), "assets/models/king.obj");
            scene->models[i].texture_id = load_texture("assets/textures/fekete.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row + 4.4, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 90);
            scene->models[i].Index = i;
        }
        if (i == 27)
        {
            load_model(&(scene->models[i].model), "assets/models/kiralyno.obj");
            scene->models[i].texture_id = load_texture("assets/textures/fekete.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row + 4.4, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 90);
            scene->models[i].Index = i;
        }
        if (i <= 23)
        {
            load_model(&(scene->models[i].model), "assets/models/paraszt.obj");
            scene->models[i].texture_id = load_texture("assets/textures/fekete.jpg");
            glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
            init_vec3(&(scene->models[i].positon), row + 4.4, (double)(i % 8) / 1.1 + 1.3, 0.82);
            init_vec3(&(scene->models[i].rotation), 0, 0, 90);
            scene->models[i].Index = i;
        }
    }
    load_model(&(scene->models[32].model), "assets/models/table.obj");
    scene->models[32].texture_id = load_texture("assets/textures/BoardColor.jpg");
    glBindTexture(GL_TEXTURE_2D, scene->models[32].texture_id);
    init_vec3(&(scene->models[32].positon), 4.5, 4.5, -0.6);
    init_vec3(&(scene->models[32].rotation), 0, 0, 0);
    scene->models[32].Index = 32;

    for (int i = 0; i < 32; i++)
    {
        init_bounding_box(&scene->models[i].box, &(scene->models[i].model));
        update_bounding_box(&scene->models[i].box, scene->models[i].positon);
    }

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

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

// Update

void update_scene(Scene *scene, int index, float x, float y)
{
    if (index == -1)
    {
        return;
    }
    else
    {
        // glTranslatef(scene->models[index].positon.x, scene->models[index].positon.y, scene->models[index].positon.z);
        // scene->models[index].rotation.x += 0.1;

        scene->models[index].rotation.x += 0.1;
        // scene->models[index].rotation.y += 0.1;
        scene->models[index].positon.x += x / 100;
        scene->models[index].positon.y += y / 100;
        // glLoadMatrixf(matrix);
    }
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
        glBindTexture(GL_TEXTURE_2D, scene->models[i].texture_id);
        draw_model(&(scene->models[i].model));
    }
    glLoadMatrixf(matrix);
    glTranslatef(scene->models[32].positon.x, scene->models[32].positon.y, scene->models[32].positon.z);
    glRotatef(scene->models[32].rotation.x, 1.0, 0.0, 0.0);
    glRotatef(scene->models[32].rotation.y, 0.0, 1.0, 0.0);
    glRotatef(scene->models[32].rotation.z, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->models[32].texture_id);
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

void re_render_obj(Scene *scene, int index, float x, float y)
{
    scene->models[index].positon.x += x;
    scene->models[index].positon.y += y;
    draw_model(&(scene->models[index].model));
}

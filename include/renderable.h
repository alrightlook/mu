#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "camera.h"
#include "transformation.h"

enum vertex_buffers {
  VERTEX_BUFFER_POSITION = 0,
  VERTEX_BUFFER_NORMAL = 1,
  VERTEX_BUFFER_TEXTURE_COORD = 2,
  VERTEX_BUFFER_INDEX = 3,
  NUM_VERTEX_BUFFERS = 4,
};

struct renderable {
  size_t num_vertices;
  GLuint vertex_array_object;
  GLuint vertex_buffers[NUM_VERTEX_BUFFERS];
};

int renderable_load_mesh(struct renderable *renderable, struct mesh *mesh);
void renderable_delete(struct renderable *renderable);
int renderable_render(struct renderable *renderable, struct shader *shader, struct texture *texture, struct camera *camera, struct transformation *transformation, struct buffer *lights);

#endif

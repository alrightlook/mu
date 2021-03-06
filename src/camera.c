#include <math.h>
#include "camera.h"

struct camera camera_new(float fov, float clip_near, float clip_far, float x, float y, float z, float rx, float ry, float rz) {
  struct camera camera = {
    .transformation = transformation_new(-x, -y, -z, rx, ry, rz, 1.0),
    .fov = fov,
    .clip_near = clip_near,
    .clip_far = clip_far
  };
  return camera;
}

void camera_move(struct camera *camera, float dx, float dy, float dz) {
  transformation_move(&camera->transformation, -dx, -dy, -dz);
}

void camera_rotate(struct camera *camera, float drx, float dry, float drz) {
  transformation_rotate(&camera->transformation, drx, dry, drz);
}

void camera_look_at(struct camera *camera, struct vec3f position) {
  struct vec3f direction = vec3f_normalize(vec3f_add(vec3f_scale(camera->transformation.position, -1.0), position));
  float rot_x = atan2(direction.y, direction.z);
  float rot_y = atan2(-direction.x, sqrtf(direction.y * direction.y + direction.z * direction.z));
  camera->transformation.rotation.x = rot_x;
  camera->transformation.rotation.y = rot_y;
  camera->transformation.rotation.z = 0.0;
}

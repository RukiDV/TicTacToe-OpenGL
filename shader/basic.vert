#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 color;

out vec4 color_vert;

uniform mat4 u_modelViewProj;

void main() {

    gl_Position = /*u_modelViewProj * */vec4(pos, 1.0f);
    color_vert = color;
}
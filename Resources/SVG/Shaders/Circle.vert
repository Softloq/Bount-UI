#version 330 core

layout (location = 0) in vec3 l_Position;
layout (location = 1) in vec3 l_Normal;
layout (location = 2) in vec2 l_UV;

uniform mat4 u_Transform = mat4(1.0);

out vec2 out_Position;
out vec3 out_Normal;

void main()
{
    gl_Position = u_Transform * vec4(l_Position.x, -l_Position.y, l_Position.z, 1.0f);
    out_Position = l_Position.xy;
    out_Normal = l_Normal;
}
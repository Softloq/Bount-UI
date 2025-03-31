#version 330 core

layout (location = 0) in vec3 lPosition;
layout (location = 1) in vec3 lNormal;
layout (location = 2) in vec2 lUV;

uniform mat4 uTransform = mat4(1.0);

out vec2 outPosition;
out vec3 outNormal;

void main()
{
    gl_Position = uTransform * vec4(lPosition.x, -lPosition.y, lPosition.z, 1.0f);
    outPosition = lPosition.xy;
    outNormal = lNormal;
}
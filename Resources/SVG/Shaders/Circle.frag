#version 330 core

out vec4 fragNormal;
in vec3 outNormal;

void main()
{
    fragNormal = vec4(outNormal, 1.0f);
}
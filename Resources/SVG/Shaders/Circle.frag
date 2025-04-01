#version 330 core

out vec4 frag_Normal;
in vec2 out_Position;
in vec3 out_Normal;

uniform vec2 u_Resolution = vec2(800.0f, 600.0f);

uniform vec2 u_CirclePos = vec2(0.0f, 0.0f);
uniform float u_CircleRadius = 0.0f;

uniform vec4 u_Fill = vec4(0.0f, 0.0f, 0.0f, 1.0f);

vec2 svg_Position = (out_Position + vec2(1.0f, 1.0f))*0.5f;

float smooth_sdf(float dist)
{
    float aa = fwidth(dist);
    return smoothstep(-aa, 0.25f, -dist);
}

float circle_sdf(vec2 p, vec2 center, float radius)
{
    return length(p - center) - radius;
}

void main()
{
    vec2 p = svg_Position*u_Resolution;
    float dist = circle_sdf(p, u_CirclePos, u_CircleRadius);
    float alpha = smooth_sdf(dist);
    frag_Normal = vec4(u_Fill.xyz, alpha);
}
#version 330 core

out vec4 fNormal;
in vec2 outPosition;
in vec3 outNormal;

uniform vec4 uFill = vec4(0.0f, 0.0f, 0.0f, 1.0f);
uniform vec3 uCircleCX_CY_R = vec3(100.0f, 100.0f, 100.0f);
vec2 size_factor = vec2(800.0f, 600.0f);

float smooth_sdf(float dist)
{
    float aa = fwidth(dist);
    return smoothstep(-aa, aa, -dist);
}

float circle_sdf(vec2 p, vec2 center, float radius)
{
    return length(p - center) - radius;
}
void main()
{
    vec2 p = ((outPosition + vec2(1.0f, 1.0f))/2.0f)*size_factor;
    vec2 center = uCircleCX_CY_R.xy;
    float radius = uCircleCX_CY_R.z;
    float dist = circle_sdf(p, center, radius);
    float smooth_value = smooth_sdf(dist);
    fNormal = vec4(uFill.xyz, smooth_value);
}
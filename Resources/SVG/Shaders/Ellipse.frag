#version 330 core

out vec4 frag_Normal;
in vec2 out_Position;
in vec3 out_Normal;

uniform vec2 u_Resolution = vec2(800.0f, 600.0f);

uniform vec2 u_EllipsePos = vec2(0.0f, 0.0f);
uniform vec2 u_EllipseRadius = vec2(0.0f, 0.0f);

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

float ellipse_sdf(vec2 p, vec2 center, vec2 ab)
{
    if(ab.x == ab.y) return circle_sdf(p, center, ab.x);
    p = p - center;
    p = abs(p); if(p.x > p.y) {p = p.yx; ab = ab.yx;}
    float l = ab.y * ab.y - ab.x * ab.x;
    float m = ab.x*p.x/l;      float m2 = m*m; 
    float n = ab.y*p.y/l;      float n2 = n*n; 
    float c = (m2 + n2 - 1.0f)/3.0f; float c3 = c*c*c;
    float q = c3 + m2*n2*2.0f;
    float d = c3 + m2*n2;
    float g = m + m*n2;
    float co;
    if(d < 0.0f)
    {
        float h = acos(q/c3)/3.0f;
        float s = cos(h);
        float t = sin(h)*sqrt(3.0f);
        float rx = sqrt(-c*(s + t + 2.0f) + m2);
        float ry = sqrt(-c*(s - t + 2.0f) + m2);
        co = (ry+sign(l)*rx+abs(g)/(rx*ry)- m)/2.0f;
    }
    else
    {
        float h = 2.0f*m*n*sqrt(d);
        float s = sign(q+h)*pow(abs(q+h), 1.0f/3.0f);
        float u = sign(q-h)*pow(abs(q-h), 1.0f/3.0f);
        float rx = -s - u - c*4.0f + 2.0f*m2;
        float ry = (s - u)*sqrt(3.0f);
        float rm = sqrt( rx*rx + ry*ry );
        co = (ry/sqrt(rm-rx)+2.0f*g/rm-m)/2.0f;
    }
    vec2 r = ab * vec2(co, sqrt(1.0f-co*co));
    return length(r-p) * sign(p.y-r.y);
}

void main()
{
    vec2 p = svg_Position*u_Resolution;
    float dist = ellipse_sdf(p, u_EllipsePos, u_EllipseRadius);
    float alpha = smooth_sdf(dist);
    frag_Normal = vec4(u_Fill.xyz, alpha);
}
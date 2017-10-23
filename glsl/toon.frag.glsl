#version 150

//uniform vec3 lightDir;
varying vec3 normal;
vec4 orig_color;


void main(void)
{
   vec4 color;
   float intensity;
   vec3 n = normalize(normal);
   intensity = dot(vec3(gl_LightSource[0].position), n);

   if(intensity > .95) {
       color = orig_color;
   } else if (intensity > .5) {
       color = orig_color * .5;
   } else if (intensity > .25) {
       color = orig_color * .25;
   } else {
       color = orig_color * .1;
   }
   gl_FragColor = color;
}

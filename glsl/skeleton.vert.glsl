#version 150
//vertices

uniform mat4 u_Model;
uniform mat4 u_ViewProj;

in vec4 vs_Pos;
in vec4 vs_Col;

out vec4 fs_Col;


//joint weights
in vec2 weights;

//joints of influence
in ivec2 jointIDs;


//joint bind matrices
uniform mat4 bindmats[100];

//current overall joint transformations
uniform mat4 jmats[100];


void main(void)
{

    //get first joint of influence's id
    vec4 pos1 = jmats[jointIDs[0]] * bindmats[jointIDs[0]] * vs_Pos;



    //get second joint of influence's id
    vec4 pos2 = jmats[jointIDs[1]] * bindmats[jointIDs[1]] * vs_Pos;

    //get weighted average
    vec4 lerped_vs_Pos = weights[0] * pos1  + weights[1]  * pos2;


    fs_Col = vs_Col;

    //calculate the new position of the pos
    vec4 modelposition = u_Model *  lerped_vs_Pos;


    // built-in things to pass down the pipeline
    gl_Position = u_ViewProj * modelposition;

}

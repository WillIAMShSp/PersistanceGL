
#version 330 core

layout(location = 0) in vec3 position; 
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normals;

out vec3 v_position;
out vec2 v_texCoord;
out vec3 v_normals;
out vec3 v_modelpos;
flat out int v_amountoflights;


uniform mat4 u_Model = mat4(1.0);
uniform mat4 u_View;
uniform mat4 u_Projection;
uniform int amountoflights = 0;








void main()
{

 gl_Position =  u_Projection *  u_View  * u_Model * vec4(position, 1.0);
 v_texCoord = texCoord;
 v_normals = normals;
 v_position = position;
 v_amountoflights = amountoflights;


 v_modelpos = vec3(u_Model * vec4(position,1.0));







 //

 //so hear me out, for vertex shader ligthing, we could calculate with glposition the difference between the positions of the ligths and the positions of the vertices to, therefore, calculate the correct diffuse value
 // wouldn't that be ideal? we could use the same methods that wer're currently using in the fragment shader, thus making the whole operation cheaper, and making the correct ligthing even easier using gl_Position

};



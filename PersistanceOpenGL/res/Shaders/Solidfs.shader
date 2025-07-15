#version 330 core


layout (location = 0) out vec4 FragColor; 
layout (location = 1) out vec4 brightcolor;

void main()
{
    FragColor = vec4(1.0); 
    

    float brightness = dot(FragColor.rgb, vec3(0.2126, 0.7152, 0.0722));

	if(brightness>0.1)
	{
		brightcolor = vec4(1.0);
	}
	else
	{
		brightcolor = vec4(0.0);
	}

}
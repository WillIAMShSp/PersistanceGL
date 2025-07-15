#version 330 core



layout(location = 0) out vec4 color; 


in vec3 v_position;
in vec2 v_texCoord;
in vec3 v_normals;
in vec3 v_modelpos;

flat in int v_amountoflights;

uniform vec4 u_Color;
uniform sampler2D u_Texture;



struct Light
{
	vec3 LightPosition;
	vec3 LightColor;
	float AmbientIntensity;

	
};

struct Material
{
	vec3 Color;
	vec3 DiffuseColor;
	float DiffuseIntensity;

	
};


uniform Material Mat;
uniform Light gLight;
uniform Light gLights[10];




float DirectionNormal(vec3 LightPos, vec3 VertPos, vec3 norms)
{
	vec3 newDir = LightPos-VertPos;

	newDir = normalize(newDir);

	vec3 normal = normalize(norms);

	float DotProductAngle = clamp(dot(normal,newDir),1.0,0.0);

	return abs(1-cos(DotProductAngle));


}




void main()
{
	vec4 textureColor = texture(u_Texture, v_texCoord);
	textureColor = vec4(1.0);
	vec3 normals = v_normals;

	

	vec3 position = v_modelpos;
	
	



	vec4 AmbientValue = vec4(Mat.Color, 1.0) * vec4(gLights[0].LightColor * gLights[0].AmbientIntensity, 1.0); 


	
	


	vec4 DiffuseValue = vec4(0.0);

	for(int i = 0; i < v_amountoflights; i++)
	{
		
		DiffuseValue += vec4(Mat.DiffuseColor,1.0) *
						vec4(gLights[i].LightColor * Mat.DiffuseIntensity, 1.0) * 
						vec4(DirectionNormal(gLights[i].LightPosition, position, normals));
		
	}



	color =				   textureColor 
						 * (AmbientValue + DiffuseValue);
						 
	
	
};
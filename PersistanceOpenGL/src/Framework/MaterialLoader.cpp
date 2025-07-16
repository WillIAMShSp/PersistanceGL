#include "MaterialLoader.h"


MaterialLoader::MaterialLoader()
{
}

MaterialLoader::MaterialLoader(const std::string& filepath)
{


    std::string line;
    std::ifstream stream;
    int count = 0;
        
    std::vector<glm::vec3> AmbientColor;
    std::vector<glm::vec3> DiffuseColor;
    std::vector<glm::vec3> SpecularColor;




    stream.open(filepath);



    while (getline(stream, line))
    {

        if (DivideStrings(line)[0] == "newmtl")
        {
            count++;
        }
   

    }
    m_mnames.reserve(count);
    m_umats.reserve(count);
    m_materials.reserve(count);

    stream.close();

  


    stream.open(filepath);



    while (getline(stream, line))
    {

        const auto& dividedstring = DivideStrings(line);


        if (dividedstring[0] == "newmtl")
        {
            m_mnames.emplace_back(dividedstring[1]);
            std::cout << "material name:"<<dividedstring[1]<<"\n";
        }

        if (dividedstring[0] == "Ka")
        {
            float x, y, z;
            sscanf_s(line.c_str(), "Ka %f %f %f", &x, &y, &z);
            AmbientColor.push_back(glm::vec3(x,y,z));
        }

        if (dividedstring[0] == "Kd")
        {
            float x, y, z;
            sscanf_s(line.c_str(), "Kd %f %f %f", &x, &y, &z);
            DiffuseColor.push_back(glm::vec3(x, y, z));
        }

        if (dividedstring[0] == "Ks")
        {
            float x, y, z;
            sscanf_s(line.c_str(), "Ks %f %f %f", &x, &y, &z);
            SpecularColor.push_back(glm::vec3(x, y, z));
        }






    }

    for (int i = 0; i < count; i++)
    {

        m_umats[m_mnames[i]] = Materials(AmbientColor[i].r, AmbientColor[i].g, AmbientColor[i].b, DiffuseColor[i].r, DiffuseColor[i].g, DiffuseColor[i].b, SpecularColor[i].r, SpecularColor[i].g, SpecularColor[i].b);

        m_materials.push_back(Materials( AmbientColor[i].r, AmbientColor[i].g, AmbientColor[i].b, DiffuseColor[i].r, DiffuseColor[i].g, DiffuseColor[i].b, SpecularColor[i].r, SpecularColor[i].g, SpecularColor[i].b ));

    }


    stream.close();

   
    



}

void MaterialLoader::SetUniforms(const unsigned int& shader, Materials& f_material)
{
  

    glUseProgram(shader);


    unsigned int AmbientIntensityLoc = glGetUniformLocation(shader, "gLight.AmbientIntensity");
    unsigned int MaterialColorLoc = glGetUniformLocation(shader, "Mat.Color");
    unsigned int DiffuseColorLoc = glGetUniformLocation(shader, "Mat.DiffuseColor");
    unsigned int DiffuseIntensityLoc = glGetUniformLocation(shader, "Mat.DiffuseIntensity");
    

    


    

    glUniform1f(AmbientIntensityLoc, 0.2f);
    glUniform3f(MaterialColorLoc, f_material.ka0, f_material.ka1, f_material.ka2);
    glUniform3f(DiffuseColorLoc, f_material.kd0, f_material.kd1, f_material.kd2);
    glUniform1f(DiffuseIntensityLoc, 1);

    glUseProgram(0);


}

void MaterialLoader::SetUniforms(const unsigned int& shader, int id)
{
    glUseProgram(shader);

    unsigned int AmbientIntensityLoc = glGetUniformLocation(shader, "gLight.AmbientIntensity");
    unsigned int MaterialColorLoc = glGetUniformLocation(shader, "Mat.Color");
    unsigned int DiffuseColorLoc = glGetUniformLocation(shader, "Mat.DiffuseColor");
    unsigned int DiffuseIntensityLoc = glGetUniformLocation(shader, "Mat.DiffuseIntensity");


    glUniform1f(AmbientIntensityLoc, 0.2f);
    glUniform3f(MaterialColorLoc, m_materials[id].ka0, m_materials[id].ka1, m_materials[id].ka2);
    glUniform3f(DiffuseColorLoc, m_materials[id].kd0, m_materials[id].kd1, m_materials[id].kd2);
    glUniform1f(DiffuseIntensityLoc, 1);


    glUseProgram(0);

}

void MaterialLoader::SetUniforms(Shader& shader, Materials& material)
{

    shader.SetUniform1f("gLight.AmbientIntensity", 0.2f);
    shader.SetUniform3f("Mat.Color", material.ka0, material.ka1, material.ka2);
    shader.SetUniform3f("Mat.DiffuseColor", material.kd0, material.kd1, material.kd2);
    shader.SetUniform1f("Mat.DiffuseIntensity", 1.0);






}

std::vector<std::string> MaterialLoader::DivideStrings(const std::string& string, const std::string& delimiter)
{
    size_t start = 0;
    size_t end = -1 * delimiter.size();
    std::vector<std::string> strings;


    do
    {
        start = end + delimiter.size();
        end = string.find(delimiter, start);
        strings.push_back(string.substr(start, end - start));

    } while (end != std::string::npos);


    return strings;
}

MaterialLoader::~MaterialLoader()
{
}

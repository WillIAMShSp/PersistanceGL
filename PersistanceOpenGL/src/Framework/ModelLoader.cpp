#include "ModelLoader.h"
#include "Renderer.h"

ModelLoader::ModelLoader()
{

}

ModelLoader::ModelLoader(const std::string& filepath, Shader& shader)
    :m_shadersource(shader)
{

    //int vc = 0;
    //int tc = 0;
    //int nc = 0;
    
    
    layout.push<float>(3);
    layout.push<float>(2);
    layout.push<float>(3);

    
    int posvcount = 0;
    int posncount = 0;
    int postcount = 0;
    int facecount = 0;
    std::string line;
    std::ifstream stream;
   



    stream.open(filepath);



    while (getline(stream, line))

    {

        if (DivideString(line)[0] == "usemtl")
        {
            materialcount++;
        }




        if (line[0] == 'v')
        {

            if (line[1] == ' ')
            {
                posvcount++;
            }

            if (line[1] == 't')
            {
                postcount++;

            }

            if (line[1] == 'n')
            {

                posncount++;

            }


        }




    }

    pos.reserve(posvcount);
    uv.reserve(postcount);
    norm.reserve(posncount);
    VertexBuffers.resize(1);

    stream.close();







    stream.open(filepath);

    

    


   

    


    while (getline(stream, line))
    {

        if (line[0] == 'v')
        {

            if (line[1] == ' ')
            {
                float x = 0, y = 0, z = 0;
                
                if (sscanf_s(line.c_str(), "v %f %f %f", &x, &y, &z)) 
                {
                    //std::cout << "v " << x << " " << y << " " << z << "pos["<<vc<<"]" << "\n";
                   // vc++;
                }
                
                    pos.push_back(glm::vec3(x, y, z));


              
            }
            else if (line[1] == 't')
            {
                float x, y;
                if (sscanf_s(line.c_str(), "vt %f %f", &x, &y))
                {
                   // std::cout << "vt " << x << " " << y <<"tex[" << tc << "]" << "\n";
                   // tc++;
                }

                uv.push_back(glm::vec2(x, y));


               
            }
            else if(line[1] == 'n')
            {
                float x = 0, y = 0, z = 0;

                if (sscanf_s(line.c_str(), "vn %f %f %f", &x, &y, &z))
                {

                    //std::cout << "vn " << x << " " << y << " " << z << "tex[" << nc << "]" <<"\n";
                    //nc++;
                }


                norm.push_back(glm::vec3(x, y, z));

                //std::cout << "vn " << x << " " << y << " " << z << "\n";
            }
            


        }
        else if (line[0] == 'f')
        {
            
            //std::cout << "\n " << line << " \n";
            
            const auto& nums = DivideString(line);

            size_t trianglecount = nums.size() - 3;

            for (int i = 0; i<trianglecount; i++)
            {
                

                ReadTriangles(nums[1]);
                ReadTriangles(nums[2 + i]);
                ReadTriangles(nums[3 + i]);


            }




        }




    }
    
    VertexBuffers[0] = vertices;




   

    


    stream.close();

}

ModelLoader::ModelLoader(const std::string& ModelPath, const std::string& MaterialPath, Shader& shader)
    :MatLoader(MaterialPath), m_shadersource(shader)
{
    ismaterialused = true;

    shader.Bind();

    layout.push<float>(3);
    layout.push<float>(2);
    layout.push<float>(3);
    









    int posvcount = 0;
    int posncount = 0;
    int postcount = 0;
    int facecount = 0;
    std::string line;
    std::ifstream stream;
    
    std::vector<Vertex>verts;
  


    stream.open(ModelPath);



    while (getline(stream, line))

    {

        if (DivideString(line)[0] == "usemtl")
        {
            materialcount++;
        }




        if (line[0] == 'v')
        {

            if (line[1] == ' ')
            {
                posvcount++;
            }

            if (line[1] == 't')
            {
                postcount++;

            }

            if (line[1] == 'n')
            {

                posncount++;

            }


        }




    }

    pos.reserve(posvcount);
    uv.reserve(postcount);
    norm.reserve(posncount);
    VertexBuffers.resize(materialcount);
    matnames.reserve(materialcount);

    stream.close();







    stream.open(ModelPath);








    int selectedmat = -1;




    while (getline(stream, line))
    {

        const auto& dividedline = DivideString(line);




        if (line[0] == 'v')
        {

            if (line[1] == ' ')
            {
                float x = 0, y = 0, z = 0;

                if (sscanf_s(line.c_str(), "v %f %f %f", &x, &y, &z))
                {
                    //std::cout << "v " << x << " " << y << " " << z << "pos["<<vc<<"]" << "\n";
                   // vc++;
                }

                pos.push_back(glm::vec3(x, y, z));



            }
            else if (line[1] == 't')
            {
                float x, y;
                if (sscanf_s(line.c_str(), "vt %f %f", &x, &y))
                {
                    // std::cout << "vt " << x << " " << y <<"tex[" << tc << "]" << "\n";
                    // tc++;
                }

                uv.push_back(glm::vec2(x, y));



            }
            else if (line[1] == 'n')
            {
                float x = 0, y = 0, z = 0;

                if (sscanf_s(line.c_str(), "vn %f %f %f", &x, &y, &z))
                {

                    //std::cout << "vn " << x << " " << y << " " << z << "tex[" << nc << "]" <<"\n";
                    //nc++;
                }


                norm.push_back(glm::vec3(x, y, z));

                //std::cout << "vn " << x << " " << y << " " << z << "\n";
            }



        }
        else if (line[0] == 'f')
        {

            //std::cout << "\n " << line << " \n";

            const auto& nums = DivideString(line);

            size_t trianglecount = nums.size() - 3;

            for (int i = 0; i < trianglecount; i++)
            {


                ReadTriangles(nums[1], verts);
                ReadTriangles(nums[2 + i], verts);
                ReadTriangles(nums[3 + i], verts);


            }




        }

        else if (dividedline[0] == "usemtl" && selectedmat<0)
        {

            selectedmat++;

            std::string combinedstring;

            for (int i = 1; i < dividedline.size(); i++)
            {
                if (dividedline[i] != "")
                {
                    combinedstring += dividedline[i];

                }
                
            }

            matnames.emplace_back(combinedstring);
           
        }
        else if (dividedline[0] == "usemtl" && selectedmat >= 0)
        {
            VertexBuffers[selectedmat] = VertexBuffer(verts);
            verts.clear();
            matnames.push_back(dividedline[1]);
            
            
            selectedmat++;

        }



    }
    if (stream.eof() && selectedmat > -1)
    {
        VertexBuffers[selectedmat] = VertexBuffer(verts);

    }











    stream.close();

    for (auto& i : matnames)
    {
        std::cout << i << "\n";
    }

}

ModelLoader::~ModelLoader()
{
}

void ModelLoader::Draw(Renderer& renderer)
{
    m_shadersource.SetUniformMat4fv("u_Model", m_modeluniform);

    if (ismaterialused)
    {
        for (int i = 0; i < VertexBuffers.size(); i++)
        {
            Materials& material = MatLoader.m_umats[matnames[i]];

            VertexBuffer& vb = VertexBuffers[i];

            vao.AddBuffer(vb, layout);

            MatLoader.SetUniforms(m_shadersource.GetShader(), material);

            renderer.Draw(vao, VertexBuffers[i].GetSize(), m_shadersource);



        }
    }

    else 
    {
        VertexBuffer& vb = VertexBuffers[0];
        vao.AddBuffer(vb, layout);
        renderer.Draw(vao, VertexBuffers[0].GetSize(), m_shadersource);


    }

}




















std::vector<std::string> ModelLoader::DivideString(const std::string& string, const std::string& delimiter)
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

void ModelLoader::DivideStringInto(const std::string& string, const std::string& delimiter, std::vector<std::string>& vector)
{
    size_t start = 0;
    size_t end = -1 * delimiter.size();
    

    do
    {
        start = end + delimiter.size();
        end = string.find(delimiter, start);
        vector.push_back(string.substr(start, end - start));

    } while (end != std::string::npos);

}

void ModelLoader::ReadTriangles(const std::string& description)
{

    const auto& indices = DivideString(description, "/");


    int i_pos = stoi(indices[0]);
    int i_tex = 0;
    int i_norm = 0;

    if (indices.size() == 2)
    {
        if (indices[1] != "")
        {
            i_tex = stoi(indices[1]);

            vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, uv[i_tex - 1].x, uv[i_tex - 1].y, 0, 0, 0));

        }
        else
        {

            vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, 0, 0, 0, 0, 0));


        }

    }
    else if (indices.size() == 3)
    {
        i_norm = stoi(indices[2]);

        if (indices[1] != "")
        {
            i_tex = stoi(indices[1]);
            vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, uv[i_tex - 1].x, uv[i_tex - 1].y, norm[i_norm - 1].x, norm[i_norm - 1].y, norm[i_norm - 1].z));
        }
        else
        {

            vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, 0, 0, norm[i_norm - 1].x, norm[i_norm - 1].y, norm[i_norm - 1].z));

        }



    }

    else
    {
        vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, 0, 0, 0, 0, 0));
    }

}

void ModelLoader::ReadTriangles(const std::string& description, std::vector<Vertex>& vertices)
{
    const auto& indices = DivideString(description, "/");


    int i_pos = stoi(indices[0]);
    int i_tex = 0;
    int i_norm = 0;

    if (indices.size() == 2)
    {
        if (indices[1] != "")
        {
            i_tex = stoi(indices[1]);

            vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, uv[i_tex - 1].x, uv[i_tex - 1].y, 0, 0, 0));

        }
        else
        {

            vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, 0, 0, 0, 0, 0));


        }
        
    }
    else if (indices.size() == 3)
    {
        i_norm = stoi(indices[2]);

        if (indices[1] != "")
        {
            i_tex = stoi(indices[1]);
            vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, uv[i_tex - 1].x, uv[i_tex - 1].y, norm[i_norm - 1].x, norm[i_norm - 1].y, norm[i_norm - 1].z));
        }
        else
        {

            vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, 0, 0, norm[i_norm - 1].x, norm[i_norm - 1].y, norm[i_norm - 1].z));

        }



    }

    else
    {
        vertices.push_back(Vertex(pos[i_pos - 1].x, pos[i_pos - 1].y, pos[i_pos - 1].z, 0, 0, 0, 0, 0));
    }
}

#include "ScreenShader.h"


ScreenShader::ScreenShader()
	:m_screenshader(ScreenVertexSource, ScreenFragmentSource)
{
}



void ScreenShader::Apply(Texture& texture)
{
	m_screenshader.Bind();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glDrawArrays(GL_TRIANGLES, 0, 6);




}
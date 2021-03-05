#include "cphipch.h"
#include "OpenGLShaderPipeline.h"

namespace Comphi::OpenGL {
	ShaderPipeline::~ShaderPipeline()
	{
		glDeleteProgramPipelines(1, &m_pipeline);
	}
	
	bool ShaderPipeline::InitPipeline()
	{
		// Init program pipeline
		if (m_pipeline == -1)
		{
			glGenProgramPipelines(1, &m_pipeline);
		}
		glUseProgramStages(m_pipeline, GL_ALL_SHADER_BITS, 0);

		return true;
	}

	bool ShaderPipeline::BindProgram(IShaderProgram& shaderProgram)
	{
		// Attach the first program to the vertex stage, and the second program
		// to the geometry and fragment stages
		glUseProgramStages(m_pipeline, shaderProgram.GetTypeMask(), shaderProgram.shaderID);
		return true;
	}

	bool ShaderPipeline::UnbindProgram(IShaderProgram& shaderProgram)
	{
		glUseProgramStages(m_pipeline, shaderProgram.GetTypeMask(), 0);
		return false;
	}

	bool ShaderPipeline::BindPipeline()
	{
		glBindProgramPipeline(m_pipeline);
		return false;
	}

}

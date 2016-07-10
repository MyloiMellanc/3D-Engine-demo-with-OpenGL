
#include "ProgramPipeline.h"

#include "../Support/Macro.h"
#include "GLSupport.h"
#include "Program.h"

#include <assert.h>

ProgramPipeline* ProgramPipeline::create()
{
	ProgramPipeline* pipeline = nullptr;
	GLuint pipeline_id = 0;

	glGenProgramPipelines(1, &pipeline_id);

	if (pipeline != 0)
	{
		pipeline = new ProgramPipeline();
		if (pipeline && pipeline->init())
		{
			pipeline->setID(pipeline_id);
			pipeline->setName("Program Pipeline");
		}
		else
		{
			glDeleteProgramPipelines(1, &pipeline_id);
			SAFE_DELETE(pipeline)	
		}
	}

	return pipeline;
}


void ProgramPipeline::setShaderSet(const shader_set& shaderset)
{
	GLuint pipeline_id = getID();

	//레퍼런스 상 ID 0인 프로그램이 입력되면 그 쉐이더 파트는 무시한다.
	glUseProgramStages(pipeline_id, GL_VERTEX_SHADER_BIT, _shaderset.vs_program_id);
	glUseProgramStages(pipeline_id, GL_TESS_CONTROL_SHADER_BIT, _shaderset.tcs_program_id);
	glUseProgramStages(pipeline_id, GL_TESS_EVALUATION_SHADER_BIT, _shaderset.tes_program_id);
	glUseProgramStages(pipeline_id, GL_GEOMETRY_SHADER_BIT, _shaderset.gs_program_id);
	glUseProgramStages(pipeline_id, GL_COMPUTE_SHADER_BIT, _shaderset.cs_program_id);
	glUseProgramStages(pipeline_id, GL_FRAGMENT_SHADER_BIT, _shaderset.fs_program_id);

	_shaderset = shaderset;
}

void ProgramPipeline::showUsingShader()
{
	//logger 작성시 작성
}

void ProgramPipeline::showUsingProgramList()
{
	//logger 작성시 작성
}

void ProgramPipeline::useThisRenderObject()
{
	glUseProgram(getID());
}

ProgramPipeline::~ProgramPipeline()
{
	GLuint pipeline_id = getID();
	glDeleteProgramPipelines(1, &pipeline_id);
}


ProgramPipeline::ProgramPipeline()
{
	_shaderset = { 0,0,0,0,0,0 };
}

bool ProgramPipeline::init()
{
	return true;
}
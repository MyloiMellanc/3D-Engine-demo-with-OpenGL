#ifndef __PROGRAM_MANAGER__
#define __PROGRAM_MANAGER__


#include "../Support/Macro.h"
#include "GLSupport.h"
#include <vector>

class Program;
class ProgramPipeline;


/*
* manager programs and one pipeline of OpenGL.
* Program which is separably linked is send its pointer to pipeline.
* Variable:
*	programlist ( not separably linked)
*	pipeline (contains separably linked programlist vector)
*/
class ProgramManager
{
public:
	/*
	* This class is created by this method only.
	* if it failed to create, return nullptr.
	*/
	static ProgramManager* create();


	/*
	* push program pointer to its programlist vector.
	* assert by (program != nullptr).
	*/
	void addProgram(Program* program);

	/*
	* add program pipeline class pointer to its pipelinelist vector.
	* assert by (pipeline != nullptr).
	*/
	void addProgramPipeline(ProgramPipeline* pipeline);


	/*
	* getter of program pointer.
	* using program name, or ID.
	* if fail to search, it return nullptr.
	*/
	Program* getProgram(const char* program_name) const;
	Program* getProgram(const GLuint program_id) const;


	/*
	* delete program in programlist vector, and OpenGL memory.
	* using program name, or ID.
	*/
	void deleteProgram(const char* program_name);
	void deleteProgram(const GLuint program_id);

	void deleteAllPrograms();
	void deleteAllProgramPipelines();



	/*
	* add information of programlist to log by using log macro.
	* it may be printf, or sent log to its own Logger class.
	*/
	void showProgramList();

	/*
	* delete all program in OpenGL memory.
	* delete program pipeline in OpenGL memory.
	*/
	~ProgramManager();

	/*
	* constructor method is used only in create method.
	* this class must be created by create method only.
	*/
PROTECT_CONSTRUCTOR_ACCESS:

	/*
	* Initialize programlist vector, pipeline pointer.
	*/
	ProgramManager();

	/*
	* return true.
	*/
	bool init();

protected:

private:

	/*
	* contains program object. both of separable or non separable progra.
	*/
	std::vector<Program*> _programlist;

	/*
	* it contains program pipeline object.
	*/
	std::vector<ProgramPipeline*> _pipelinelist;
};

#endif

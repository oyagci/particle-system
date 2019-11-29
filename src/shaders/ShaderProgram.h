#include "AShaderProgram.h"

class ShaderProgram : public AShaderProgram
{
public:
	bool Compile();
private:
	GLuint _id;
};

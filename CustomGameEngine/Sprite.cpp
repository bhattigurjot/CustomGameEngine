#include "Sprite.h"

Sprite::Sprite()
	:_vboID(0)
{
}


Sprite::~Sprite()
{
	// Free vertex buffer
	if (_vboID != 0)
	{
		glDeleteBuffers(1, &_vboID);
	}
}

void Sprite::Init(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	if (_vboID == 0) // if there is no id already
	{
		// Generate new buffer and change vbo id
		glGenBuffers(1, &_vboID);
		// Delete buffer in destructor
	}

	float vertexData[12]; // Each vertex is float, x and y, so 6 each

	// These are screen coordinates
	// First Triangle
	// First vertex (top right)
	vertexData[0] = x + width;
	vertexData[1] = y + height;
	// Second vertex (top left)
	vertexData[2] = x;
	vertexData[3] = y + height;
	// Third vertex (bottom left)
	vertexData[4] = x;
	vertexData[5] = y;
	// Second Triangle
	// Fourth vertex (bottom left)
	vertexData[6] = x;
	vertexData[7] = y;
	// Fifth vertex (bottom right)
	vertexData[8] = x + width;
	vertexData[9] = y;
	// Sixth vertex (top right)
	vertexData[10] = x + width;
	vertexData[11] = y + height;

	// Bind buffer, make it active
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	// Which data should be used?
	glBufferData(GL_ARRAY_BUFFER, 
		sizeof(vertexData), 
		vertexData, 
		GL_STATIC_DRAW);
	// Unbind the buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::Draw()
{
	// Bind buffer, make it active
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	// Only 1 vertex buffer attrib array, position
	glEnableVertexAttribArray(0);

	// tell where the data is
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	// Actually draw
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// Disable the vertex attrib
	glDisableVertexArrayAttrib(_vboID, 0);
	// Unbind the buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
/**
 * @file mesh.h
 * 
 * @brief The Mesh header file.
 * 
 * @section license License
 * This file is part of RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *   - Initial commit
 * - Copyright [year] [your name] <you@yourhost.com>
 *   - [description]
 */

#ifndef MESH_H
#define MESH_H

// Include GLEW
#include <GL/glew.h>

/// @brief The Mesh class generates meshes (vertices, normals, UV coordinates).
class Mesh
{
	public:
		Mesh();				///< @brief Constructor of the Mesh
		virtual ~Mesh();	///< @brief Destructor of the Mesh

		/// @brief get the vertices of the Mesh
		/// @return GLuint _vertexbuffer
		GLuint vertexbuffer() { return _vertexbuffer; };
		/// @brief get the normals of the Mesh
		/// @return GLuint _vnormalbuffer
		GLuint normalbuffer() { return _normalbuffer; };
		/// @brief get the UV's of the Mesh
		/// @return GLuint _uvbuffer
		GLuint uvbuffer() { return _uvbuffer; };

		/// @brief fills vertices, normals and UV's with values for a Sprite Mesh
		/// @param width the width of the Sprite
		/// @param height the height of the Sprite
		/// @param pivotx the x component of the pivot of the Sprite
		/// @param pivoty the y component of the pivot of the Sprite
		/// @param uvwidth 1.0f=full texture, 0.5f=2x2 texture, 0.25f=4x4 texture etc.
		/// @param uvheight 1.0f=full texture, 0.5f=2x2 texture, 0.25f=4x4 texture etc.
		/// @return void
		void generateSpriteMesh(int width, int height,
			float pivotx, float pivoty,
			float uvwidth, float uvheight
		);
	
	private:
		GLuint _vertexbuffer;	///< @brief internal list of vertices
		GLuint _normalbuffer;	///< @brief internal list of normals
		GLuint _uvbuffer;		///< @brief internal list of UV's
};

#endif /* MESH_H */ 

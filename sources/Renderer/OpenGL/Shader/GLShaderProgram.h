/*
 * GLShaderProgram.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_GL_SHADER_PROGRAM_H__
#define __LLGL_GL_SHADER_PROGRAM_H__


#include <LLGL/ShaderProgram.h>
#include "../OpenGL.h"


namespace LLGL
{


class GLShaderProgram : public ShaderProgram
{

    public:

        GLShaderProgram();
        ~GLShaderProgram();

        void AttachShader(Shader& shader) override;

        bool LinkShaders() override;

        std::string QueryInfoLog() override;

        std::vector<VertexAttribute> QueryVertexAttributes() const override;
        std::vector<ConstantBufferDescriptor> QueryConstantBuffers() const override;

        void BindVertexAttributes(const std::vector<VertexAttribute>& vertexAttribs, bool ignoreUnusedAttributes = false) override;
        void BindConstantBuffer(const std::string& name, unsigned int bindingIndex) override;

        //! Returns the shader program ID.
        inline GLuint GetID() const
        {
            return id_;
        }

    private:

        GLuint  id_         = 0;
        bool    linkStatus_ = false;

};


} // /namespace LLGL


#endif



// ================================================================================

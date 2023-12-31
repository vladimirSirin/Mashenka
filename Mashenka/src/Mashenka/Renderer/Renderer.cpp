﻿#include "mkpch.h"
#include "Renderer.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Renderer2D.h"


namespace Mashenka
{
    // Initialize the scene data
    Scope<Renderer::SceneData> Renderer::s_SceneData = CreateScope<SceneData>();

    // Init
    void Renderer::Init()
    {
        // Initialize the renderer API
        RenderCommand::Init();
        Renderer2D::Init();
    }

    void Renderer::OnWindowResize(uint32_t width, uint32_t height)
    {
        // Set the viewport
        RenderCommand::SetViewport(0, 0, width, height);
    }

    void Renderer::BeginScene(OrthographicCamera& camera)
    {
        // Set the view projection matrix of the scene
        s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {
        // Render the next frame
    }

    // Submit the vertex array to the RendererCommand
    // This is the function that will be called by the application
    void Renderer::Submit(std::shared_ptr<Shader>& shader, std::shared_ptr<VertexArray> vertexArray, const glm::mat4& transform)
    {
        shader->Bind(); // Bind the shader

        // Upload the uniform matrix to the shader
        const auto openglShader = std::dynamic_pointer_cast<OpenGLShader>(shader);
        openglShader->UploadUniformMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
        openglShader->UploadUniformMat4("u_Transform", transform);
        
        // Submit the vertex array to the RendererCommand
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }
}

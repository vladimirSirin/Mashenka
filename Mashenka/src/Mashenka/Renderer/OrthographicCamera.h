﻿#pragma once
#include "Camera.h"

namespace Mashenka
{
    class OrthographicCamera : public Camera
    {
    public:
        OrthographicCamera(float orthoLeft, float orthoRight, float orthoBottom, float orthoTop);

        void OnEvent(Event& e) override;

        void SetProjection(float left, float right, float bottom, float top) override;

    private:
  
    };
}

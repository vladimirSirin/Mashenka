﻿#pragma once

#include "mkpch.h"

#include "Mashenka/Core.h"
#include "Mashenka/Events/Event.h"

namespace Mashenka
{
    // This is the window property struct, easier to manage, expand for future use.
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Mashenka Engine",
            unsigned int width = 1280,
            unsigned int height = 720)
                :Title(title), Width(width), Height(height)
        {
            
        }
    };

    // Interface representing a desktop system based Window
    class MASHENKA_API Window
    {
    public:
        // wrapping a callable object/method with Event& input
        using EventCallbackFn = std::function<void(Event&)>;

        // Window base functions, in the actual implementation will be platform specific
        virtual ~Window() {}
        virtual void OnUpdate() = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // Window Attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
    
}
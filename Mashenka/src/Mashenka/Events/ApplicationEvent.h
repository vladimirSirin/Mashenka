﻿#pragma once
#include "Event.h"

namespace Mashenka
{
    class MASHENKA_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height)
        {
        }

        unsigned int GetWidth() const { return m_Width; }
        unsigned int GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << "," << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        unsigned int m_Width, m_Height;
    };

    class MASHENKA_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent(){}

        EVENT_CLASS_TYPE(WindowsClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class MASHENKA_API AppTickEvent : public Event
    {
    public:
        AppTickEvent(){}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class MASHENKA_API AppUpdateEvent: public Event
    {
    public:
        AppUpdateEvent(){}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class MASHENKA_API AppRenderEvent: public Event
    {
    public:
        AppRenderEvent(){}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}

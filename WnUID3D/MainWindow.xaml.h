#pragma once

#include "MainWindow.g.h"
#include "Common\DeviceResources.h"
#include "Common\StepTimer.h"
#include "Content\Sample3DSceneRenderer.h"
#include <mutex> // Include for std::mutex
namespace winrt::WnUID3D::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void CreateWindowSizeDependentResources();
        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void StartRenderLoop();
        void StopRenderLoop();
        std::mutex& GetMutex() { return m_mutex; }
        // Rendering loop timer.
        void ProcessInput();
        void Update();
        bool Render();
        // Cached pointer to device resources.
        std::shared_ptr<DX::DeviceResources> m_deviceResources;

        // TODO: Replace with your own content renderers.
        std::unique_ptr<Sampling::Sample3DSceneRenderer> m_sceneRenderer;

        winrt::Windows::Foundation::IAsyncAction m_renderLoopWorker;
        std::mutex m_mutex;
        DX::StepTimer m_timer;
        // Track current input pointer position.
        float m_pointerLocationX = 0.0f;
    };
}

namespace winrt::WnUID3D::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}

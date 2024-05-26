#include "pch.h"
#include "MainWindow.xaml.h"
//#include <openvdb/openvdb.h>
//#include <iostream>
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.System.Threading.h>
using namespace Sampling;

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WnUID3D::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::CreateWindowSizeDependentResources()
    {
        // TODO: Replace this with the size-dependent initialization of your app's content.
        m_sceneRenderer->CreateWindowSizeDependentResources();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        m_deviceResources = std::make_shared<DX::DeviceResources>();

        m_deviceResources->SetSwapChainPanel(swapChainPanel());
        // TODO: Replace this with your app's content initialization.
        m_sceneRenderer = std::unique_ptr<Sample3DSceneRenderer>(new Sample3DSceneRenderer(m_deviceResources));
        CreateWindowSizeDependentResources();
        //// Register to be notified if the Device is lost or recreated
        ////m_deviceResources->RegisterDeviceNotify(this);
        StartRenderLoop();
        //auto m_deviceResources = std::make_shared<DX::DeviceResources>();
        //auto panelNative{ swapChainPanel().as<ISwapChainPanelNative>() };

        //auto panel = swapChainPanel();
        //m_deviceResources->SetSwapChainPanel(swapChainPanel());

        //// Register to be notified if the Device is lost or recreated
        ////m_deviceResources->RegisterDeviceNotify(this);
        //m_sceneRenderer->CreateWindowSizeDependentResources();

        //DX::StepTimer m_timer;
        //float m_pointerLocationX;
        //m_timer.GetFrameCount();
        //m_sceneRenderer->StartTracking();
        //m_sceneRenderer->TrackingUpdate(0);
        // Don't try to render anything before the first Update.

        // TODO: Replace this with your app's content initialization.
        // Initialize the Windows Runtime
//        init_apartment(apartment_type::single_threaded);
        myButton().Content(box_value(L"Clicked"));
        m_deviceResources->Present();
//
//        UINT32_t creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
//
//        D3D_FEATURE_LEVEL featureLevels[] =
//        {
//            D3D_FEATURE_LEVEL_11_1,
//            D3D_FEATURE_LEVEL_11_0,
//            D3D_FEATURE_LEVEL_10_1,
//            D3D_FEATURE_LEVEL_10_0,
//            D3D_FEATURE_LEVEL_9_3,
//            D3D_FEATURE_LEVEL_9_2,
//            D3D_FEATURE_LEVEL_9_1
//        };
//
//        // Create the Direct3D device.
//        winrt::com_ptr<::ID3D11Device> d3dDevice;
//        D3D_FEATURE_LEVEL supportedFeatureLevel;
//        winrt::check_hresult(::D3D11CreateDevice(
//            nullptr,
//            D3D_DRIVER_TYPE_HARDWARE,
//            0,
//            creationFlags,
//            featureLevels,
//            ARRAYSIZE(featureLevels),
//            D3D11_SDK_VERSION,
//            d3dDevice.put(),
//            &supportedFeatureLevel,
//            nullptr)
//        );
//        // Get the Direct3D device.
//        winrt::com_ptr<::IDXGIDevice> dxgiDevice{
//            d3dDevice.as<::IDXGIDevice>() };
//
//        // Create the Direct2D device and a corresponding context.
//        winrt::com_ptr<::ID2D1Device> d2dDevice;
//        ::D2D1CreateDevice(dxgiDevice.get(), nullptr, d2dDevice.put());
//
//        winrt::com_ptr<::ID2D1DeviceContext> d2dDeviceContext;
//        winrt::check_hresult(
//            d2dDevice->CreateDeviceContext(
//                D2D1_DEVICE_CONTEXT_OPTIONS_NONE,
//                d2dDeviceContext.put()
//            )
//        );
//
//        // MainPage.cpp | paste this at the end of MainPage::ClickHandler
//// Get the DXGI adapter.
//        winrt::com_ptr< ::IDXGIAdapter > dxgiAdapter;
//        dxgiDevice->GetAdapter(dxgiAdapter.put());
//
//        // Get the DXGI factory.
//        winrt::com_ptr< ::IDXGIFactory2 > dxgiFactory;
//        dxgiFactory.capture(dxgiAdapter, &IDXGIAdapter::GetParent);
//
//        DXGI_SWAP_CHAIN_DESC1 swapChainDesc{ 0 };
//        swapChainDesc.Width = 500;
//        swapChainDesc.Height = 500;
//        swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; // This is the most common swapchain format.
//        swapChainDesc.Stereo = false;
//        swapChainDesc.SampleDesc.Count = 1; // Don't use multi-sampling.
//        swapChainDesc.SampleDesc.Quality = 0;
//        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//        swapChainDesc.BufferCount = 2;
//        swapChainDesc.Scaling = DXGI_SCALING_STRETCH;
//        swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL; // We recommend using this swap effect for all applications.
//        swapChainDesc.Flags = 0;
//
//        // Create a swap chain by calling IDXGIFactory2::CreateSwapChainForComposition.
//        winrt::com_ptr< ::IDXGISwapChain1 > swapChain;
//        dxgiFactory->CreateSwapChainForComposition(
//            d3dDevice.get(),
//            &swapChainDesc,
//            nullptr,
//            swapChain.put());
//        // MainPage.cpp | paste this at the end of MainPage::ClickHandler
//// Get native interface for SwapChainPanel
//
//        winrt::check_hresult(
//            panelNative->SetSwapChain(swapChain.get())
//        );
//
//        // Create a Direct2D target bitmap associated with the
//// swap chain back buffer, and set it as the current target.
//        D2D1_BITMAP_PROPERTIES1 bitmapProperties =
//            D2D1::BitmapProperties1(
//                D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW,
//                D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED),
//                96.f,
//                96.f
//            );
//
//        winrt::com_ptr<::IDXGISurface> dxgiBackBuffer;
//        swapChain->GetBuffer(0, __uuidof(dxgiBackBuffer), dxgiBackBuffer.put_void());
//
//        winrt::com_ptr< ::ID2D1Bitmap1 > targetBitmap;
//        winrt::check_hresult(
//            d2dDeviceContext->CreateBitmapFromDxgiSurface(
//                dxgiBackBuffer.get(),
//                &bitmapProperties,
//                targetBitmap.put()
//            )
//        );
//
//        d2dDeviceContext->SetTarget(targetBitmap.get());
//
//        // Draw using Direct2D context.
//        d2dDeviceContext->BeginDraw();
//
//        d2dDeviceContext->Clear(D2D1::ColorF(D2D1::ColorF::Orange));
//
//        //winrt::com_ptr<::ID2D1SolidColorBrush> brush;
//        //winrt::check_hresult(d2dDeviceContext->CreateSolidColorBrush(
//        //    D2D1::ColorF(D2D1::ColorF::Chocolate),
//        //    D2D1::BrushProperties(0.8f),
//        //    brush.put()));
//
//        //D2D1_SIZE_F const size{ 350, 500 };
//        //D2D1_RECT_F const rect{ 100.0f, 100.0f, size.width - 100.0f, size.height - 100.0f };
//        //d2dDeviceContext->DrawRectangle(rect, brush.get(), 100.0f);
//
//        d2dDeviceContext->EndDraw();
//
//        swapChain->Present(1, 0);
//        
    }
    void MainWindow::StartRenderLoop()
    {	
        // If the animation render loop is already running then do not start another thread.
        if (m_renderLoopWorker && m_renderLoopWorker.Status() == winrt::Windows::Foundation::AsyncStatus::Started)
        {
            return;
        }

        // Create a task that will be run on a background thread.
        auto workItemHandler = [this](winrt::Windows::Foundation::IAsyncAction const& action)
            {
                // Calculate the updated frame and render once per vertical blanking interval.
                while (action.Status() == winrt::Windows::Foundation::AsyncStatus::Started)
                {
                    std::lock_guard<std::mutex> lock(m_mutex);
                    Update();
                    if (Render())
                    {
                        m_deviceResources->Present();
                    }
                }
            };

        // Run task on a dedicated high priority background thread.
        m_renderLoopWorker = winrt::Windows::System::Threading::ThreadPool::RunAsync(
            winrt::Windows::System::Threading::WorkItemHandler(workItemHandler),
            winrt::Windows::System::Threading::WorkItemPriority::High,
            winrt::Windows::System::Threading::WorkItemOptions::TimeSliced
        );
    }
    void MainWindow::StopRenderLoop()
    {
		m_renderLoopWorker.Cancel();
    }
    void MainWindow::ProcessInput()
    {
    }
    void MainWindow::Update()
    {
        ProcessInput();

        // Update scene objects.
        m_timer.Tick([&]()
            {
                // TODO: Replace this with your app's content update functions.
                m_sceneRenderer->Update(m_timer);
            });
    }
    bool MainWindow::Render()
    {
        if (m_timer.GetFrameCount() == 0)
        {
            return false;
        }
        auto context = m_deviceResources->GetD3DDeviceContext();

        // Reset the viewport to target the whole screen.
        auto viewport = m_deviceResources->GetScreenViewport();
        context->RSSetViewports(1, &viewport);

        // Reset render targets to the screen.
        ID3D11RenderTargetView* const targets[1] = { m_deviceResources->GetBackBufferRenderTargetView() };
        context->OMSetRenderTargets(1, targets, m_deviceResources->GetDepthStencilView());

        // Clear the back buffer and depth stencil view.
        context->ClearRenderTargetView(m_deviceResources->GetBackBufferRenderTargetView(), DirectX::Colors::CornflowerBlue);
        context->ClearDepthStencilView(m_deviceResources->GetDepthStencilView(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

        // Render the scene objects.
        // TODO: Replace this with your app's content rendering functions.
        m_sceneRenderer->Render();
    }
}

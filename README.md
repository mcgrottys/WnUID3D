<H1>D3D Template UWP -> WinRT/WinUI3</H1>

I was trying out some DirectX11 stuff and wanted to work with OpenVDB files but I was learning in a UWP environment which caused issues with the VCPKG build.
I was able to pull OPENVDB into WinRT so I decided I'd try that instead.
I could not find any templates to build a non UWP WinRT desktop app with Direct3D.

That lead me down this path, and I am sharing my work to maybe save your time.

I am still missing interactivity, and you need to press the button to start.
Probably some other issues too.

Most changes involved replacing ComPtr with com_ptr

Changes to threading, it probably is less optimized now tbh, I just wanted it to work.

The WinRT UI elements use structs instead of classes for some reason.

Also, a bunch of namespace changes.

Please fork and improve. I really want to see more DirectX stuff on Github.

Also yes, I should be using DirectX12, I will start using that soon.

Also, NGL I used ChatGPT on several sections, and that code seemed sus (mine too), but hey as you can see I've got a spinning cube now:

![image](https://github.com/mcgrottys/WnUID3D/assets/8999072/82b31051-c3b5-49eb-8d97-260b105bc418)

P.S. I pulled the code and tried debugging, the first time it failed to deploy. It wasn't until local machine appeared as the start object that it started working again. Not sure how I fixed it... good luck!

Update:

Okay so it seems if you create a template from this you also need to create a package.appxmanifest

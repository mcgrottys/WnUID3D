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

I figured out the deploy failures. Seems like you need to make sure that these Imports/Targets are set. For some reason when importing the project it decided to target a newer version that broke the build configs.

  <Import Project="..\packages\Microsoft.WindowsAppSDK.1.5.240311000\build\native\Microsoft.WindowsAppSDK.props" Condition="Exists('..\packages\Microsoft.WindowsAppSDK.1.5.240311000\build\native\Microsoft.WindowsAppSDK.props')" />
  <Import Project="..\packages\Microsoft.Windows.SDK.BuildTools.10.0.22621.756\build\Microsoft.Windows.SDK.BuildTools.props" Condition="Exists('..\packages\Microsoft.Windows.SDK.BuildTools.10.0.22621.756\build\Microsoft.Windows.SDK.BuildTools.props')" />
  <Import Project="..\packages\Microsoft.Windows.CppWinRT.2.0.230706.1\build\native\Microsoft.Windows.CppWinRT.props" Condition="Exists('..\packages\Microsoft.Windows.CppWinRT.2.0.230706.1\build\native\Microsoft.Windows.CppWinRT.props')" />
    <!--..........................-->
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
    <Import Project="..\packages\Microsoft.Windows.CppWinRT.2.0.230706.1\build\native\Microsoft.Windows.CppWinRT.targets" Condition="Exists('..\packages\Microsoft.Windows.CppWinRT.2.0.230706.1\build\native\Microsoft.Windows.CppWinRT.targets')" />
    <Import Project="..\packages\Microsoft.Windows.SDK.BuildTools.10.0.22621.756\build\Microsoft.Windows.SDK.BuildTools.targets" Condition="Exists('..\packages\Microsoft.Windows.SDK.BuildTools.10.0.22621.756\build\Microsoft.Windows.SDK.BuildTools.targets')" />
    <Import Project="..\packages\Microsoft.WindowsAppSDK.1.5.240311000\build\native\Microsoft.WindowsAppSDK.targets" Condition="Exists('..\packages\Microsoft.WindowsAppSDK.1.5.240311000\build\native\Microsoft.WindowsAppSDK.targets')" />
    <Import Project="..\packages\Microsoft.Windows.ImplementationLibrary.1.0.220914.1\build\native\Microsoft.Windows.ImplementationLibrary.targets" Condition="Exists('..\packages\Microsoft.Windows.ImplementationLibrary.1.0.220914.1\build\native\Microsoft.Windows.ImplementationLibrary.targets')" />
  </ImportGroup>
  <Target Name="EnsureNuGetPackageBuildImports" BeforeTargets="PrepareForBuild">
    <PropertyGroup>
      <ErrorText>This project references NuGet package(s) that are missing on this computer. Use NuGet Package Restore to download them.  For more information, see http://go.microsoft.com/fwlink/?LinkID=322105. The missing file is {0}.</ErrorText>
    </PropertyGroup>
    <Error Condition="!Exists('..\packages\Microsoft.Windows.CppWinRT.2.0.230706.1\build\native\Microsoft.Windows.CppWinRT.props')" Text="$([System.String]::Format('$(ErrorText)', '..\packages\Microsoft.Windows.CppWinRT.2.0.230706.1\build\native\Microsoft.Windows.CppWinRT.props'))" />
    <Error Condition="!Exists('..\packages\Microsoft.Windows.CppWinRT.2.0.230706.1\build\native\Microsoft.Windows.CppWinRT.targets')" Text="$([System.String]::Format('$(ErrorText)', '..\packages\Microsoft.Windows.CppWinRT.2.0.230706.1\build\native\Microsoft.Windows.CppWinRT.targets'))" />
    <Error Condition="!Exists('..\packages\Microsoft.Windows.SDK.BuildTools.10.0.22621.756\build\Microsoft.Windows.SDK.BuildTools.props')" Text="$([System.String]::Format('$(ErrorText)', '..\packages\Microsoft.Windows.SDK.BuildTools.10.0.22621.756\build\Microsoft.Windows.SDK.BuildTools.props'))" />
    <Error Condition="!Exists('..\packages\Microsoft.Windows.SDK.BuildTools.10.0.22621.756\build\Microsoft.Windows.SDK.BuildTools.targets')" Text="$([System.String]::Format('$(ErrorText)', '..\packages\Microsoft.Windows.SDK.BuildTools.10.0.22621.756\build\Microsoft.Windows.SDK.BuildTools.targets'))" />
    <Error Condition="!Exists('..\packages\Microsoft.WindowsAppSDK.1.5.240311000\build\native\Microsoft.WindowsAppSDK.props')" Text="$([System.String]::Format('$(ErrorText)', '..\packages\Microsoft.WindowsAppSDK.1.5.240311000\build\native\Microsoft.WindowsAppSDK.props'))" />
    <Error Condition="!Exists('..\packages\Microsoft.WindowsAppSDK.1.5.240311000\build\native\Microsoft.WindowsAppSDK.targets')" Text="$([System.String]::Format('$(ErrorText)', '..\packages\Microsoft.WindowsAppSDK.1.5.240311000\build\native\Microsoft.WindowsAppSDK.targets'))" />
    <Error Condition="!Exists('..\packages\Microsoft.Windows.ImplementationLibrary.1.0.220914.1\build\native\Microsoft.Windows.ImplementationLibrary.targets')" Text="$([System.String]::Format('$(ErrorText)', '..\packages\Microsoft.Windows.ImplementationLibrary.1.0.220914.1\build\native\Microsoft.Windows.ImplementationLibrary.targets'))" />
  </Target>

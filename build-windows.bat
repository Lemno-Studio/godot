mkdir	.\.tmp

curl -L -o .\.tmp\cppwinrt.zip https://www.nuget.org/api/v2/package/Microsoft.Windows.CppWinRT/2.0.190401.2
tar -xf .\.tmp\cppwinrt.zip -C .\.tmp
.\.tmp\bin\cppwinrt.exe -in local -out .\platform\windows -verbose

rmdir /s /q .\.tmp

cmake -Bbuild -GNinja
.\.venv\Scripts\scons.exe d3d12=no angle=no use_llvm=yes use_mingw=yes

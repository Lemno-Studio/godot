winget install Microsoft.VisualStudio.2022.BuildTools
python -m pip install scons

curl -L -o cppwinrt.zip https://www.nuget.org/api/v2/package/Microsoft.Windows.CppWinRT/2.0.190401.2
mkdir	.\.tmp
tar -xf cppwinrt.zip -C .\.tmp
.\.tmp\bin\cppwinrt.exe -in local -out .\platform\windows -verbose
rmdir /s /q .\.tmp

echo "DONE. Restart your terminal"

winget install Microsoft.VisualStudio.2022.BuildTools
python -m pip install scons

curl -o cppwinrt.zip https://www.nuget.org/api/v2/package/Microsoft.Windows.CppWinRT/2.0.190401.2
tar -xf cppwinrt.zip .\.tmp
tar -xf .\.tmp\bin\cppwinrt.exe -in local -out .\platform\windows -verbose
rmdir /s /q .\tmp

echo "DONE. Restart your terminal"

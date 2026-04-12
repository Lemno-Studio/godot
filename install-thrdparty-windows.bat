winget install BrechtSanders.WinLibs.POSIX.UCRT.LLVM
winget install python

python -m venv .\.venv
.\.venv\Scripts\pip install scons

echo "DONE. Restart your terminal"

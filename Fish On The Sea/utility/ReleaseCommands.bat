set ProjectDir=%~1
set TargetDir=%~2
set DLLDirSFML=%~3

xcopy "%ProjectDir%res\" "%TargetDir%res\" /E /Y
copy "%DLLDirSFML%\raylib.dll" "%TargetDir%raylib.dll" /Y

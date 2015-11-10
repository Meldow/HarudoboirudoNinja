@echo Cleaning solution...
:: solution
del /s /q *.sdf > NUL
rd /s /q scripts\vs2010\ipch > NUL
:: scripts
del /s /q *.user > NUL
del /s /q *.log > NUL
:: cglib
del cglib\lib\cglib_d.lib > NUL
del cglib\lib\cglib.lib > NUL
:: obj
del /s /q *.obj > NUL
del /s /q *.tlog > NUL
del /s /q *.lastbuildstate > NUL
del /s /q *.idb > NUL
del /s /q *.pdb > NUL
del /s /q *.manifest > NUL
del /s /q *.res > NUL
del /s /q *.rc > NUL
:: projects
del /s /q *.exe > NUL
del /s /q *.ilk > NUL
del /s /q *.exp > NUL
del /s /q *.unsuccessfulbuild > NUL
del projects\bin\*.lib > NUL
@echo Done.
pause
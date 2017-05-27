IF EXIST .\tower.exe .\tower.exe DSA.Vent.Tower.dbnf DSA::Vent::Tower::CPPGenerator

cl.exe /I..\..\..\ *.cpp /link /out:tower.exe

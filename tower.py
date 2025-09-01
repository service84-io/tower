import sys

import S84_Tower_System_ctcode
import S84_Tower_Main_ctcode

class FileWriter(S84_Tower_System_ctcode.OutputStream):
    def __init__(self: 'FileWriter', file_name: str):
        self.target = open(file_name, 'w')

    def WriteLine(self: 'LoggerClass', line:  'str') -> None:
        self.target.write(line)
        self.target.write("\n")

class LoggerClass(S84_Tower_System_ctcode.OutputStream):
    def WriteLine(self: 'LoggerClass', line:  'str') -> None:
        print(line)

class System(S84_Tower_System_ctcode.System):
    def ReadFileToString(self: 'System', file_name: 'str') -> 'str':
        result:str = ""
        file = open(file_name)

        for line in file:
            result = result + line

        return result
    
    def OpenFileWriter(self: 'System', file_name: 'str') -> 'S84_Tower_System_ctcode.OutputStream':
        return FileWriter(file_name)
    
    def GetLoggerDestination(self: 'System') -> 'S84_Tower_System_ctcode.OutputStream':
        return LoggerClass()

def main():
    pass

if __name__ == "__main__":
    system: System = System()
    main: S84_Tower_Main_ctcode.Main = S84_Tower_Main_ctcode.Main()
    dbnf_file_name: str = ""
    generator_name: str = ""

    if len(sys.argv) == 3:
        dbnf_file_name = sys.argv[1]
        generator_name = sys.argv[2]
        
    sys.exit(main.RunMain(system, dbnf_file_name, generator_name))

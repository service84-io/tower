import S84_Tower_System_ctcode
import S84_Tower_Generator_ctcode
import S84_Tower_Generator_CPPGenerator_ctcode
import S84_Tower_Generator_CTCodeGenerator_ctcode
import S84_Tower_Generator_LogToConsole_ctcode
import S84_Tower_dbnf_ctcode

def ClearList(input: list) -> None: input.clear()
def Size(input: list) -> int: return len(input)
def Element(input: list, element: int ) -> any: return input[element]
def Append(input: list, element: any) -> None: input.append(element)
def ClearMap(input: dict) -> None: input.clear()
def SetKV(input: dict, key: str, element: any) -> None: input[key] = element
def Keys(input: dict) -> list[str]:
    result: list[str] = []
    for key in input.keys():
        result.append(key)
    return result
def HasKV(input: dict, key: str) -> bool: return key in input
def GetKV(input: dict, key: str) -> any: return input[key]
def Length(input: str) -> int: return len(input)
def At(input: str, index: int) -> str: return input[index:index+1]
def IntAt(input: str, index: int) -> int: return ord(input[index:index+1])
def Concat(left: str, right: str) -> str: return left + right

class Main:
    def __init__(self: 'Main'):
        pass

    def GetCPPGenerator(self: 'Main') -> 'S84_Tower_Generator_ctcode.Generator':
        return S84_Tower_Generator_CPPGenerator_ctcode.CPPGenerator()

    def GetCTCodeGenerator(self: 'Main') -> 'S84_Tower_Generator_ctcode.Generator':
        return S84_Tower_Generator_CTCodeGenerator_ctcode.CTCodeGenerator()

    def GetLogToConsole(self: 'Main') -> 'S84_Tower_Generator_ctcode.Generator':
        return S84_Tower_Generator_LogToConsole_ctcode.LogToConsole()

    def RunMain(self: 'Main',system: 'S84_Tower_System_ctcode.System',dbnf_file_name: 'str',generator: 'str') -> 'int':
        logger: 'S84_Tower_System_ctcode.OutputStream' = system.GetLoggerDestination()
        generators: 'dict[str, S84_Tower_Generator_ctcode.Generator]' = {}
        SetKV(generators,"CPPGenerator",self.GetCPPGenerator())
        SetKV(generators,"DSA::Vent::Tower::CPPGenerator",self.GetCPPGenerator())
        SetKV(generators,"S84::Tower::CPPGenerator",self.GetCPPGenerator())
        SetKV(generators,"s84::tower::CPPGenerator",self.GetCPPGenerator())
        SetKV(generators,"CTCodeGenerator",self.GetCTCodeGenerator())
        SetKV(generators,"DSA::Vent::Tower::CTCodeGenerator",self.GetCTCodeGenerator())
        SetKV(generators,"S84::Tower::CTCodeGenerator",self.GetCTCodeGenerator())
        SetKV(generators,"s84::tower::CTCodeGenerator",self.GetCTCodeGenerator())
        SetKV(generators,"LogToConsole",self.GetLogToConsole())
        if dbnf_file_name=="" or not HasKV(generators,generator):
            logger.WriteLine("tower <DBNF_File> <Generator>")
            logger.WriteLine("Known generators:")
            registered_generators: 'list[str]' = Keys(generators)
            index: 'int' = 0
            while index<Size(registered_generators):
                logger.WriteLine(Concat("    ",Element(registered_generators,index)))
                index = index+1
            return 1
        dbnf: 'str' = system.ReadFileToString(dbnf_file_name)
        if dbnf=="":
            logger.WriteLine(Concat("The file ",Concat(dbnf_file_name," is empty or does not exist.")))
            return 1
        dbnf_large_string: 'S84_Tower_dbnf_ctcode.LargeString' = S84_Tower_dbnf_ctcode.LargeString()
        dbnf_large_string.SetData(dbnf)
        index: 'S84_Tower_dbnf_ctcode.LengthString' = S84_Tower_dbnf_ctcode.LengthString()
        index.SetData(dbnf_large_string)
        index.SetStart(0)
        index.SetLength(Length(dbnf))
        parser_network: 'S84_Tower_dbnf_ctcode.ParserNetwork' = S84_Tower_dbnf_ctcode.ParserNetwork()
        parser_network.Initialize()
        grammar_result: 'S84_Tower_dbnf_ctcode.GrammarResult' = S84_Tower_dbnf_ctcode.GrammarResult()
        grammar_parser: 'S84_Tower_dbnf_ctcode.GrammarParser' = parser_network.GetGrammarParser()
        logger.WriteLine("Parsing Grammar...")
        grammar_parser.ParseSingleSave(index,grammar_result)
        if grammar_result.GetResult() and index.GetLength()==0:
            logger.WriteLine("Done Parsing Grammar!")
            target_generator: 'S84_Tower_Generator_ctcode.Generator' = GetKV(generators,generator)
            return target_generator.GenerateParser(system,grammar_result.GetValue(),dbnf_file_name)
        else:
            logger.WriteLine(Concat("Failed to parse ",Concat(dbnf_file_name,".")))
            return 1


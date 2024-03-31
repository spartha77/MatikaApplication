#pragma once
#include <string>
#include <vector>
#include <complex>
#include <algorithm>
#include <optional>
#include <type_traits>
#include <sstream>
#include <filesystem>
#include <map>
#include <variant>
#include <fstream>
#include <exception>


#ifdef MATIKAKERNEL_EXPORTS
#define MATIKAKERNEL_API __declspec(dllexport)
#else
#define MATIKAKERNEL_API __declspec(dllimport)
#endif

namespace fs = std::filesystem;

#include "MatrixWrapper.h"

class MATIKAKERNEL_API Interpreter
{
private:

	// Command specifics
	std::string m_OutMatrixTag = "res";
	ExecutionSubType m_ExecutionSubType = ExecutionSubType::None;
	std::string m_var, m_Filename;
	std::string m_Statement;
	std::vector<std::string> m_StatementTokens;
	std::unique_ptr<MatrixWrapper> m_MatrixWrapperPtr;
	
public:
	StatementType m_StatementType = StatementType::None;
	Interpreter();
	void parse(const std::string& statement); //throws
	void syntaxAnalyzer();
	void  readMatrixDataFromFile(const std::string& statement);
	void handleExecutionStatement();
	void handleInlineDataWithType();
	void handleInlineDataWithoutType();
	void semanticAnalyzer(); // throws
private:
	std::string getHelpMessage()
	{
		std::string message;
		message += "Correct usage <matrix_name> = <optional type> <name> = <rows>, <.m_Columns>,";
		message += "[n1, n2, ..m_Rows * .m_Columns numbers]; \n";
		message += "In the case of complex numbers ==>>  <matrix_name> = <optional type <complex int>>";
		message += "<name> = <rows>, <.m_Columns>, [(n1,n2),(n3,n4)..]; \n";
		return message;
	}
};
#pragma once

// Includes
#include <Windows.h>
#include <stdio.h>
#include "TSingleton.hpp"

// Defines
#define MAX_BUFFER 1024						// Max size for the buffer
#define L_FAIL false						// Function was successful
#define L_OK true							// Function failed
#define g_pLogfile CLogfile::Get()			// Macro for easier usage

// Colors for the text
enum FONTCOLORS
{
	BLACK,
	RED,
	GREEN,
	BLUE,
	PURPLE
};

// Classdeclaration
//
class CLogfile : public TSingleton<CLogfile>
{
	// Memberfunctions
public:
	CLogfile();
	~CLogfile();
	void CreateLogfile(const char* logName);
	void WriteTopic(const char* topic, int size);
	void Textout(const char* text);
	void Textout(int color, const char* text);
	void Textout(int color, bool list, const char* text);
	void fTextout(const char* text, ...);
	void fTextout(int color, const char* text, ...);
	void fTextout(int color, bool list, const char* text, ...);
	void FunctionResult(const char* name, bool result);

	// Membervariables
private:
	FILE* m_Logfile;
};
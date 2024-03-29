#include "Logfile.hpp"

// Constructor
CLogfile::CLogfile()
{

}

// Destructor - Outputs a message and closes the Logfile
CLogfile::~CLogfile()
{
	// End of Logfile, write and close file
	Textout("<br><br>--END OF LOGFILE--</font></body></html>");
	fclose(m_Logfile);
}

// Task: Create Logfile and write the header
void CLogfile::CreateLogfile(const char* logName)
{
	// Empty Logfile and write the HTML header
	fopen_s(&m_Logfile, logName, "w");
	Textout("<html><head><title>Logfile</title></head>");
	Textout("<body><font face='courier new'>");
	WriteTopic("Logfile", 3);

	// Output current build-configuration
	#ifdef _DEBUG
		Textout("BUILD: DEBUG<br>");
	#else
		Textout("BUILD: RELEASE<br>");
	#endif
	
	// Link for E-Mail-Adress
	Textout("<a href='mailto:rene.reifen@icloud.com?subject=Logfile'>");
	Textout("Send E-Mail to me</a><br><br>");

	// Close Logfile and open again with append
	fclose(m_Logfile);
	fopen_s(&m_Logfile, logName, "a");
}

// WriteTopic
// Task: Create a HTML header
void CLogfile::WriteTopic(const char* topic, int size)
{
	// Create HTML header and flush
	Textout("<table cellspacing='0' cellpadding='0' width='100%%'");
	Textout("bgcolor='#DFDFE5'>\n<tr>\n<td>\n<font face='arial'");
	fTextout("size='+%i'>\n", size);
	Textout(topic);
	Textout("</font>\n</td>\n</tr>\n</table>\n<br>");
	fflush(m_Logfile);
}

// Textout
// Task: Write text to Logfile (black)
void CLogfile::Textout(const char* text)
{
	// Write text to file and flush
	fprintf(m_Logfile, text);
	fflush(m_Logfile);
}

// Textout
// Task: Write text to Logfile (colored)
void CLogfile::Textout(int color, const char* text)
{
	Textout(color, false, text);
}

// Textout
// Task: Write texto to Logfile (colored, list)
void CLogfile::Textout(int color, bool list, const char* text)
{
	// Create list-tag
	if (list)
		Textout("<li>");

	// Create colortag
	switch (color)
	{
	case BLACK:
		Textout("<font color=black>"); break;
	case RED:
		Textout("<font color=red>"); break;
	case GREEN:
		Textout("<font color=green>"); break;
	case BLUE:
		Textout("<font color=blue>"); break;
	case PURPLE:
		Textout("<font color=purple>"); break;
	};

	// Write the text
	Textout(text);
	Textout("</font>");

	if (!list)
		Textout("<br>");
	else
		Textout("</li>");
}

// fTextout
// Task: Create formatted text and write it to the Logfile
void CLogfile::fTextout(const char* text, ...)
{
	char buffer[MAX_BUFFER];		// Char buffer
	va_list pArgList;				// List of given arguments

	// Create string from arguments
	va_start(pArgList, text);
	vsprintf_s(buffer, MAX_BUFFER, text, pArgList); 
	va_end(pArgList);

	// Write generated string to Logfile
	Textout(buffer);
}

// fTextout
// Task: create formatted text and write it to the Logfile (colored)
void CLogfile::fTextout(int color, const char* text, ...)
{
	char buffer[MAX_BUFFER];		// Char buffer
	va_list pArgList;				// List of given arguments
	
	va_start(pArgList, text);
	vsprintf_s(buffer, MAX_BUFFER, text, pArgList);
	va_end(pArgList);

	Textout(color, buffer);
}

// fTextout
// Task: Create formatted text and write it to the Logfile (colored, list)
void CLogfile::fTextout(int color, bool list, const char* text, ...)
{
	char buffer[MAX_BUFFER];		// Char buffer
	va_list pArgList;				// List of given arguments

	va_start(pArgList, text);
	vsprintf_s(buffer, MAX_BUFFER, text, pArgList);
	va_end(pArgList);

	Textout(color, list, buffer);
}

// FunctionResult
// Task: Output OK or ERROR for functioncall
void CLogfile::FunctionResult(const char* name, bool result)
{
	if (L_OK == result)
	{
		Textout("<table width='100%%' cellSpacing='1' cellPadding='5'");
		Textout(" border='0' bgcolor='#C0C0C0'><tr><td bgcolor=");
		fTextout("'#FFFFFF' width='35%%'> %s </td>", name);
		Textout("<td bgcolor='#FFFFFF' width='30%%'><font color =");
		Textout("'green'>OK</font></td><td bgcolor='#FFFFFF' ");
		Textout("width='35%%'>-/-</td></tr></table>");
	}
	else 
	{
		Textout("<table width='100%%' cellSpacing='1' cellPadding='5'");
		Textout(" border='0' bgcolor='#C0C0C0'><tr><td bgcolor=");
		fTextout("'#FFFFFF' width='35%%'>%s</td>", name);
		Textout("<td bgcolor='#FFFFFF' width='30%%'><font color =");
		Textout("'red'>ERROR</font></td><td bgcolor='#FFFFFF'");
		Textout("width='35%%'>-/-</td></tr></table>");
	}
}


#pragma once
#include <string>
#include <fnd/types.h>
#include <fnd/IFile.h>
#include <nx/ContentMetaBinary.h>

#include "nstool.h"

class CnmtProcess
{
public:
	CnmtProcess();
	~CnmtProcess();

	void process();

	void setInputFile(fnd::IFile* file, bool ownIFile);
	void setCliOutputMode(CliOutputMode type);
	void setVerifyMode(bool verify);

	const nx::ContentMetaBinary& getContentMetaBinary() const;

private:
	const std::string kModuleName = "CnmtProcess";

	fnd::IFile* mFile;
	bool mOwnIFile;
	CliOutputMode mCliOutputMode;
	bool mVerify;

	nx::ContentMetaBinary mCnmt;

	void displayCmnt();
};
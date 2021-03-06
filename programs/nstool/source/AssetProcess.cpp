#include <fnd/SimpleFile.h>
#include <fnd/Vec.h>
#include "AssetProcess.h"
#include "OffsetAdjustedIFile.h"


AssetProcess::AssetProcess() :
	mFile(nullptr),
	mOwnIFile(false),
	mCliOutputMode(_BIT(OUTPUT_BASIC)),
	mVerify(false)
{

}

AssetProcess::~AssetProcess()
{
	if (mOwnIFile)
	{
		delete mFile;
	}
}

void AssetProcess::process()
{
	if (mFile == nullptr)
	{
		throw fnd::Exception(kModuleName, "No file reader set.");
	}

	importHeader();
	if (_HAS_BIT(mCliOutputMode, OUTPUT_BASIC))
		displayHeader();
	processSections();
}

void AssetProcess::setInputFile(fnd::IFile* file, bool ownIFile)
{
	mFile = file;
	mOwnIFile = ownIFile;
}

void AssetProcess::setCliOutputMode(CliOutputMode type)
{
	mCliOutputMode = type;
}

void AssetProcess::setVerifyMode(bool verify)
{
	mVerify = verify;
}

void AssetProcess::setListFs(bool list)
{
	mRomfs.setListFs(list);
}

void AssetProcess::setIconExtractPath(const std::string& path)
{
	mIconExtractPath = path;
}

void AssetProcess::setNacpExtractPath(const std::string& path)
{
	mNacpExtractPath = path;
}

void AssetProcess::setRomfsExtractPath(const std::string& path)
{
	mRomfs.setExtractPath(path);
}


void AssetProcess::importHeader()
{
	fnd::Vec<byte_t> scratch;
	if (mFile->size() < sizeof(nx::sAssetHeader))
	{
		throw fnd::Exception(kModuleName, "Corrupt ASET: file too small");
	}

	scratch.alloc(sizeof(nx::sAssetHeader));
	mFile->read(scratch.data(), 0, scratch.size());

	mHdr.fromBytes(scratch.data(), scratch.size());
}

void AssetProcess::processSections()
{
	if (mHdr.getIconInfo().size > 0 && mIconExtractPath.isSet)
	{
		if ((mHdr.getIconInfo().size + mHdr.getIconInfo().offset) > mFile->size()) 
			throw fnd::Exception(kModuleName, "ASET geometry for icon beyond file size");

		fnd::SimpleFile outfile(mIconExtractPath.var, fnd::SimpleFile::Create);
		fnd::Vec<byte_t> cache;

		cache.alloc(mHdr.getIconInfo().size);
		mFile->read(cache.data(), mHdr.getIconInfo().offset, cache.size());
		outfile.write(cache.data(), cache.size());
		outfile.close();
	}

	if (mHdr.getNacpInfo().size > 0)
	{
		if ((mHdr.getNacpInfo().size + mHdr.getNacpInfo().offset) > mFile->size()) 
			throw fnd::Exception(kModuleName, "ASET geometry for nacp beyond file size");

		if (mNacpExtractPath.isSet)
		{
			fnd::SimpleFile outfile(mNacpExtractPath.var, fnd::SimpleFile::Create);
			fnd::Vec<byte_t> cache;

			cache.alloc(mHdr.getNacpInfo().size);
			mFile->read(cache.data(), mHdr.getNacpInfo().offset, cache.size());
			outfile.write(cache.data(), cache.size());
			outfile.close();
		}
		
		mNacp.setInputFile(new OffsetAdjustedIFile(mFile, false, mHdr.getNacpInfo().offset, mHdr.getNacpInfo().size), true);
		mNacp.setCliOutputMode(mCliOutputMode);
		mNacp.setVerifyMode(mVerify);

		mNacp.process();
	}

	if (mHdr.getRomfsInfo().size > 0)
	{
		if ((mHdr.getRomfsInfo().size + mHdr.getRomfsInfo().offset) > mFile->size()) 
			throw fnd::Exception(kModuleName, "ASET geometry for romfs beyond file size");

		mRomfs.setInputFile(new OffsetAdjustedIFile(mFile, false, mHdr.getRomfsInfo().offset, mHdr.getRomfsInfo().size), true);
		mRomfs.setCliOutputMode(mCliOutputMode);
		mRomfs.setVerifyMode(mVerify);

		mRomfs.process();
	}
}

void AssetProcess::displayHeader()
{
	if (_HAS_BIT(mCliOutputMode, OUTPUT_LAYOUT))
	{
		printf("[ASET Header]\n");
		printf("  Icon:\n");
		printf("    Offset:       0x%" PRIx64 "\n", mHdr.getIconInfo().offset);
		printf("    Size:         0x%" PRIx64 "\n", mHdr.getIconInfo().size);
		printf("  NACP:\n");
		printf("    Offset:       0x%" PRIx64 "\n", mHdr.getNacpInfo().offset);
		printf("    Size:         0x%" PRIx64 "\n", mHdr.getNacpInfo().size);
		printf("  RomFS:\n");
		printf("    Offset:       0x%" PRIx64 "\n", mHdr.getRomfsInfo().offset);
		printf("    Size:         0x%" PRIx64 "\n", mHdr.getRomfsInfo().size);
	}	
}
		

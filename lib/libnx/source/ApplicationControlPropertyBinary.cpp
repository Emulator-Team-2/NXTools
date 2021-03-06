#include <nx/ApplicationControlPropertyBinary.h>

nx::ApplicationControlPropertyBinary::ApplicationControlPropertyBinary()
{
	clear();
}

nx::ApplicationControlPropertyBinary::ApplicationControlPropertyBinary(const ApplicationControlPropertyBinary& other)
{
	*this = other;
}

void nx::ApplicationControlPropertyBinary::operator=(const ApplicationControlPropertyBinary& other)
{
	clear();
	mTitle = other.mTitle;
	mIsbn = other.mIsbn;
	mStartupUserAccount = other.mStartupUserAccount;
	mTouchScreenUsageMode = other.mTouchScreenUsageMode;
	mAocRegistrationType = other.mAocRegistrationType;
	mAttributeFlag = other.mAttributeFlag;
	mParentalControlFlag = other.mParentalControlFlag;
	mScreenshotMode = other.mScreenshotMode;
	mVideoCaptureMode = other.mVideoCaptureMode;
	mDataLossConfirmation = other.mDataLossConfirmation;
	mPlayLogPolicy = other.mPlayLogPolicy;
	mPresenceGroupId = other.mPresenceGroupId;
	mRatingAge = other.mRatingAge;
	mDisplayVersion = other.mDisplayVersion;
	mAocBaseId = other.mAocBaseId;
	mSaveDatawOwnerId = other.mSaveDatawOwnerId;
	mUserAccountSaveDataSize = other.mUserAccountSaveDataSize;
	mDeviceSaveDataSize = other.mDeviceSaveDataSize;
	mBcatDeliveryCacheStorageSize = other.mBcatDeliveryCacheStorageSize;
	mApplicationErrorCodeCategory = other.mApplicationErrorCodeCategory;
	mLocalCommunicationId = other.mLocalCommunicationId;
	mLogoType = other.mLogoType;
	mLogoHandling = other.mLogoHandling;
	mRuntimeAocInstallMode = other.mRuntimeAocInstallMode;
	mCrashReportMode = other.mCrashReportMode;
	mHdcp = other.mHdcp;
	mSeedForPsuedoDeviceId = other.mSeedForPsuedoDeviceId;
	mBcatPassphase = other.mBcatPassphase;
	mUserAccountSaveDataMax = other.mUserAccountSaveDataMax;
	mDeviceSaveDataMax = other.mDeviceSaveDataMax;
	mTemporaryStorageSize = other.mTemporaryStorageSize;
	mCacheStorageSize = other.mCacheStorageSize;
	mCacheStorageDataAndJournalSizeMax = other.mCacheStorageDataAndJournalSizeMax;
	mCacheStorageIndex = other.mCacheStorageIndex;
	mPlayLogQueryableApplicationId = other.mPlayLogQueryableApplicationId;
	mPlayLogQueryCapability = other.mPlayLogQueryCapability;
	mRepairFlag = other.mRepairFlag;
	mProgramIndex = other.mProgramIndex;
}

bool nx::ApplicationControlPropertyBinary::operator==(const ApplicationControlPropertyBinary& other) const
{
	return (mTitle == other.mTitle) \
		&& (mIsbn == other.mIsbn) \
		&& (mStartupUserAccount == other.mStartupUserAccount) \
		&& (mTouchScreenUsageMode == other.mTouchScreenUsageMode) \
		&& (mAocRegistrationType == other.mAocRegistrationType) \
		&& (mAttributeFlag == other.mAttributeFlag) \
		&& (mParentalControlFlag == other.mParentalControlFlag) \
		&& (mScreenshotMode == other.mScreenshotMode) \
		&& (mVideoCaptureMode == other.mVideoCaptureMode) \
		&& (mDataLossConfirmation == other.mDataLossConfirmation) \
		&& (mPlayLogPolicy == other.mPlayLogPolicy) \
		&& (mPresenceGroupId == other.mPresenceGroupId) \
		&& (mRatingAge == other.mRatingAge) \
		&& (mDisplayVersion == other.mDisplayVersion) \
		&& (mAocBaseId == other.mAocBaseId) \
		&& (mSaveDatawOwnerId == other.mSaveDatawOwnerId) \
		&& (mUserAccountSaveDataSize == other.mUserAccountSaveDataSize) \
		&& (mDeviceSaveDataSize == other.mDeviceSaveDataSize) \
		&& (mBcatDeliveryCacheStorageSize == other.mBcatDeliveryCacheStorageSize) \
		&& (mApplicationErrorCodeCategory == other.mApplicationErrorCodeCategory) \
		&& (mLocalCommunicationId == other.mLocalCommunicationId) \
		&& (mLogoType == other.mLogoType) \
		&& (mLogoHandling == other.mLogoHandling) \
		&& (mRuntimeAocInstallMode == other.mRuntimeAocInstallMode) \
		&& (mCrashReportMode == other.mCrashReportMode) \
		&& (mHdcp == other.mHdcp) \
		&& (mSeedForPsuedoDeviceId == other.mSeedForPsuedoDeviceId) \
		&& (mBcatPassphase == other.mBcatPassphase) \
		&& (mUserAccountSaveDataMax == other.mUserAccountSaveDataMax) \
		&& (mDeviceSaveDataMax == other.mDeviceSaveDataMax) \
		&& (mTemporaryStorageSize == other.mTemporaryStorageSize) \
		&& (mCacheStorageSize == other.mCacheStorageSize) \
		&& (mCacheStorageDataAndJournalSizeMax == other.mCacheStorageDataAndJournalSizeMax) \
		&& (mCacheStorageIndex == other.mCacheStorageIndex) \
		&& (mPlayLogQueryableApplicationId == other.mPlayLogQueryableApplicationId) \
		&& (mPlayLogQueryCapability == other.mPlayLogQueryCapability) \
		&& (mRepairFlag == other.mRepairFlag) \
		&& (mProgramIndex == other.mProgramIndex);
}

bool nx::ApplicationControlPropertyBinary::operator!=(const ApplicationControlPropertyBinary& other) const
{
	return !(*this == other);
}

void nx::ApplicationControlPropertyBinary::toBytes()
{
	mRawBinary.alloc(sizeof(nx::sApplicationControlProperty));

	sApplicationControlProperty* data = (sApplicationControlProperty*)mRawBinary.data();

	// strings
	uint32_t supported_langs = 0;
	for (size_t i = 0; i < mTitle.size(); i++)
	{
		supported_langs = _BIT(mTitle[i].language);
		strncpy(data->title[mTitle[i].language].name, mTitle[i].name.c_str(), nacp::kNameLength);
		strncpy(data->title[mTitle[i].language].publisher, mTitle[i].publisher.c_str(), nacp::kPublisherLength);
	}
	data->supported_language_flag = supported_langs;

	strncpy(data->isbn, mIsbn.c_str(), nacp::kIsbnLength);
	strncpy(data->display_version, mDisplayVersion.c_str(), nacp::kDisplayVersionLength);
	strncpy(data->application_error_code_category, mApplicationErrorCodeCategory.c_str(), nacp::kApplicationErrorCodeCategoryLength);
	strncpy(data->bcat_passphrase, mBcatPassphase.c_str(), nacp::kBcatPassphraseLength);

	// enum type casts
	data->startup_user_account = mStartupUserAccount;
	data->touch_screen_usage = mTouchScreenUsageMode;
	data->add_on_content_registration_type = mAocRegistrationType;
	data->attribute_flag = mAttributeFlag;
	data->parental_control_flag = mParentalControlFlag;
	data->screenshot = mScreenshotMode;
	data->video_capture = mVideoCaptureMode;
	data->data_loss_confirmation = mDataLossConfirmation;
	data->play_log_policy = mPlayLogPolicy;
	data->logo_type = mLogoType;
	data->logo_handling = mLogoHandling;
	data->runtime_add_on_content_install = mRuntimeAocInstallMode;
	data->crash_report = mCrashReportMode;
	data->hdcp = mHdcp;
	data->play_log_query_capability = mPlayLogQueryCapability;
	data->repair_flag = mRepairFlag;

	// misc params
	data->presence_group_id = mPresenceGroupId;
	memset(data->rating_age, nacp::kUnusedAgeRating, nacp::kRatingAgeCount); // clear ratings
	for (size_t i = 0; i < mRatingAge.size(); i++)
	{
		data->rating_age[mRatingAge[i].organisation] = mRatingAge[i].age;
	}
	data->add_on_content_base_id = mAocBaseId;
	data->save_data_owner_id = mSaveDatawOwnerId;
	for (size_t i = 0; i < mLocalCommunicationId.size() && i < nacp::kLocalCommunicationIdCount; i++)
	{
		data->local_communication_id[i] = mLocalCommunicationId[i];
	}
	data->seed_for_pseudo_device_id = mSeedForPsuedoDeviceId;
	for (size_t i = 0; i < mPlayLogQueryableApplicationId.size() && i < nacp::kPlayLogQueryableApplicationIdCount; i++)
	{
		data->play_log_queryable_application_id[i] = mPlayLogQueryableApplicationId[i];
	}
	data->cache_storage_index = mCacheStorageIndex;
	data->program_index = mProgramIndex;

	// sizes
	data->user_account_save_data_size = mUserAccountSaveDataSize.size;
	data->user_account_save_data_journal_size = mUserAccountSaveDataSize.journal_size;
	data->device_save_data_size = mDeviceSaveDataSize.size;
	data->device_save_data_journal_size = mDeviceSaveDataSize.journal_size;
	data->bcat_delivery_cache_storage_size = mBcatDeliveryCacheStorageSize;
	data->user_account_save_data_size_max = mUserAccountSaveDataMax.size;
	data->user_account_save_data_journal_size_max = mUserAccountSaveDataMax.journal_size;
	data->device_save_data_size_max = mDeviceSaveDataMax.size;
	data->device_save_data_journal_size_max = mDeviceSaveDataMax.journal_size;
	data->temporary_storage_size = 	mTemporaryStorageSize;
	data->cache_storage_size = mCacheStorageSize.size;
	data->cache_storage_journal_size = mCacheStorageSize.journal_size;
	data->cache_storage_data_and_journal_size_max = mCacheStorageDataAndJournalSizeMax;
}

void nx::ApplicationControlPropertyBinary::fromBytes(const byte_t* bytes, size_t len)
{
	if (len < sizeof(nx::sApplicationControlProperty))
	{
		throw fnd::Exception(kModuleName, "NACP too small");
	}

	clear();

	mRawBinary.alloc(sizeof(nx::sApplicationControlProperty));
	memcpy(mRawBinary.data(), bytes, mRawBinary.size());

	const sApplicationControlProperty* data = (const sApplicationControlProperty*)mRawBinary.data();

	// strings
	for (size_t i = 0; i < nacp::kMaxLanguageCount; i++)
	{
		if (_HAS_BIT(data->supported_language_flag.get(), i))
		{
			mTitle.addElement({(nacp::Language)i, std::string(data->title[i].name, nacp::kNameLength), std::string(data->title[i].publisher, nacp::kPublisherLength)});
		}
	}
	if (data->isbn[0] != 0)
		mIsbn = std::string(data->isbn, nacp::kIsbnLength);
	if (data->display_version[0] != 0)
		mDisplayVersion = std::string(data->display_version, nacp::kDisplayVersionLength);
	if (data->application_error_code_category[0] != 0)
		mApplicationErrorCodeCategory = std::string(data->application_error_code_category, nacp::kApplicationErrorCodeCategoryLength);
	if (data->bcat_passphrase[0] != 0)
		mBcatPassphase = std::string(data->bcat_passphrase, nacp::kBcatPassphraseLength);

	// enum type casts
	mStartupUserAccount = (nacp::StartupUserAccount)data->startup_user_account;
	mTouchScreenUsageMode = (nacp::TouchScreenUsageMode)data->touch_screen_usage;
	mAocRegistrationType = (nacp::AocRegistrationType)data->add_on_content_registration_type;
	mAttributeFlag = (nacp::AttributeFlag)data->attribute_flag.get();
	mParentalControlFlag = (nacp::ParentalControlFlag)data->parental_control_flag.get();
	mScreenshotMode = (nacp::ScreenshotMode)data->screenshot;
	mVideoCaptureMode = (nacp::VideoCaptureMode)data->video_capture;
	mDataLossConfirmation = (nacp::DataLossConfirmation)data->data_loss_confirmation;
	mPlayLogPolicy = (nacp::PlayLogPolicy)data->play_log_policy;
	mLogoType = (nacp::LogoType)data->logo_type;
	mLogoHandling = (nacp::LogoHandling)data->logo_handling;
	mRuntimeAocInstallMode = (nacp::RuntimeAocInstallMode)data->runtime_add_on_content_install;
	mCrashReportMode = (nacp::CrashReportMode)data->crash_report;
	mHdcp = (nacp::Hdcp)data->hdcp;
	mPlayLogQueryCapability = (nacp::PlayLogQueryCapability)data->play_log_query_capability;
	mRepairFlag = (nacp::RepairFlag)data->repair_flag;

	// misc params
	mPresenceGroupId = data->presence_group_id.get();
	for (size_t i = 0; i < nacp::kRatingAgeCount; i++)
	{
		if (data->rating_age[i] != nacp::kUnusedAgeRating)
			mRatingAge.addElement({(nacp::Organisation)i, data->rating_age[i]});
	}
	mAocBaseId = data->add_on_content_base_id.get();
	mSaveDatawOwnerId = data->save_data_owner_id.get();
	for (size_t i = 0; i < nacp::kLocalCommunicationIdCount; i++)
	{
		if (data->local_communication_id[i].get() != 0)
			mLocalCommunicationId.addElement(data->local_communication_id[i].get());
	}
	mSeedForPsuedoDeviceId = data->seed_for_pseudo_device_id.get();
	for (size_t i = 0; i < nacp::kPlayLogQueryableApplicationIdCount; i++)
	{
		if (data->play_log_queryable_application_id[i].get() != 0)
			mPlayLogQueryableApplicationId.addElement(data->play_log_queryable_application_id[i].get());
	}
	mCacheStorageIndex = data->cache_storage_index.get();
	mProgramIndex = data->program_index;

	// sizes
	mUserAccountSaveDataSize.size = (int64_t)data->user_account_save_data_size.get();
	mUserAccountSaveDataSize.journal_size = (int64_t)data->user_account_save_data_journal_size.get();
	mDeviceSaveDataSize.size = (int64_t)data->device_save_data_size.get();
	mDeviceSaveDataSize.journal_size = (int64_t)data->device_save_data_journal_size.get();
	mBcatDeliveryCacheStorageSize = (int64_t)data->bcat_delivery_cache_storage_size.get();
	mUserAccountSaveDataMax.size = (int64_t)data->user_account_save_data_size_max.get();
	mUserAccountSaveDataMax.journal_size = (int64_t)data->user_account_save_data_journal_size_max.get();
	mDeviceSaveDataMax.size = (int64_t)data->device_save_data_size_max.get();
	mDeviceSaveDataMax.journal_size = (int64_t)data->device_save_data_journal_size_max.get();
	mTemporaryStorageSize = (int64_t)data->temporary_storage_size.get();
	mCacheStorageSize.size = (int64_t)data->cache_storage_size.get();
	mCacheStorageSize.journal_size = (int64_t)data->cache_storage_journal_size.get();
	mCacheStorageDataAndJournalSizeMax = (int64_t)data->cache_storage_data_and_journal_size_max.get();
}

const fnd::Vec<byte_t>& nx::ApplicationControlPropertyBinary::getBytes() const
{
	return mRawBinary;
}

void nx::ApplicationControlPropertyBinary::clear()
{
	mRawBinary.clear();
	mTitle.clear();
	mIsbn.clear();
	mStartupUserAccount = nacp::USER_None;
	mTouchScreenUsageMode = nacp::TOUCH_None;
	mAocRegistrationType = nacp::AOC_AllOnLaunch;
	mAttributeFlag = nacp::ATTR_None;
	mParentalControlFlag = nacp::PC_None;
	mScreenshotMode = nacp::SCRN_Allow;
	mVideoCaptureMode = nacp::VCAP_Disable;
	mDataLossConfirmation = nacp::DLOSS_None;
	mPlayLogPolicy = nacp::PLP_All;
	mPresenceGroupId = 0;
	mRatingAge.clear();
	mDisplayVersion.clear();
	mAocBaseId = 0;
	mSaveDatawOwnerId = 0;
	mUserAccountSaveDataSize = {0, 0};
	mDeviceSaveDataSize = {0, 0};
	mBcatDeliveryCacheStorageSize = 0;
	mApplicationErrorCodeCategory.clear();
	mLocalCommunicationId.clear();
	mLogoType = nacp::LOGO_Nintendo;
	mLogoHandling = nacp::LHND_Auto;
	mRuntimeAocInstallMode = nacp::RTAOC_Deny;
	mCrashReportMode = nacp::CREP_Deny;
	mHdcp = nacp::HDCP_None;
	mSeedForPsuedoDeviceId = 0;
	mBcatPassphase.clear();
	mUserAccountSaveDataMax;
	mDeviceSaveDataMax = {0, 0};
	mTemporaryStorageSize = 0;
	mCacheStorageSize = {0, 0};
	mCacheStorageDataAndJournalSizeMax = 0;
	mCacheStorageIndex = 0;
	mPlayLogQueryableApplicationId.clear();
	mPlayLogQueryCapability = nacp::PLQC_None;
	mRepairFlag = nacp::REPF_None;
	mProgramIndex = 0;
}

const fnd::List<nx::ApplicationControlPropertyBinary::sTitle>& nx::ApplicationControlPropertyBinary::getTitle() const
{
	return mTitle;
}

void nx::ApplicationControlPropertyBinary::setTitle(const fnd::List<sTitle>& title)
{
	mTitle = title;
}

const std::string& nx::ApplicationControlPropertyBinary::getIsbn() const
{
	return mIsbn;
}

void nx::ApplicationControlPropertyBinary::setIsbn(const std::string& isbn)
{
	mIsbn = isbn;
}

nx::nacp::StartupUserAccount nx::ApplicationControlPropertyBinary::getStartupUserAccount() const
{
	return mStartupUserAccount;
}

void nx::ApplicationControlPropertyBinary::setStartupUserAccount(nacp::StartupUserAccount var)
{
	mStartupUserAccount = var;
}

nx::nacp::TouchScreenUsageMode nx::ApplicationControlPropertyBinary::getTouchScreenUsageMode() const
{
	return mTouchScreenUsageMode;
}

void nx::ApplicationControlPropertyBinary::setTouchScreenUsageMode(nacp::TouchScreenUsageMode var)
{
	mTouchScreenUsageMode = var;
}

nx::nacp::AocRegistrationType nx::ApplicationControlPropertyBinary::getAocRegistrationType() const
{
	return mAocRegistrationType;
}

void nx::ApplicationControlPropertyBinary::setAocRegistrationType(nacp::AocRegistrationType var)
{
	mAocRegistrationType = var;
}

nx::nacp::AttributeFlag nx::ApplicationControlPropertyBinary::getAttributeFlag() const
{
	return mAttributeFlag;
}

void nx::ApplicationControlPropertyBinary::setAttributeFlag(nacp::AttributeFlag var)
{
	mAttributeFlag = var;
}

nx::nacp::ParentalControlFlag nx::ApplicationControlPropertyBinary::getParentalControlFlag() const
{
	return mParentalControlFlag;
}

void nx::ApplicationControlPropertyBinary::setParentalControlFlag(nacp::ParentalControlFlag var)
{
	mParentalControlFlag = var;
}

nx::nacp::ScreenshotMode nx::ApplicationControlPropertyBinary::getScreenshotMode() const
{
	return mScreenshotMode;
}

void nx::ApplicationControlPropertyBinary::setScreenshotMode(nacp::ScreenshotMode var)
{
	mScreenshotMode = var;
}

nx::nacp::VideoCaptureMode nx::ApplicationControlPropertyBinary::getVideoCaptureMode() const
{
	return mVideoCaptureMode;
}

void nx::ApplicationControlPropertyBinary::setVideoCaptureMode(nacp::VideoCaptureMode var)
{
	mVideoCaptureMode = var;
}

nx::nacp::DataLossConfirmation nx::ApplicationControlPropertyBinary::getDataLossConfirmation() const
{
	return mDataLossConfirmation;
}

void nx::ApplicationControlPropertyBinary::setDataLossConfirmation(nacp::DataLossConfirmation var)
{
	mDataLossConfirmation = var;
}

nx::nacp::PlayLogPolicy nx::ApplicationControlPropertyBinary::getPlayLogPolicy() const
{
	return mPlayLogPolicy;
}

void nx::ApplicationControlPropertyBinary::setPlayLogPolicy(nacp::PlayLogPolicy var)
{
	mPlayLogPolicy = var;
}

uint64_t nx::ApplicationControlPropertyBinary::getPresenceGroupId() const
{
	return mPresenceGroupId;
}

void nx::ApplicationControlPropertyBinary::setPresenceGroupId(uint64_t var)
{
	mPresenceGroupId = var;
}

const fnd::List<nx::ApplicationControlPropertyBinary::sRating>& nx::ApplicationControlPropertyBinary::getRatingAge() const
{
	return mRatingAge;
}

void nx::ApplicationControlPropertyBinary::setRatingAge(const fnd::List<sRating>& var)
{
	mRatingAge = var;
}

const std::string& nx::ApplicationControlPropertyBinary::getDisplayVersion() const
{
	return mDisplayVersion;
}

void nx::ApplicationControlPropertyBinary::setDisplayVersion(const std::string& var)
{
	mDisplayVersion = var;
}

uint64_t nx::ApplicationControlPropertyBinary::getAocBaseId() const
{
	return mAocBaseId;
}

void nx::ApplicationControlPropertyBinary::setAocBaseId(uint64_t var)
{
	mAocBaseId = var;
}

uint64_t nx::ApplicationControlPropertyBinary::getSaveDatawOwnerId() const
{
	return mSaveDatawOwnerId;
}

void nx::ApplicationControlPropertyBinary::setSaveDatawOwnerId(uint64_t var)
{
	mSaveDatawOwnerId = var;
}

const nx::ApplicationControlPropertyBinary::sStorageSize& nx::ApplicationControlPropertyBinary::getUserAccountSaveDataSize() const
{
	return mUserAccountSaveDataSize;
}

void nx::ApplicationControlPropertyBinary::setUserAccountSaveDataSize(const sStorageSize& var)
{
	mUserAccountSaveDataSize = var;
}

const nx::ApplicationControlPropertyBinary::sStorageSize& nx::ApplicationControlPropertyBinary::getDeviceSaveDataSize() const
{
	return mDeviceSaveDataSize;
}

void nx::ApplicationControlPropertyBinary::setDeviceSaveDataSize(const sStorageSize& var)
{
	mDeviceSaveDataSize = var;
}

int64_t nx::ApplicationControlPropertyBinary::getBcatDeliveryCacheStorageSize() const
{
	return mBcatDeliveryCacheStorageSize;
}

void nx::ApplicationControlPropertyBinary::setBcatDeliveryCacheStorageSize(int64_t var)
{
	mBcatDeliveryCacheStorageSize = var;
}

const std::string& nx::ApplicationControlPropertyBinary::getApplicationErrorCodeCategory() const
{
	return mApplicationErrorCodeCategory;
}

void nx::ApplicationControlPropertyBinary::setApplicationErrorCodeCategory(const std::string& var)
{
	mApplicationErrorCodeCategory = var;
}

const fnd::List<uint64_t>& nx::ApplicationControlPropertyBinary::getLocalCommunicationId() const
{
	return mLocalCommunicationId;
}

void nx::ApplicationControlPropertyBinary::setLocalCommunicationId(const fnd::List<uint64_t>& var)
{
	mLocalCommunicationId = var;
}

nx::nacp::LogoType nx::ApplicationControlPropertyBinary::getLogoType() const
{
	return mLogoType;
}

void nx::ApplicationControlPropertyBinary::setLogoType(nacp::LogoType var)
{
	mLogoType = var;
}

nx::nacp::LogoHandling nx::ApplicationControlPropertyBinary::getLogoHandling() const
{
	return mLogoHandling;
}

void nx::ApplicationControlPropertyBinary::setLogoHandling(nacp::LogoHandling var)
{
	mLogoHandling = var;
}

nx::nacp::RuntimeAocInstallMode nx::ApplicationControlPropertyBinary::getRuntimeAocInstallMode() const
{
	return mRuntimeAocInstallMode;
}

void nx::ApplicationControlPropertyBinary::setRuntimeAocInstallMode(nacp::RuntimeAocInstallMode var)
{
	mRuntimeAocInstallMode = var;
}

nx::nacp::CrashReportMode nx::ApplicationControlPropertyBinary::getCrashReportMode() const
{
	return mCrashReportMode;
}

void nx::ApplicationControlPropertyBinary::setCrashReportMode(nacp::CrashReportMode var)
{
	mCrashReportMode = var;
}

nx::nacp::Hdcp nx::ApplicationControlPropertyBinary::getHdcp() const
{
	return mHdcp;
}

void nx::ApplicationControlPropertyBinary::setHdcp(nacp::Hdcp var)
{
	mHdcp = var;
}

uint64_t nx::ApplicationControlPropertyBinary::getSeedForPsuedoDeviceId() const
{
	return mSeedForPsuedoDeviceId;
}

void nx::ApplicationControlPropertyBinary::setSeedForPsuedoDeviceId(uint64_t var)
{
	mSeedForPsuedoDeviceId = var;
}

const std::string& nx::ApplicationControlPropertyBinary::getBcatPassphase() const
{
	return mBcatPassphase;
}

void nx::ApplicationControlPropertyBinary::setBcatPassphase(const std::string& var)
{
	mBcatPassphase = var;
}

const nx::ApplicationControlPropertyBinary::sStorageSize& nx::ApplicationControlPropertyBinary::getUserAccountSaveDataMax() const
{
	return mUserAccountSaveDataMax;
}

void nx::ApplicationControlPropertyBinary::setUserAccountSaveDataMax(const sStorageSize& var)
{
	mUserAccountSaveDataMax = var;
}

const nx::ApplicationControlPropertyBinary::sStorageSize& nx::ApplicationControlPropertyBinary::getDeviceSaveDataMax() const
{
	return mDeviceSaveDataMax;
}

void nx::ApplicationControlPropertyBinary::setDeviceSaveDataMax(const sStorageSize& var)
{
	mDeviceSaveDataMax = var;
}

int64_t nx::ApplicationControlPropertyBinary::getTemporaryStorageSize() const
{
	return mTemporaryStorageSize;
}

void nx::ApplicationControlPropertyBinary::setTemporaryStorageSize(int64_t var)
{
	mTemporaryStorageSize = var;
}

const nx::ApplicationControlPropertyBinary::sStorageSize& nx::ApplicationControlPropertyBinary::getCacheStorageSize() const
{
	return mCacheStorageSize;
}

void nx::ApplicationControlPropertyBinary::setCacheStorageSize(const sStorageSize& var)
{
	mCacheStorageSize = var;
}

int64_t nx::ApplicationControlPropertyBinary::getCacheStorageDataAndJournalSizeMax() const
{
	return mCacheStorageDataAndJournalSizeMax;
}

void nx::ApplicationControlPropertyBinary::setCacheStorageDataAndJournalSizeMax(int64_t var)
{
	mCacheStorageDataAndJournalSizeMax = var;
}

uint16_t nx::ApplicationControlPropertyBinary::getCacheStorageIndex() const
{
	return mCacheStorageIndex;
}

void nx::ApplicationControlPropertyBinary::setCacheStorageIndex(uint16_t var)
{
	mCacheStorageIndex = var;
}

const fnd::List<uint64_t>& nx::ApplicationControlPropertyBinary::getPlayLogQueryableApplicationId() const
{
	return mPlayLogQueryableApplicationId;
}

void nx::ApplicationControlPropertyBinary::setPlayLogQueryableApplicationId(const fnd::List<uint64_t>& var)
{
	mPlayLogQueryableApplicationId = var;
}

nx::nacp::PlayLogQueryCapability nx::ApplicationControlPropertyBinary::getPlayLogQueryCapability() const
{
	return mPlayLogQueryCapability;
}

void nx::ApplicationControlPropertyBinary::setPlayLogQueryCapability(nacp::PlayLogQueryCapability var)
{
	mPlayLogQueryCapability = var;
}

nx::nacp::RepairFlag nx::ApplicationControlPropertyBinary::getRepairFlag() const
{
	return mRepairFlag;
}

void nx::ApplicationControlPropertyBinary::setRepairFlag(nacp::RepairFlag var)
{
	mRepairFlag = var;
}

byte_t nx::ApplicationControlPropertyBinary::getProgramIndex() const
{
	return mProgramIndex;
}

void nx::ApplicationControlPropertyBinary::setProgramIndex(byte_t var)
{
	mProgramIndex = var;
}
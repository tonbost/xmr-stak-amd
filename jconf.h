#pragma once
#include <stdlib.h>
#include <string>

class jconf
{
public:
	static jconf* inst()
	{
		if (oInst == nullptr) oInst = new jconf;
		return oInst;
	};

	bool parse_config(const char* sFilename);

	struct thd_cfg {
		size_t index;
		size_t intensity;
		size_t w_size;
		long long cpu_aff;
	};

	size_t GetThreadCount();
	bool GetThreadConfig(size_t id, thd_cfg &cfg);

	size_t GetPlatformIdx();

	const char* GetPoolAddress();
	const char* GetPoolPwd();
	const char* GetWalletAddress();

	uint64_t GetVerboseLevel();
	uint64_t GetAutohashTime();

	uint64_t GetCallTimeout();
	uint64_t GetNetRetry();

	uint16_t GetHttpdPort();

	bool PreferIpv4();

	inline bool HaveHardwareAes() { return bHaveAes; }

private:
	jconf();
	static jconf* oInst;

	bool check_cpu_features();
	struct opaque_private;
	opaque_private* prv;

	bool bHaveAes;
};
